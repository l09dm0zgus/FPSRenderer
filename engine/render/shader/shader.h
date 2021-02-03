#ifndef SHADER_H
#define SHADER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace PFE
{
    class ShaderProgram
    {
        public:
            void use();
            ShaderProgram(const GLchar * vertexPath,const GLchar *fragmentPath);
            void setUniformVariable(int value,std::string uniformName);
            void setUniformVariable(glm::mat4 value, std::string uniformName);
            void setUniformVariable(float value,std::string uniformName);
            void setUniformVariable(std::vector<int>value,std::string uniformName);
            void setUniformVariable(glm::vec3 value, std::string uniformName);
            void setUniformVariable(glm::vec4 value, std::string uniformName);
        private:
            GLuint program;
            std::string vertexCode;
            std::string fragmentCode;
            const char *vertexShaderText,*fragmentShaderText;
            GLuint vertexShader,fragmentShader;
            GLint success;
            GLchar log[512];
            void readFiles(const GLchar * vertexPath,const GLchar *fragmentPath);
            void compile();
            void link();

    };

}

#endif // SHADER_H
