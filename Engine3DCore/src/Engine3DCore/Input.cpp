#include "Engine3DCore/Input.hpp"

namespace Engine3D {

	bool Input::m_keys_pressed[static_cast<size_t>(KeyCode::KEY_LAST)] = {};

	bool Input::IsKeyPressed(const KeyCode key_code)
	{
		return m_keys_pressed[static_cast<size_t>(key_code)];
	}
	void Input::PressKey(const KeyCode key_code)
	{
		m_keys_pressed[static_cast<size_t>(key_code)] = true;
	}
	void Input::ReleaseKey(const KeyCode key_code)
	{
		m_keys_pressed[static_cast<size_t>(key_code)] = false;
	}
}