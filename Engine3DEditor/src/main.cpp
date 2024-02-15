#include <iostream>
#include <memory>
#include <imgui/imgui.h>

#include <Engine3DCore/Input.hpp>
#include <Engine3DCore/Application.hpp>

class Engine3DEditor : public Engine3D::Application
{
	virtual void on_update() override
	{
        bool move_camera = false;
        glm::vec3 movement_delta{ 0, 0, 0 };
        glm::vec3 rotation_delta{ 0, 0, 0 };

        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_W))
        {
            camera_position[2] -= 0.01f;
            movement_delta.x += 0.05f;
            move_camera = true;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_S))
        {
            camera_position[2] += 0.01f;
            movement_delta.x -= 0.05f;
            move_camera = true;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_A))
        {
            camera_position[0] -= 0.01f;
            movement_delta.y -= 0.05f;
            move_camera = true;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_D))
        {
            camera_position[0] += 0.01f;
            movement_delta.y += 0.05f;
            move_camera = true;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_E))
        {
            camera_position[1] += 0.01f;
            movement_delta.z += 0.05f;
            move_camera = true;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_Q))
        {
            camera_position[1] -= 0.01f;
            movement_delta.z -= 0.05f;
            move_camera = true;
        }

        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_UP))
        {
            camera_rotation[0] += 0.5f;
            rotation_delta.y -= 0.5f;
            move_camera = true;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_DOWN))
        {
            camera_rotation[0] -= 0.5f;
            rotation_delta.y += 0.5f;
            move_camera = true;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_RIGHT))
        {
            camera_rotation[1] -= 0.5f;
            rotation_delta.z -= 0.5f;
            move_camera = true;
        }
        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_LEFT))
        {
            camera_rotation[1] += 0.5f;
            rotation_delta.z += 0.5f;
            move_camera = true;
        }

        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_P))
        {
            rotation_delta.x += 0.5f;
            move_camera = true;
        }

        if (Engine3D::Input::IsKeyPressed(Engine3D::KeyCode::KEY_O))
        {
            rotation_delta.x -= 0.5f;
            move_camera = true;
        }

        if (move_camera)
        {
            camera.add_movement_and_rotatition(movement_delta, rotation_delta);
        }
	}

	virtual void on_ui_draw() override
	{
        camera_position[0] = camera.get_camera_position().x;
        camera_position[1] = camera.get_camera_position().y;
        camera_position[2] = camera.get_camera_position().z;
        camera_rotation[0] = camera.get_camera_rotation().x;
        camera_rotation[1] = camera.get_camera_rotation().y;
        camera_rotation[2] = camera.get_camera_rotation().z;

		ImGui::Begin("Editor");

        if (ImGui::SliderFloat3("camera position", camera_position, -10.f, 10.f))
        {
            camera.set_position(glm::vec3(camera_position[0], camera_position[1], camera_position[2]));
        }
        if (ImGui::SliderFloat3("camera rotation", camera_rotation, 0, 360.f))
        {
            camera.set_rotation(glm::vec3(camera_rotation[0], camera_rotation[1], camera_rotation[2]));
        }

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