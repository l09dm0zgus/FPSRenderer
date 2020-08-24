#include "shader.h"

PFE::Shader::Shader(const GLchar* vertexPath,const GLchar* fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    vShaderFile.exceptions(std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::badbit);
    try
    {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream,fShaderStream;
        vShaderStream<<vShaderFile.rdbuf();
        fShaderStream<<fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout<<"Error shader : file not load"<<std::endl;
    }
    GLuint vertexShader,fragmentShader;


    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);


    const char *vertexShaderText,*fragmentShaderText;
    GLint success;
    GLchar log[512];


    vertexShaderText = vertexCode.c_str();
    fragmentShaderText = fragmentCode.c_str();



    glShaderSource(vertexShader,1,&vertexShaderText,NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader,512,NULL,log);
        std::cout<<"Error compile shader : "<<log<<std::endl;
    }



    glShaderSource(fragmentShader,1,&fragmentShaderText,NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader,512,NULL,log);
        std::cout<<"Error compile shader : "<<log<<std::endl;
    }

    program = glCreateProgram();

    glAttachShader(program,vertexShader);
    glAttachShader(program,fragmentShader);


    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, log);
        std::cout<<"Error link shaders  :  "<<log<<std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
void PFE::Shader::use()
{
    glUseProgram(program);
}
void PFE::Shader::setUniformVariable(glm::mat4 value, std::string uniformName)
{
    glUniformMatrix4fv(glGetUniformLocation(program, uniformName.c_str()), 1, GL_FALSE, &value[0][0]);
}
void PFE::Shader::setUniformVariable(int value,std::string uniformName)
{

    glUniform1i(glGetUniformLocation(program,uniformName.c_str()),value);

}
void PFE::Shader::setUniformVariable(float value,std::string uniformName)
{
    glUniform1f(glGetUniformLocation(program,uniformName.c_str()),value);
}
void PFE::Shader::setUniformVariable(std::vector<int>value, std::string uniformName)
{

    glUniform1iv(glGetUniformLocation(program,uniformName.c_str()),value.size(),value.data());
}
