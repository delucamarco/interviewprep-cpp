/*
 * Common.cpp
 *
 */

#include "Common.h"

common::Chronometer::Chronometer()
{
	_isRunning = false;
}

void common::Chronometer::start()
{
	if(_isRunning == false)
	{
		gettimeofday(&_a_time, NULL);
		_isRunning = true;
	}
}

void common::Chronometer::start(timeval a_time)
{
	if(_isRunning == false)
	{
		_a_time = a_time;
		_isRunning = true;
	}
}

double common::Chronometer::stop()
{
	double elapsed_time = 0.0;

	_isRunning = false;

	gettimeofday(&_b_time, NULL);

	elapsed_time =  (_b_time.tv_sec - _a_time.tv_sec) * 1000;   // seconds to milliseconds
	elapsed_time += (_b_time.tv_usec - _a_time.tv_usec) / 1000.0; // microseconds to milliseconds

	return elapsed_time;
}

double common::Chronometer::timeRunning()
{
	double elapsed_time = 0.0;
	if(_isRunning)
	{
		timeval currentTime;
		gettimeofday(&currentTime, NULL);

		elapsed_time =  (currentTime.tv_sec - _a_time.tv_sec) * 1000;   // seconds to milliseconds
		elapsed_time += (currentTime.tv_usec - _a_time.tv_usec) / 1000.0; // microseconds to milliseconds
	}

	return elapsed_time;
}
