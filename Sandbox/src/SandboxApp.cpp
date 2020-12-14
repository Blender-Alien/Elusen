#include <Elusen.h>

class ExampleLayer : public Elusen::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		EL_INFO("ExampleLayer::Update");
	}

	void OnEvent(Elusen::Event& event) override
	{
		EL_TRACE("{0}", event);
	}
};

class Sandbox : public Elusen::Application
{
public:
	
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Elusen::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Elusen::Application* Elusen::CreateApplication()
{
	return new Sandbox();
}