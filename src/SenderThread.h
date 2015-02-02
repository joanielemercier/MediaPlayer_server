#pragma once
#include "ofThread.h"

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
	void setFrameNumber(long frame_number);
protected:
	virtual void threadedFunction();
private:
	long incrementFrameNumber();
	std::string address_;
	int port_;
	int interval_;
	int interval_timescale_;
	long frame_number_;
};

