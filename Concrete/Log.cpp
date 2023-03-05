#include "Log.h"

#include "CoreTime.h"

namespace CC
{
	void Log::Info(const std::stringstream& message)
	{
		LogIntern(LogSeverity::INFO, message);
	}

	void Log::Warn(const std::stringstream& message)
	{
		LogIntern(LogSeverity::WARNING, message);
	}

	void Log::Error(const std::stringstream& message)
	{
		LogIntern(LogSeverity::ERROR, message);
	}

	void Log::Fatal(const std::stringstream& message)
	{
		LogIntern(LogSeverity::FATAL, message);
	}

	void Log::LogIntern(const LogSeverity& severity, const std::stringstream& message)
	{
		std::string currentTime = CoreTime::GetTimeString();
		std::string color, clearColor;

		std::cout << color << currentTime << " " << LogSeverityToStr(severity) << " "
				  << message.str() << clearColor << "\n";
	}

	std::string Log::LogSeverityToStr(const LogSeverity& severity)
	{
		switch (severity)
		{
			case LogSeverity::INFO:
				return "INFO";

			case LogSeverity::WARNING:
				return "WARNING";

			case LogSeverity::ERROR:
				return "ERROR";

			case LogSeverity::FATAL:
				return "FATAL";

			default:
				return "";
		}
	}
}

