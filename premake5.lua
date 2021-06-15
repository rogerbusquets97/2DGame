workspace "PixelGame"
	architecture "x64"
	startproject "PixelGame"

	configurations
	{
		"Debug",
		"Release"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	IncludeDir = {}
	IncludeDir["PixelGameEngine"] = "PixelGame/ThirdParty/olcPixelGameEngine/Include"
	IncludeDir["entt"] = "PixelGame/ThirdParty/entt/include"

project "PixelGame"
	location "PixelGame"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/ThirdParty/**.h",
		"%{prj.name}/ThirdParty/**.cpp",
		"%{prj.name}/ThirdParty/**.hpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		IncludeDir["PixelGameEngine"],
		IncludeDir["entt"]
	}

	libdirs
	{
	}

	links
	{
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PLATFORM_WINDOWS",
			"_CRT_SECURE_NO_WARNINGS"
		}

		undefines
		{
			"_UNICODE",
			"UNICODE"
		}

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		optimize "on"