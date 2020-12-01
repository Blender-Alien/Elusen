#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Elusen {
	
	class ELUSEN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define EL_CORE_TRACE(...) ::Elusen::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EL_CORE_ERROR(...) ::Elusen::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EL_CORE_WARN(...)  ::Elusen::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EL_CORE_INFO(...)  ::Elusen::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EL_CORE_FATAL(...) ::Elusen::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Core log macros
#define EL_TRACE(...) ::Elusen::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EL_ERROR(...) ::Elusen::Log::GetClientLogger()->error(__VA_ARGS__)
#define EL_WARN(...)  ::Elusen::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EL_INFO(...)  ::Elusen::Log::GetClientLogger()->info(__VA_ARGS__)
#define EL_FATAL(...) ::Elusen::Log::GetClientLogger()->fatal(__VA_ARGS__)