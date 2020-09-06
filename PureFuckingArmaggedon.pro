TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17
CONFIG += sanitizer sanitize_leak
LIBS += -lGLEW -lSOIL  -lglfw -lGL -lX11 -lpthread -lXrandr
SOURCES += \
        animation2d.cpp \
        block.cpp \
        blockvertices.cpp \
        camera.cpp \
        keyboard.cpp \
        main.cpp \
        mouse.cpp \
        render.cpp \
        renderobject.cpp \
        scene.cpp \
        shader.cpp \
        sprite.cpp \
        spritevertices.cpp \
        texture.cpp \
        tilesettexture.cpp \
        transform.cpp \
        vertexatrribute.cpp \
        vertexbuffers.cpp \
        window.cpp


CONFIG += <standard>
HEADERS += \
    IVertices.h \
    animation2d.h \
    animator.h \
    block.h \
    blockvertices.h \
    camera.h \
    keyboard.h \
    libs/ini.h \
    mouse.h \
    render.h \
    renderobject.h \
    scene.h \
    shader.h \
    sprite.h \
    spritevertices.h \
    texture.h \
    tilesettexture.h \
    transform.h \
    vertexatrribute.h \
    vertexbuffers.h \
    window.h

#unix|win32: LIBS += -lreactphysics3d
unix|win32: INCLUDEPATH += $$PWD/libs/glm
DISTFILES += \
    libs/glm/glm/CMakeLists.txt
