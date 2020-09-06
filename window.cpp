#include "window.h"

PFE::Window::Window(int w,int h,string windowTitle)
{
    this->windowWidth = w;
    this->windowHeight = h;
    this->windowTitle = windowTitle.c_str();
    init();
}
void PFE::Window::GLFWInit()
{
    glfwInit();
    window = glfwCreateWindow(windowWidth,windowHeight,windowTitle,nullptr,nullptr);
    if(window == nullptr)
    {
        glfwTerminate();
        throw std::runtime_error("Failed create window!");
    }

    glfwMakeContextCurrent(window);

    glfwSetWindowUserPointer(window,this);
    glfwSetWindowSizeCallback(window,PFE::Window::resizeCallback);

   // glfwSetWindowSize(window,windowWidth,windowHeight);

    monitor =  glfwGetPrimaryMonitor();
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    glfwGetWindowPos(window, &windowX, &windowY);
    updateViewport = true;
}
void PFE::Window::GLEWInit()
{
    glewExperimental = GL_TRUE;
    GLenum result = glewInit();
    if(result  != GLEW_OK)
    {
        glfwTerminate();
        throw runtime_error("GL context not created!");
    }
}
void PFE::Window::init()
{
    GLFWInit();
    GLEWInit();
}
void PFE::Window::resizeCallback(GLFWwindow *window, int cx, int cy)
{
    void *ptr = glfwGetWindowUserPointer(window);
    if(Window *win = static_cast<Window*>(ptr))
        win->resize(cx,cy);
}
void PFE::Window::resize(int cx,int cy)
{
    updateViewport = true;
}
bool PFE::Window::isFullscreen()
{
    return glfwGetWindowMonitor(window) != nullptr;
}
void PFE::Window::setFullscreen(bool fullscreen)
{
    if(isFullscreen() == fullscreen)
        return;
    if (fullscreen)
    {
        // backup window position and window size
        glfwGetWindowPos(window, &windowX, &windowY);
        glfwGetWindowSize(window, &windowWidth, &windowHeight);

        // get resolution of monitor
        const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

        // switch to full screen
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, 0 );
    }
    else
    {
        // restore last window size and position
        glfwSetWindowMonitor(window, nullptr,  windowX, windowY, windowWidth, windowHeight, 0 );
    }

    updateViewport = true;
}
void PFE::Window::render(void (*renderCallback)(),void (*mouseCallback)(GLFWwindow*,double,double),void (*keyCallback)(GLFWwindow*,int,int,int,int))
{

    glEnable(GL_DEPTH_TEST);

    //enable trancperency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    double lastTime = glfwGetTime();
    int nbFrames = 0;
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        double currentTime = glfwGetTime();
        nbFrames++;
        if ( currentTime - lastTime >= 1.0 )
        { // If last prinf() was more than 1 sec ago
            // printf and reset timer
            printf("%f ms/frame\n", 1000.0/double(nbFrames));
            nbFrames = 0;
            lastTime += 1.0;
        }
        if(updateViewport)
        {
            glfwGetFramebufferSize(window,&viewportWidth,&viewportHeight);
            glViewport(0,0,viewportWidth,viewportHeight);
            updateViewport = false;
        }
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        glfwSetCursorPosCallback(window, mouseCallback);

        glfwSetKeyCallback(window,Keyboard::keyboardCallback);
        if(Keyboard::isKeyPressed(GLFW_KEY_F5))
        {
            setFullscreen(true);
        }
        if(Keyboard::isKeyPressed(GLFW_KEY_F6))
        {
            setFullscreen(false);
        }
        if(Keyboard::isKeyPressed(GLFW_KEY_ESCAPE))
        {
            destroy();
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        (*renderCallback)();
        glfwSwapBuffers(window);
    }
}
void PFE::Window::destroy()
{
    glfwTerminate();
    exit(0);
}
