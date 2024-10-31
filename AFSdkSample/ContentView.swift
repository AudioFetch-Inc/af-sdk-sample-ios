//
//  ContentView.swift
//  AFSdkSample
//
//  Example SwiftUI for audiofetch sdk sample.
//

import SwiftUI
import Flutter

struct ContentView: View {
  @Environment(AudioFetch.self) var audiofetch

    var body: some View {
        VStack {
            Image(systemName: "globe")
                .imageScale(.large)
                .foregroundStyle(.tint)
            Text("Hello, world from AudioFetch!")

            // Scrolling list of all channels discovered
            List {
                ForEach( audiofetch.sortedKeys, id: \.self ) { key in

                    // The key in the channels list is the "UI Channel Number", which
                    // is the channel number shown in the AudioFetch listening app.
                    Button( action: {
                        var channel: AFChannel = audiofetch.channels[key]!

                        // The channel structure contains the ip address of the box
                        // for that channel, as well as the box channel number
                        // For reference, the conversion is:
                        // uiChNum = boxBaseChannel + boxChannel + 1
                        // The boxBaseChannel is controlled by the box letter in the
                        // doghouse configuration.
                        audiofetch.audio.startAudio(on: channel.ips[0], channel: UInt(channel.chNum)! )
                        audiofetch.isPlaying = true
                        audiofetch.lastChannel = key

                    }) {
                        Text("Channel \(key)")
                    }
                    //Text("Channel: \(channel!.chNum)")
                }
            }

            // Bottom Play/Pause control.
            Button(action: {
                if (audiofetch.isPlaying == true) {
                    audiofetch.audio.muteAudio()
                    audiofetch.isPlaying = false
                }
                else {
                    //var channel: AFChannel = audiofetch.channels[audiofetch.lastChannel]!
                    //audiofetch.audio.startAudio(on: channel.ips[0], channel: UInt(channel.chNum)! )
                    audiofetch.audio.unMuteAudio()
                    audiofetch.isPlaying = true
                }
               }) {
                   audiofetch.isPlaying ? Text("Pause") : Text("Play")
               }
        }
        .padding()
    }
}

#Preview {
    ContentView()
}



