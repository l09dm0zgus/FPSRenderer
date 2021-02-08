#include "texture.h"

glm::vec2 PFE::Texture::getTextureSize()
{
    glm::vec2 size;
    size.x = imageWidth;
    size.y = imageHeight;
    return size;
}

void PFE::Texture::loadImageFile(std::string file)
{
    try
    {
       int imageChanels;
       image = stbi_load(file.c_str(),&imageWidth,&imageHeight,&imageChanels,STBI_rgb_alpha);
       if(!image)
       {
           throw "ERROR::Image file not found.";
       }
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
}

void PFE::Texture::create()
{
    if(image)
    {
        glGenTextures(1,&imageProgram);
        glBindTexture(GL_TEXTURE_2D,imageProgram);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            // Set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,imageWidth,imageHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,image);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(image);
        glBindTexture(GL_TEXTURE_2D,0);
    }
    else
    {
        std::cout<<"ERROR::Image not created!"<<std::endl;
    }
}

void PFE::Texture::draw(int id)
{
    glActiveTexture(GL_TEXTURE0+id);
  //  std::cout <<std::hex<< GL_TEXTURE0 + id << std::endl;
    glBindTexture(GL_TEXTURE_2D,imageProgram);
}
