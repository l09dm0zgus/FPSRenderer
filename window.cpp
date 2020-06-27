#include "window.h"

Window::Window(int w,int h,string windowTitle)
{
    this->w = w;
    this->h = h;
    this->windowTitle = windowTitle.c_str();
    init();
}
void Window::init()
{
    glfwInit();
    glfwInitHint(GLFW_VERSION_MAJOR,3);
    glfwInitHint(GLFW_VERSION_MINOR,3);
    glfwInitHint(GLFW_OPENGL_ANY_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwInitHint(GLFW_RESIZABLE,GL_FALSE);
    window = glfwCreateWindow(w,h,windowTitle,nullptr,nullptr);
    if(window == nullptr)
    {
        cout<<"FAILED CREATE WINDOW!!!!"<<endl;
        glfwTerminate();

    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    GLenum result = glewInit();
    if(result  != GLEW_OK)
    {
        fprintf(stderr,"ERROR : '%s' \n'",glewGetErrorString(result));
    }

    glfwGetFramebufferSize(window,&w,&h);
    glViewport(0,0,w,h);
}
void Window::render(void (*renderCallback)(),void (*mouseCallback)(GLFWwindow*,double,double),void (*keyCallback)(GLFWwindow*,int,int,int,int))
{

    glEnable(GL_DEPTH_TEST);

    //enable trancperency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        glfwSetCursorPosCallback(window, mouseCallback);

        glfwSetKeyCallback(window,keyCallback);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        (*renderCallback)();
        glfwSwapBuffers(window);
    }
}
void Window::destroy()
{
    glfwTerminate();
}
