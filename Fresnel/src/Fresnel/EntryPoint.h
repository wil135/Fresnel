#pragma once

#ifdef FS_PLATFORM_WINDOWS

extern Fresnel::Application* Fresnel::CreateApplication();

int main(int argc, char** argv)
{
	Fresnel::Log::init();
	FS_CORE_WARN("Initialized Log!");
	int a = 5;
	FS_INFO("Hello! Var={0}", a);

	Fresnel::Application* app = Fresnel::CreateApplication();
	app->run();
	delete app;

	return 0;
}

#endif