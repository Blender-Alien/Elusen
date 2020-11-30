#include <Elusen.h>

class Sandbox : public Elusen::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox() {

	}

};

Elusen::Application* Elusen::CreateApplication()
{
	return new Sandbox();
}