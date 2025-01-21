#pragma once

#include <string>

#include "glad/glad.h"

namespace Renderer
{
    class ShaderProgram
    {
    public:
        ShaderProgram() = delete;
        ShaderProgram(ShaderProgram&) = delete;
        ShaderProgram(const std::string& vertexShader, std::string& fragmentShader);
        ~ShaderProgram();

        ShaderProgram& operator = (ShaderProgram&) = delete;
        ShaderProgram& operator = (ShaderProgram&&) noexcept;
        ShaderProgram(ShaderProgram&& shaderProgram);
        
        bool IsCompiled() const { return _isCompiled; }
        void Use() const;
        
    private:
        bool CreateShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);
        bool _isCompiled = false;
        GLuint _shaderId = 0;
    };
}

