#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include "libs/glm/gtc/matrix_transform.hpp"
#include "shader.h"
#include "camera.h"
using namespace  std;
class Block
{
public:
    Block();
    void setPosition(glm::vec3 position);
    void setSize(glm::vec3 size);
    void setRotate(GLfloat angle,glm::vec3 axis);
    void loadTextures(string text1,string text2);
    void render(Camera &cam);
    void setShaderFile(string vertexShader,string fragmentShader);
    glm::vec3 getSize();
    void destroy();
    void collision(Camera &cam);
    glm::vec3 getPosition();
private:
    GLuint texture1,texture2;
    GLfloat *setTextureSize();
    void transform();
    GLuint VBO,VAO;
    Shader *shaders;
    glm::mat4 SRT;
    glm::vec3 position;
    glm::vec3 size;
    glm::mat4 rotate;

};

#endif // BLOCK_H
