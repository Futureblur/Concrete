#pragma once

#include "Core.h"

namespace CC
{
	// Specifies the severity of a log message.
	enum LogSeverity : uint8_t
	{
		INFO,
		WARNING,
		ERROR,
		FATAL
	};

	// This class is responsible for logging messages to the console.
	class Log
	{
	public:
		// Logs an info message to the console.
		static void Info(const std::stringstream& message);

		// Logs a warning message to the console.
		static void Warn(const std::stringstream& message);

		// Logs an error message to the console.
		static void Error(const std::stringstream& message);

		// Logs a fatal error message to the console.
		static void Fatal(const std::stringstream& message);

		// Converts LogSeverity enum into string.
		static std::string LogSeverityToStr(const LogSeverity& severity);

	private:
		// Logs to the standard output using a custom template.
		static void LogIntern(const LogSeverity& severity, const std::stringstream& message);
	};

	// Base macro for logging messages to the console.
	#define CC_LOG(message, source, severity)                   \
			do {                                                \
				std::stringstream _logStringStream;             \
				_logStringStream << message;                    \
				Log::severity(_logStringStream, source);        \
			} while(0)

	// Macro for logging an info message to the console with the source being PLAYER.
	#define CC_INFO(message) CC_LOG(message, Info)

	// Macro for logging a warning message to the console with the source being PLAYER.
	#define CC_WARN(message) CC_LOG(message, Warn)

	// Macro for logging an error message to the console with the source being PLAYER.
	#define CC_ERROR(message) CC_LOG(message, Error)

	// Macro for logging a fatal error message to the console with the source being PLAYER.
	#define CC_FATAL(message) CC_LOG(message, Fatal)

	// Converts Vec2 into text.
	#define CC_VEC2_TEXT(vector) "( " << (vector).x << " | " << (vector).y << " )"

	// Converts Vec3 into text.
	#define CC_VEC3_TEXT(vector) "( " << (vector).x << " | " << (vector).y << " | " << (vector).z << " )"

	// Converts Vec4 into text.
	#define CC_VEC4_TEXT(vector) "( " << (vector).x << " | " << (vector).y << " | " << (vector).z << " | " << (vector).w << " )"
}
