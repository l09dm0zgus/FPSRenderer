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
    class Shader
    {
        public:
            void use();
            Shader(const GLchar * vertexPath,const GLchar *fragmentPath);
            void setUniformVariable(int value,std::string uniformName);
            void setUniformVariable(glm::mat4 value, std::string uniformName);
            void setUniformVariable(float value,std::string uniformName);
            void setUniformVariable(std::vector<int>value,std::string uniformName);
        private:
            GLuint program;

    };

}

#endif // SHADER_H
