#include <iostream>
#include <memory>
#include <imgui/imgui.h>

#include <Engine3DCore/Input.hpp>
#include <Engine3DCore/Application.hpp>

class Engine3DEditor : public Engine3D::Application
{
	virtual void on_update() override
	{
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_W))
        {
            camera_position[2] -= 0.01f;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_S))
        {
            camera_position[2] += 0.01f;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_A))
        {
            camera_position[0] -= 0.01f;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_D))
        {
            camera_position[0] += 0.01f;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_E))
        {
            camera_position[1] += 0.01f;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_Q))
        {
            camera_position[1] -= 0.01f;
        }

        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_UP))
        {
            camera_rotation[0] += 0.5f;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_DOWN))
        {
            camera_rotation[0] -= 0.5f;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_RIGHT))
        {
            camera_rotation[1] -= 0.5f;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_LEFT))
        {
            camera_rotation[1] += 0.5f;
        }
	}

	virtual void on_ui_draw() override
	{
		ImGui::Begin("Editor");
		ImGui::SliderFloat3("camera position", camera_position, -10.f, 10.f);
		ImGui::SliderFloat3("camera rotation", camera_rotation, 0, 360.f);
		ImGui::Checkbox("Perspective camera", &perspective_camera);
		ImGui::End();
	}

	int frame = 0;
};

int main()
{
	auto pEngine3DEditor = std::make_unique<Engine3DEditor>();

	int returnCode = pEngine3DEditor->start(1024, 768, "Engine3D Editor");

	std::cin.get();

	return returnCode;
}