#include <iostream>
#include <memory>
#include <imgui/imgui.h>

#include <Engine3DCore/Application.hpp>

class Engine3DEditor : public Engine3D::Application
{
	virtual void on_update() override
	{
		//std::cout << "Update frame: " << frame++ << std::endl;
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