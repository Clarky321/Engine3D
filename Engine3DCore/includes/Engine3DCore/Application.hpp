#pragma once

#include "Engine3DCore/Event.hpp"
#include "Engine3DCore/Camera.hpp"

#include <memory>

using namespace Enigne3D;

namespace Engine3D {

    class Application
    {
    public:
        Application();
        virtual ~Application();
        Application(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;
        virtual int start(unsigned int window_width, unsigned int window_height, const char* title);

        virtual void on_update() {}

        virtual void on_ui_draw() {}

        float camera_position[3] = { 0.f, 0.f, 1.f };
        float camera_rotation[3] = { 0.f, 0.f, 0.f };

        bool perspective_camera = true;

        Camera camera{ glm::vec3(-5.f, 0.f, 0.f) };


    private:
        std::unique_ptr<class Window> m_pWindow;

        EventDispatcher m_event_dispatcher;
        bool m_bCloseWindow = false;
    };
}