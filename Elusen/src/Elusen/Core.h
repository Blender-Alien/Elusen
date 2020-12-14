#pragma once

#ifdef EL_PLATFORM_WINDOWS
	#ifdef EL_BUILD_DLL
		#define ELUSEN_API __declspec(dllexport)
	#else
		#define ELUSEN_API __declspec(dllimport)
	#endif
#else
	#error Elusen only supports Windows!
#endif

#ifdef EL_ENABLE_ASSERTS
	#define EL_ASSERT(x, ...) { if(!(x)) {EL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define EL_CORE_ASSERT(x, ...) { if(!(x)) {EL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define EL_ASSERT(x, ...)
	#define EL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define EL_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)