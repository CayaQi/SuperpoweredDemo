#ifndef Header_SuperpoweredExample
#define Header_SuperpoweredExample

#include <math.h>
#include <pthread.h>
#include <stdio.h>

#include "SuperpoweredExample.h"
#include <SuperpoweredAdvancedAudioPlayer.h>
#include <SuperpoweredFilter.h>
#include <SuperpoweredRoll.h>
#include <SuperpoweredFlanger.h>
#include <AndroidIO/SuperpoweredAndroidAudioIO.h>
#include <SuperpoweredRecorder.h>
#include <SuperpoweredReverb.h>
#include <SuperpoweredLimiter.h>
#include <jni.h>

#define HEADROOM_DECIBEL 3.0f
static const float headroom = powf(10.0f, -HEADROOM_DECIBEL * 0.025f);
static const int REVERB_NON = 0;
static const int REVERB_DRY = 1;
static const int REVERB_WET = 2;
static const int REVERB_WIDTH = 3;
static const int REVERB_MIX = 4;
static const int REVERB_ROOMSIZE = 5;
static const int REVERB_DAMP = 6;

class SuperpoweredExample {
public:

	SuperpoweredExample(unsigned int samplerate, unsigned int buffersize, const char *path, int fileAoffset, int fileAlength, int fileBoffset, int fileBlength);
	~SuperpoweredExample();

	bool process(short int *output, unsigned int numberOfSamples);
	void onPlayPause(bool play);
	void onCrossfader(int value);
	void onFxSelect(int value);
	void onFxOff();
	void onFxValue(int value);
	void onFxReverbValue(int param,int value);
	void onLimiterState(bool state);
	void startRecord(JNIEnv *env,jstring path);

private:
    SuperpoweredAndroidAudioIO *audioSystem;
    SuperpoweredAdvancedAudioPlayer *playerA, *playerB;
    SuperpoweredRoll *roll;
    SuperpoweredFilter *filter;
    SuperpoweredFlanger *flanger;
	SuperpoweredReverb *reverb;
	SuperpoweredLimiter *limiter;
    float *stereoBuffer;
    unsigned char activeFx;
    float crossValue, volA, volB;
};

#endif
