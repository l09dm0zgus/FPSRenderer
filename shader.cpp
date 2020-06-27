#include "shader.h"

Shader::Shader(const GLchar* vertexPath,const GLchar* fragmentPath)
{
    string vertexCode;
    string fragmentCode;
    ifstream vShaderFile;
    ifstream fShaderFile;
    vShaderFile.exceptions(ifstream::badbit);
    fShaderFile.exceptions(ifstream::badbit);
    try
    {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        stringstream vShaderStream,fShaderStream;
        vShaderStream<<vShaderFile.rdbuf();
        fShaderStream<<fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (ifstream::failure e)
    {
        cout<<"Error shader : file not load"<<endl;
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
        cout<<"Error compile shader : "<<log<<endl;
    }



    glShaderSource(fragmentShader,1,&fragmentShaderText,NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader,512,NULL,log);
        cout<<"Error compile shader : "<<log<<endl;
    }

    this->program = glCreateProgram();

    glAttachShader(this->program,vertexShader);
    glAttachShader(this->program,fragmentShader);


    glLinkProgram(this->program);
    glGetProgramiv(this->program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(this->program, 512, NULL, log);
        cout<<"Error link shaders  :  "<<log<<endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
void Shader::use()
{
    glUseProgram(program);
  //  cout<<"Used : "<<program<<endl;
}
