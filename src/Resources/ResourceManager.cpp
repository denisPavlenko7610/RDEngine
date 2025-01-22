#include "ResourceManager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include "../Render/ShaderProgram.h"

using namespace std;

ResourceManager::ResourceManager(const string& executablePath)
{
    size_t found = executablePath.find_last_of("/\\");
    _path = executablePath.substr(0, found);
}

ResourceManager::~ResourceManager()
{
}

shared_ptr<Renderer::ShaderProgram> ResourceManager::loadShader(string shaderName, string vertexPath,
    string fragmentPath)
{
    string vertexString = getFileString(vertexPath);
    if (vertexString.empty())
    {
        cerr << "Failed to load vertex shader: " << vertexPath << endl;
        return nullptr;
    }

    string fragmentString = getFileString(fragmentPath);
    if (fragmentString.empty())
    {
        cerr << "Failed to load fragment shader: " << fragmentPath << '\n';
        return nullptr;
    }

    shared_ptr<Renderer::ShaderProgram>& newShader = _shaderPrograms.emplace(shaderName, make_shared<Renderer::ShaderProgram>(vertexString, fragmentString)).first->second;
    if (newShader->IsCompiled())
    {
        return newShader;
    }

    cerr << "Failed to compile shader: " << shaderName << '\n';
    return nullptr;
}

shared_ptr<Renderer::ShaderProgram> ResourceManager::getShader(string& shaderName)
{
    map<string, shared_ptr<Renderer::ShaderProgram>>::iterator iterator = _shaderPrograms.find(shaderName);
    if (iterator != _shaderPrograms.end())
    {
        return iterator->second;
    }

    cerr << "Shader not found: " << shaderName << '\n';
    return nullptr;
}

string ResourceManager::getFileString(const string& relativeFilePath)
{
    ifstream stream;
    stream.open(_path + "/" + relativeFilePath, ios::in | ios::binary);
    if (!stream.is_open())
    {
        cerr << "Failed to open file: " << relativeFilePath << endl;
        return {};
    }

    stringstream buffer;
    buffer << stream.rdbuf();
    return buffer.str();
}

