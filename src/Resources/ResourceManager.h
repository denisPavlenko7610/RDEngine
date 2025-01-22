#pragma once
#include <map>
#include <memory>
#include <string>

namespace Renderer
{
    class ShaderProgram;
}

class ResourceManager
{
public:
    ResourceManager(const std::string& executablePath);
    ~ResourceManager();

    ResourceManager(ResourceManager&) = delete;
    ResourceManager& operator=(ResourceManager&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;
    ResourceManager(ResourceManager&&) = delete;

    std::shared_ptr<Renderer::ShaderProgram> loadShader(std::string shaderName, std::string vertexPath,
                                                        std::string fragmentPath);
    std::shared_ptr<Renderer::ShaderProgram> getShader(std::string& shaderName);

private:
    std::string getFileString(const std::string& relativeFilePath);
    
    typedef std::map<std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramsMap;
    ShaderProgramsMap _shaderPrograms;

    std::string _path;
};
