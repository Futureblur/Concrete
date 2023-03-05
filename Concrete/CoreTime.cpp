#include "CoreTime.h"

namespace CC
{
	std::string CoreTime::GetTimeString()
	{
		auto now = std::chrono::system_clock::now();
		auto time = std::chrono::system_clock::to_time_t(now);

		std::stringstream ss;
		ss << std::put_time(std::localtime(&time), "%X");
		return ss.str();
	}
}
