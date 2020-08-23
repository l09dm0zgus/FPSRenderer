#include "texture.h"

void PFE::Texture::loadImageFile(std::string file)
{
    try
    {
       image = SOIL_load_image(file.c_str(),&imageWidth,&imageHeight,0,SOIL_LOAD_RGBA);
       if(!image)
       {
           throw "ERROR::Image file not found.";
       }
       
    }
    catch (std::string e)
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
        SOIL_free_image_data(image);
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
    glBindTexture(GL_TEXTURE_2D,imageProgram);
}
