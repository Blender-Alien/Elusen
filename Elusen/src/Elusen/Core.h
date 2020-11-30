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