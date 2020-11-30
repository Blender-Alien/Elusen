#pragma once

#ifdef EL_PLATFORM_WINDOWS

extern Elusen::Application* Elusen::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Elusen::CreateApplication();
	app->Run();
	delete app;
}

#endif