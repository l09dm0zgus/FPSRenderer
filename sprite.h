#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <iterator>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <glm/gtc/matrix_transform.hpp>
#include "shader.h"
#include "camera.h"
#include "spritevertices.h"
#include "vertexbuffers.h"
using namespace  std;
using namespace  PFE;
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
    VertexBuffers spriteBuffers;
    SpriteVertices vertices;
    float animationFrame = 1.0f;
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
