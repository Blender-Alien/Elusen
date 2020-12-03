#include "elpch.h"
#include "Application.h"

#include "Elusen/Events/ApplicationEvent.h"
#include "Elusen/Log.h"

namespace Elusen {


	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowsResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			EL_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			EL_TRACE(e);
		}

		while (true);
	}
}