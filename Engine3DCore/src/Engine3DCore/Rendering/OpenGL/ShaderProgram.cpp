#include "ShaderProgram.hpp"

#include "Engine3DCore/Log.hpp"

#include <glad/glad.h>

namespace Engine3D{

	bool create_shader(const char* source, const GLenum shader_type, GLuint& shader_id)
	{
		shader_id = glCreateShader(shader_type);
		glShaderSource(shader_id, 1, &source, nullptr);
		glCompileShader(shader_id);

		GLint success;
		glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE)
		{
			char info_log[1024];
			glGetShaderInfoLog(shader_id, 1024, nullptr, info_log);

			LOG_CRITICAL("Shader compilation error:\n{}", info_log);
			return false;
		}
		return true;
	}

}