#pragma once

#ifdef FS_PLATFORM_WINDOWS
	#ifdef FS_BUILD_DLL
		#define FRESNEL_API __declspec(dllexport)
	#else
		#define FRESNEL_API __declspec(dllimport)
	#endif 
#else
	#error Fresnel only supports Windows for now!
#endif

#define BIT(x) (1 << x)