#ifndef SHADER_H
#define SHADER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
using namespace  std;
class Shader
{
public:
    GLuint program;
    void use();
    Shader(const GLchar * vertexPath,const GLchar *fragmentPath);

};

#endif // SHADER_H
