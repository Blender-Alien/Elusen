#pragma once

#include "Core.h"

namespace Elusen {

	class ELUSEN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}