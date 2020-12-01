#pragma once

#include "spdlog/spdlog.h"


#ifdef EL_PLATFORM_WINDOWS

extern Elusen::Application* Elusen::CreateApplication();

int main(int argc, char** argv)
{
	Elusen::Log::Init();
	EL_CORE_WARN("Initialized Log!");
	int a = 5;
	EL_INFO("Hello! Var={0}", a);
	
	auto app = Elusen::CreateApplication();
	app->Run();
	delete app;
}

#endif