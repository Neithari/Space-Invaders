#include "FrameTime.h"

using namespace std::chrono;

FrameTime::FrameTime()
{
	last = steady_clock::now();
}

float FrameTime::Mark()
{
	auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}
