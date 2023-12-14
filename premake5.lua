workspace "Fresnel"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Fresnel"
	location "Fresnel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FS_PLATFORM_WINDOWS",
			"FS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FS_DEBUG"
		symbols "On"
			
	filter "configurations:Release"
		defines "FS_RELEASE"
		symbols "On"
			
	filter "configurations:Dist"
		defines "FS_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Fresnel/vendor/spdlog/include",
		"Fresnel/src"
	}

	links
	{
		"Fresnel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FS_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "FS_DEBUG"
		symbols "On"
			
	filter "configurations:Release"
		defines "FS_RELEASE"
		symbols "On"
			
	filter "configurations:Dist"
		defines "FS_DIST"
		symbols "On"