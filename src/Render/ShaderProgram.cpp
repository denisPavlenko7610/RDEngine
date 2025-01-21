#include "ShaderProgram.h"

namespace Renderer
{
    ShaderProgram::ShaderProgram(const std::string& vertexShader, std::string& fragmentShader)
    {
        GLuint vertexShaderID;
        if (!CreateShader(vertexShader, GL_VERTEX_SHADER, vertexShaderID))
        {
            printf("Vertex shader compile error");
            return;
        }

        GLuint fragmentShaderID;
        if (!CreateShader(fragmentShader, GL_FRAGMENT_SHADER, fragmentShaderID))
        {
            printf("Fragment shader compile error");
            glDeleteShader(vertexShaderID);
            return;
        }

        _shaderId = glCreateProgram();
        glAttachShader(_shaderId, vertexShaderID);
        glAttachShader(_shaderId, fragmentShaderID);
        glLinkProgram(_shaderId);

        GLint success;
        glGetProgramiv(_shaderId, GL_LINK_STATUS, &success);
        if (success)
        {
            _isCompiled = true;
        }
        else
        {
            GLchar infoLog[1024];
            glGetShaderInfoLog(_shaderId, 1024, nullptr, infoLog);
            printf("Error link shader type: '%s'\n", infoLog);
        }

        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);
    }

    ShaderProgram::~ShaderProgram()
    {
        glDeleteProgram(_shaderId);
    }

    ShaderProgram& ShaderProgram::operator=(ShaderProgram&& shaderProgram) noexcept
    {
        glDeleteShader(_shaderId);
        _shaderId = shaderProgram._shaderId;
        _isCompiled = shaderProgram._isCompiled;

        shaderProgram._shaderId = 0;
        shaderProgram._isCompiled = false;
        return *this;
    }

    ShaderProgram::ShaderProgram(ShaderProgram&& shaderProgram)
    {
        _shaderId = shaderProgram._shaderId;
        _isCompiled = shaderProgram._isCompiled;

        shaderProgram._shaderId = 0;
        shaderProgram._isCompiled = false;
    }

    void ShaderProgram::Use() const
    {
        glUseProgram(_shaderId);
    }

    bool ShaderProgram::CreateShader(const std::string& source, const GLenum shaderType, GLuint& shaderID)
    {
        shaderID = glCreateShader(shaderType);
        const char* code = source.c_str();
        glShaderSource(shaderID, 1, &code, nullptr);
        glCompileShader(shaderID);

        GLint success;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
        if (success)
            return true;
        
        GLchar infoLog[1024];
        glGetShaderInfoLog(shaderID, 1024, nullptr, infoLog);
        printf("Error compiling shader type %d: '%s'\n", shaderType, infoLog);
        
        return false;
    }
}
