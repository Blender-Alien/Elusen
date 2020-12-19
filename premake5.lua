workspace "Elusen"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution dircetory)
IncludeDir = {}
IncludeDir["GLFW"] = "Elusen/vendor/GLFW/include"
IncludeDir["Glad"] = "Elusen/vendor/Glad/include"
IncludeDir["ImGui"] = "Elusen/vendor/imgui"

include "Elusen/vendor/GLFW"
include "Elusen/vendor/Glad"
include "Elusen/vendor/imgui"

project "Elusen"
	location "Elusen"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "elpch.h"
	pchsource "Elusen/src/elpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
				"EL_PLATFORM_WINDOWS",
				"EL_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "EL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "EL_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "EL_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Elusen/vendor/spdlog/include",
		"Elusen/src"
	}

	links
	{
		"Elusen"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
				"EL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "EL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "EL_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "EL_DIST"
		runtime "Release"
		optimize "On"