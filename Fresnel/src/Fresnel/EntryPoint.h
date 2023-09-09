#pragma once

#ifdef FS_PLATFORM_WINDOWS

extern Fresnel::Application* Fresnel::CreateApplication();

int main(int argc, char** argv)
{
	Fresnel::Application* app = Fresnel::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif