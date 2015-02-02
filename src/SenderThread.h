#pragma once
#include "ofThread.h"
#include <ofxOsc.h>

/*
Sends periodic frame number OSC messages, plus others (to come)
Only has millisecond accuracy currently, because ofThread's sleep() takes a ms argument.
*/
class SenderThread :
	public ofThread
{
public:
	SenderThread(void);
	~SenderThread(void);
	void setup(std::string address, int port, int interval, int interval_timescale);
	long getFrameNumber();
	void resetFrameNumber();
	void send(ofxOscMessage& message);
protected:
	virtual void threadedFunction();
private:
	std::string address_;
	int port_;
	int interval_;
	int interval_timescale_;
	long frame_number_;
    bool frame_number_should_reset_;
	std::queue<ofxOscMessage> queue_;
};

