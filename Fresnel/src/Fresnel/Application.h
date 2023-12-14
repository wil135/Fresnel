#pragma once

#include "Kern.h"

namespace Fresnel 
{
	class FRESNEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// to be defined in client
	Application* CreateApplication();
}
