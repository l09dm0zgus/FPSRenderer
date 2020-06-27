#include "sprite.h"

Sprite::Sprite()
{
    this->SRT = glm::mat4(1.0f);
    this->rotate = glm::mat4(1.0f);
}
void Sprite::setPosition(glm::vec3 position)
{
    this->position = position;
    this->transform();
}

void Sprite::setRotate(GLfloat angle, glm::vec3 axis)
{
    rotate = glm::rotate(rotate,angle,axis);
    this->transform();
}
void Sprite::setSize(glm::vec3 size)
{
    this->size = size;
    this->transform();
}
void Sprite::setShaderFile(string vertexShader, string fragmentShader)
{
    this->shaders = new Shader(vertexShader.c_str(),fragmentShader.c_str());
}
void Sprite::animation()
{
    for(int i = 0;i<5;i++)
    {
        setTilePosition(6,4,i,1);
    }
}
void Sprite::loadTextures(string text1)
{
    int width,height;
    unsigned char *image = SOIL_load_image(text1.c_str(),&width,&height,0,SOIL_LOAD_RGBA);
    if(!image)
    {
        cout<<"Failed load texture!!!"<<endl;
    }
    glGenTextures(1,&texture1);
    glBindTexture(GL_TEXTURE_2D,texture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D,0);


    glGenBuffers(1,&VBO);

    glGenVertexArrays(1,&VAO);

    //bind
    glBindVertexArray(VAO);


    GLfloat vertices[] = {
        0.0f, 1.0f, 1.0f,  0.0f, 1.0f,
        1.0f, 0.0f, 1.0f,  1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,  0.0f, 0.0f,

        0.0f, 1.0f, 1.0f,  0.0f, 1.0f,
        1.0f, 1.0f, 1.0f,  1.0f, 1.0f,
        1.0f, 0.0f, 1.0f,  1.0f, 0.0f
    };
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof (vertices),vertices,GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat)*5,(GLvoid * )0);
    glEnableVertexAttribArray(0);


    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof (GLfloat)*5,(GLvoid *)(sizeof (GLfloat)*3));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    glUniform1i(glGetUniformLocation(shaders->program,"image"),0);
    rowsLoc = glGetUniformLocation(shaders->program,"rowsTile");
    collLoc = glGetUniformLocation(shaders->program,"collumsTile");
    rowPosLoc  = glGetUniformLocation(shaders->program,"rowPosition");
    collPosLoc = glGetUniformLocation(shaders->program,"collumsPosition");
}
int frameCounter =1;
float framesPerSecond = 1.0f;
void Sprite::setTilePosition(float rows, float collums, float rowPos, float colPos)
{

    if(animationFrame >rows)
    {
        animationFrame = 1.0f;
    }
    framesPerSecond = 139;
    glUniform1f(rowsLoc,rows);
    glUniform1f(collLoc,collums);
    glUniform1f(rowPosLoc,animationFrame);
    glUniform1f(collPosLoc,colPos);
   // cout<<"Delta t:"<<dTime<<endl;
    if((glfwGetTime()/frameCounter)>=0.1)
    {
        animationFrame++;
        frameCounter++;
    }

}
glm::vec3 Sprite::getPosition()
{
    return this->position;
}
void Sprite::render(Camera &cam)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,texture1);

    shaders->use();
    setTilePosition(6,4,1,1);
   // setTilePosition(4,1,2,1);
    glm::mat4 projection,view(1.0);
    view = cam.getView();
    //todo class window with persepctive
    projection = glm::perspective(glm::radians(65.0f),800.0f/600.0f,0.1f,100.0f);
    GLint transformLoc = glGetUniformLocation(shaders->program, "projection");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &projection[0][0]);
    transformLoc = glGetUniformLocation(shaders->program, "view");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &view[0][0]);
    transformLoc = glGetUniformLocation(shaders->program, "model");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &SRT[0][0]);


    //animation();

    //calc time between frames
    GLfloat currentFrame = glfwGetTime();
    dTime = currentFrame - lFrame;
    lFrame = currentFrame;

    //draw vertices
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,6);
    glBindVertexArray(0);

}
void Sprite::transform()
{
    glm::mat4 scale(1.0),translate(1.0f);
    scale = glm::scale(scale,size);
    translate = glm::translate(translate,position);
    SRT=translate * rotate *scale;
}
void Sprite::destroy()
{
    delete  shaders;
    shaders = nullptr;
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
glm::vec3 Sprite::getSize()
{
    return  this->size;
}

