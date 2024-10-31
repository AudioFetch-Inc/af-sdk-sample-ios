//
//  AFSdkSampleApp.swift
//  AFSdkSample
//
//  Created by Morgan Jones on 9/12/24.
//

import SwiftUI


// Imports for AFDisco Lib
import Flutter
import FlutterPluginRegistrant


typealias UIViewControllerType = FlutterViewController





struct AFChannel: Codable {
    let chNum: String
    let chName: String
    let ips: [String]
}

@Observable
class AudioFetch {   // xxx rename this to AudioFetch or something
  // AFDisco
  let afDiscoEngine = FlutterEngine(name: "afDisco")
  var afDiscoChannel:FlutterMethodChannel?;

  // AFAudio
  var audio = AudioManager.shared

  // Discovered channels
  var channels : [String: AFChannel] = [:]
  var sortedKeys: Array<String> = []

  // Play/pause keep track
  var isPlaying: Bool = false
  var lastChannel: String = ""


  init() {
    // Start AFDisco
    afDiscoEngine.run()
    GeneratedPluginRegistrant.register(with: self.afDiscoEngine);

    // Start AFAudio Service
    audio.startService()

    // Initialize method channel for AFDisco
    self.setupMethodChannel()
  }

  func setupMethodChannel() {
   // setup a method channel
    let controller = FlutterViewController(engine: afDiscoEngine, nibName: nil, bundle: nil)
    afDiscoChannel = FlutterMethodChannel(name: "com.audiofetch/afDisco", binaryMessenger: controller.binaryMessenger)

    // set up method call handler to receive data from AFDisco
    afDiscoChannel!.setMethodCallHandler({
      [weak self] (call: FlutterMethodCall, result: FlutterResult) -> Void in

      guard call.method == "FromClientToHost" else  {
        result(FlutterMethodNotImplemented)
        return
      }

      // Handle incoming messages from AFDisco
      var dictonary:NSDictionary? = call.arguments as? NSDictionary
      if (call.arguments != nil) {
        var msg:String = "\(dictonary!["msg"] as! String)";
        var params:String = "\(dictonary!["params"] as! String)";
      
        if (msg == "afDiscoUp") {
          // This is sent when the disco plugin is ready
          print("afDisco plugin up!");

          // Tell AFDisco to start the discovery process
          self!.sendToAFDisco(msg: "startDisco", params:"");
        }
        else if (msg == "newDisco") {
          // This is sent on every new box discovery incrementally
          // These calls happen immediately and provide raw information
          // about each AudioFetch box.

          print("Received newDisco: \(params)");
        }
        else if (msg == "discoResults") {
          // This is the completed results after the discovery period
          // ie, 6 seconds and contains the completed list of all boxes discovered.

          print("Received discoResults: \(params)");

          // Parse incoming json into a dictionary of channels
          do {
              // Parse json into array of channels
              let decoder = JSONDecoder()
              let parsedData = try decoder.decode([String: AFChannel].self, from: Data(params.utf8))
              self!.channels = parsedData
              self!.sortedKeys = Array(self!.channels.keys)

              // This sorts the keys by user interface channel number
              self!.sortedKeys.sort(by: {Int($0)! < Int($1)!})
          }
          catch {
              print("json parse error");
          }
        }
      }
    })
  }


  func sendToAFDisco(msg: String, params: String) {

      if afDiscoChannel == nil {
          setupMethodChannel();
      }
      
    // Form a json object to send to AF Disco containing the message and parameters
    let jsonObject: NSMutableDictionary = NSMutableDictionary()
    jsonObject.setValue(msg, forKey: "msg")
    jsonObject.setValue(params, forKey: "params")
    var convertedString: String? = nil
    do {
        let data1 =  try JSONSerialization.data(withJSONObject: jsonObject, options: JSONSerialization.WritingOptions.prettyPrinted)
        convertedString = String(data: data1, encoding: String.Encoding.utf8)
    } 
    catch let myJSONError {
        print(myJSONError)
    }

    afDiscoChannel!.invokeMethod("fromHostToClient", arguments: convertedString)
  }

}

// The main app, place the
@main
struct AFSdkSampleApp: App {
    
    @State var audiofetch = AudioFetch()
    
    var body: some Scene {
        WindowGroup {
          ContentView()
            .environment(audiofetch)
        }
    }
}
