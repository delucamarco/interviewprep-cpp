/*
 * Common.h
 *
 */

#ifndef ALGORITHM_COMMON_H
#define ALGORITHM_COMMON_H

#include <sys/time.h>
#include <stddef.h>

namespace common
{
	class Chronometer
	{
		private:
			timeval _a_time, _b_time;
			double  _elapsed_time;
			bool    _isRunning;

		public:
			Chronometer();

			void start();
			void start(timeval a_time);
			double stop();
			double timeRunning();
	};
}

#endif /* ALGORITHM_COMMON_H */
