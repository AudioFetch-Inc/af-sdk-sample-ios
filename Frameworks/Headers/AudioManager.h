//
//  AudioManager.h
//  audiofetch
//
//  Copyright © 2016 AudioFetch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "Apb.h"

@interface AudioManager : NSObject <AVAudioPlayerDelegate>

/*====================================
// MARK: SINGLETON
//===================================*/


/**
 Singleton

 @return AudioManager
 */
@property (class, readonly) AudioManager* _Nonnull shared;

/**
Returns device Ip address
*/
@property(readonly, null_unspecified) NSString* deviceIpAddress;

/**
Returns device mac address
*/
@property(readonly, null_unspecified) NSString* deviceMacAddress;

/*====================================
// MARK: PUBLIC METHODS
//===================================*/


/**
 Starts audio service
 */
- (void) startService;

/**
 Stops audio service
 */
- (void) stopService;

/**
 Starts only discovery service
 
 @return YES if successful, NO otherwise
 */
- (BOOL) startDiscovery;

/**
 Stops discovery service
 */
- (void) stopDiscovery;

/**
 Start the audio

 @return YES if successful, NO otherwise
 */
- (BOOL)startAudio;

/**
 Start the audio on specified channel

 @param channel The channel, on which to start playing audio.
 @return YES if successful, NO otherwise
 */
- (BOOL)startAudioOn:(NSUInteger) channel;

- (BOOL)startAudioOn:(NSString*) apb channel: (NSUInteger) channel;

- (BOOL)muteAudio;
- (BOOL)unMuteAudio;

/**
 Stops the audio
 */
- (void)stopAudio;

/**
 Deallocates the audio
 */
- (void)deallocAudio;

/**
 Play a demo track

 @param channel The demo channel
 */
- (void)playDemoTrack:(NSUInteger) channel;

/**
 Returns YES if the channel exists, NO otherwise

 @param channel The channel in question
 @return Returns YES if the channel exists, NO otherwise
 */
- (BOOL)hasChannel:(NSUInteger) channel;

/**
 Starts the audio check
 */
- (void)startAudioCheck;

/**
 Stops the audio check
 */
- (void)stopAudioCheck;

/**
 Audio check
 */
- (void)audioCheck;


/**
 Audio check timeout
 */
- (void)audioCheckTimeout;

// waio service logging interface
- (char*) memlog_get;
- (void) memlog_clear;

// json querry interface
- (NSString*) getApbsJson;
- (NSString*) getIpList;

// latench buffer size
- (void) setBufferMs: (NSUInteger) ms;

/*====================================
// MARK: PUBLIC PROPERTIES
//===================================*/

@property(readwrite) BOOL autoStartAudio;

/**
 Whether audio is playing, or not
 */
@property (readonly) BOOL isAudioPlaying;

/**
Whether Other audio is playing, or not
*/
@property (readonly) BOOL isOtherAudioPlaying;

/**
Whether audio is interrupted, or not
*/
@property (readwrite, nonatomic) BOOL isAudioInterrupted;

/**
 Indicates either discovery and/or audio service is started.
 This differs from isAudioPlaying, which monitors actual stream timeouts, this just tells us that the service is started.
 */
@property (readonly) BOOL isAudioServiceStarted;

/**
 Whether demo mode is enabled, or not
 */
@property(readwrite) BOOL demoModeEnabled;

/**
 Whether the audio session is being held, or not
 */
@property(readwrite) BOOL holdAudioSession;

/**
Whether headphones are in use, or not
*/
@property(readonly) BOOL headphonesInUse;

/**
 Whether the single APB is an express device
 */
@property(readonly) BOOL isExpressDevice;

/**
 What the volume level currently is set at (between 0 and 1)
 */
@property(readwrite) float volume;

@property(readonly, null_unspecified) float* floatBuffer;
@property(readonly) UInt32 floatBufferSize;

/**
 The currently selected channel
 */
@property(readwrite) NSUInteger currentChannel;

/**
 The apb that is currently being accessed or nil
 */
@property(readonly) Apb* _Nullable currentApb;

/**
 The list of discovered Apbs or nil
 */
@property(readonly) NSArray<Apb*>* _Nonnull allApbs;

/**
 Should be 75 for TV audio, 150 for music
 */
@property(readwrite) NSInteger bufferLatencyMilliseconds;

/**
 This is the last ace buffer setting, that was assigned.
 */
@property(readonly) int lastAceBufferSetting;

@end
