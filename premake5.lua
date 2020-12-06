workspace "mnk"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

local outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

project "mnk"
	location "mnk"
	kind "ConsoleApp"
	language "C++"
	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-intermediate/" .. outputdir .. "/%{prj.name}")
	
	pchheader "mnkpch.h"
   	pchsource("%{prj.name}/src/mnkpch.cpp")
	
	defines { "MNK" } -- compiling for .exe not .dll, for .dll use "MNK_API" instead of "MNK"
	
	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/shaders/**.glsl",
		"%{prj.name}/textures/**.png",
		"%{prj.name}/textures/**.jpg",
		"%{prj.name}/fonts/**.ttf",
		"%{prj.name}/sounds/**.ogg",
	}

	includedirs
	{
	    "includes/",
	    "%{prj.name}/src"
	}

	libdirs
	{
		"libs/"
	}

	links 
	{ 
		"opengl32.lib", 
		"glfw3.lib" 
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
	       
		postbuildcommands
		{
			"{COPY} shaders ../bin/" .. outputdir .. "/%{prj.name}/shaders/",
			"{COPY} textures ../bin/" .. outputdir .. "/%{prj.name}/textures/",
			"{COPY} fonts ../bin/" .. outputdir .. "/%{prj.name}/fonts/",
			"{COPY} sounds ../bin/" .. outputdir .. "/%{prj.name}/sounds/"
		}

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"

	filter "files:**.c"
	       flags { "NoPCH" }
