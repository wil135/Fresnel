#include <Fresnel.h>

class Sandbox 
	: public Fresnel::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Fresnel::Application* Fresnel::CreateApplication()
{
	return new Sandbox();
}