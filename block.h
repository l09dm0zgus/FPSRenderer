#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include "shader.h"
#include "camera.h"
#include "blockvertices.h"
#include "vertexbuffers.h"
#include "texture.h"
using namespace  std;
using namespace  PFE;
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
    glm::vec3 getPosition();
private:
    VertexBuffers blockBuffers;
    BlockVertices vertices;
    Texture tex1 ,tex2;
    GLfloat *setTextureSize();
    void transform();
    Shader *shaders;
    glm::mat4 SRT;
    glm::vec3 position;
    glm::vec3 size;
    glm::mat4 rotate;

};

#endif // BLOCK_H
