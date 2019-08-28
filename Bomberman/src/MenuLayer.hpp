#pragma once

#include <Swallow.hpp>

class MenuLayer : public Swallow::Layer {
private:
	Swallow::Ref<Swallow::GameObject> m_Square;

	Swallow::OrthographicCamera m_Camera;

	glm::ivec2 map_size;
public:
	MenuLayer();
	MenuLayer(const MenuLayer &s) = default;
	MenuLayer &operator=(const MenuLayer &s) = default;
	virtual ~MenuLayer() = default;

	bool OnMouseButtonPressed(Swallow::MouseButtonPressedEvent &e);
	bool OnMouseMovedEvent(Swallow::MouseMovedEvent &e);
	bool OnKeyPressed(Swallow::KeyPressedEvent &e);
	bool OnWindowResize(Swallow::WindowResizeEvent &e);


	virtual void OnEvent(Swallow::Event &e) override;
	virtual void OnImGuiRender() override;
	virtual void OnUpdate(Swallow::Timestep ts) override;
};