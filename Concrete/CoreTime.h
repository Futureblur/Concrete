#pragma once

namespace CC
{
	// This class contains functions for retrieving time related information.
	class CoreTime
	{
	public:
		// Returns the current time in this format: HH:MM:SS.
		static std::string GetTimeString();
	};
}
