TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17
CONFIG += sanitizer sanitize_leak
LIBS += -lGLEW -lSOIL  -lglfw -lGL -lX11 -lpthread -lXrandr
SOURCES += \
        animation2d.cpp \
        blockvertices.cpp \
        camera.cpp \
        cube.cpp \
        gameobject.cpp \
        keyboard.cpp \
        main.cpp \
        mouse.cpp \
        render.cpp \
        renderobject.cpp \
        scenecreator.cpp \
        scripts/enemy.cpp \
        scripts/player.cpp \
        scripts/scenefolder.cpp \
        scripts/wall.cpp \
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
    blockvertices.h \
    camera.h \
    cube.h \
    gameobject.h \
    keyboard.h \
    libs/ini.h \
    mouse.h \
    render.h \
    renderobject.h \
    scenecreator.h \
    scripts/enemy.h \
    scripts/player.h \
    scripts/scenefolder.h \
    scripts/wall.h \
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
