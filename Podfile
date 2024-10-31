source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/tyrone-sudeium/xiph-ios-podspecs.git'
platform :ios, '12.0'
use_frameworks!


project 'AFSdkSample.xcodeproj'

target 'AFSdkSample' do
    pod 'AFNetworking', '~> 4.0'
end

post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      config.build_settings["IPHONEOS_DEPLOYMENT_TARGET"] = "12.0"
    end
  end
end

