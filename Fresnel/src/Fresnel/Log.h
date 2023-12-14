#pragma once

#include <memory>

#include "Kern.h"
#include "spdlog/spdlog.h"

namespace Fresnel
{
	class FRESNEL_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}

// Core log macros
#define FS_CORE_TRACE(...)   ::Fresnel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FS_CORE_INFO(...)    ::Fresnel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FS_CORE_WARN(...)    ::Fresnel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FS_CORE_ERROR(...)   ::Fresnel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FS_CORE_FATAL(...)   ::Fresnel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define FS_TRACE(...)        ::Fresnel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FS_INFO(...)         ::Fresnel::Log::GetClientLogger()->info(__VA_ARGS__)
#define FS_WARN(...)         ::Fresnel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FS_ERROR(...)        ::Fresnel::Log::GetClientLogger()->error(__VA_ARGS__)
#define FS_FATAL(...)        ::Fresnel::Log::GetClientLogger()->fatal(__VA_ARGS__)