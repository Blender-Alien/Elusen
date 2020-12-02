#pragma once

#include "spdlog/spdlog.h"


#ifdef EL_PLATFORM_WINDOWS

extern Elusen::Application* Elusen::CreateApplication();

int main(int argc, char** argv)
{
	Elusen::Log::Init();
	EL_CORE_WARN("Initialized Log!");
	EL_INFO("That's a test message!");
	
	auto app = Elusen::CreateApplication();
	app->Run();
	delete app;
}

#endif