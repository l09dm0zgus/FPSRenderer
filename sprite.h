#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include "libs/glm/gtc/matrix_transform.hpp"
#include "shader.h"
#include "camera.h"
using namespace  std;

class Sprite
{
public:
    Sprite();
    void setPosition(glm::vec3 position);
    void setSize(glm::vec3 size);
    void setRotate(GLfloat angle,glm::vec3 axis);
    void loadTextures(string text1);
    void render(Camera &cam);
    void setShaderFile(string vertexShader,string fragmentShader);
    void setTilePosition(float rows,float collums,float rowPos,float colPos);
    glm::vec3 getSize();
    void destroy();
    glm::vec3 getPosition();

private:
    float dTime=0.0f;
    float lFrame=0.0f;
    float animationFrame = 1.0f;
    GLint rowsLoc,collLoc,rowPosLoc,collPosLoc;
    GLfloat *setTextureSize();
    void transform();
    void animation();
    GLuint VBO,VAO;
    Shader *shaders;
    glm::mat4 SRT;
    glm::vec3 position;
    glm::vec3 size;
    glm::mat4 rotate;
    GLuint texture1;
};

#endif // SPRITE_H
