#pragma once

#include "Elusen/Layer.h"

#include "Elusen/Events/ApplicationEvent.h"
#include "Elusen/Events/KeyEvent.h"
#include "Elusen/Events/MouseEvent.h"

namespace Elusen {

	class ELUSEN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);

		bool OnWindowResizeEvent(WindowResizeEvent& e);
	private:
		float m_Time = 0.0f;
	};

}