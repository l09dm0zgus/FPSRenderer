TEMPLATE = app
win32:contains(QMAKE_HOST.arch, x86):{
QMAKE_LFLAGS *= /MACHINE:X86
}
win32:contains(QMAKE_HOST.arch, x86_64):{
QMAKE_LFLAGS *= /MACHINE:X64
}
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17
CONFIG += sanitizer sanitize_leak
unix:LIBS += -lGLEW  -lglfw -lGL -lX11 -lpthread -lXrandr -lreactphysics3d
win32:LIBS += -lglfw3 -lglew32 -lopengl32 
win32:contains(QMAKE_HOST.arch, x86_64):{
    CONFIG(release, debug|release) {
        win32:LIBS += -lreactphysics3d
    }
    CONFIG(debug, debug|release) {
        win32:LIBS += -lreactphysics3dD
    }
}
SOURCES += \
        engine/camera/camera.cpp \
        engine/components/physicsworldcomponent.cpp \
        engine/components/renderobjectcomponent.cpp \
        engine/components/rigidbodycomponent.cpp \
        engine/gameobject/gameobject.cpp \
        engine/gameobject/scenecreator.cpp \
        engine/input/keyboard.cpp \
        engine/input/mouse.cpp \
        engine/primitives/cube.cpp \
        engine/primitives/sprite.cpp \
        engine/render/animation/animation2d.cpp \
        engine/render/light/lightdata.cpp \
        engine/render/render.cpp \
        engine/render/renderobject.cpp \
        engine/render/shader/shader.cpp \
        engine/render/texture/texture.cpp \
        engine/render/texture/tilesettexture.cpp \
        engine/render/vertices/blockvertices.cpp \
        engine/render/vertices/spritevertices.cpp \
        engine/render/vertices/vertexatrribute.cpp \
        engine/render/vertices/vertexbuffers.cpp \
        engine/render/window.cpp \
        engine/time/time.cpp \
        engine/file/path.cpp \
        engine/transform/transform.cpp \
        main.cpp \
        scripts/enemy.cpp \
        scripts/lightsource.cpp \
        scripts/player.cpp \
        scripts/pointlight.cpp \
        scripts/scenefolder.cpp \
        scripts/spotlight.cpp \
        scripts/wall.cpp


CONFIG += <standard>
HEADERS += \
    engine/camera/camera.h \
    engine/components/IComponent.h \
    engine/components/physicsworldcomponent.h \
    engine/components/renderobjectcomponent.h \
    engine/components/rigidbodycomponent.h \
    engine/gameobject/gameobject.h \
    engine/gameobject/scenecreator.h \
    engine/input/keyboard.h \
    engine/input/mouse.h \
    engine/primitives/cube.h \
    engine/primitives/sprite.h \
    engine/render/animation/animation2d.h \
    engine/render/animation/animator.h \
    engine/render/light/lightdata.h \
    engine/render/render.h \
    engine/render/renderobject.h \
    engine/render/shader/shader.h \
    engine/render/texture/texture.h \
    engine/render/texture/tilesettexture.h \
    engine/render/vertices/IVertices.h \
    engine/render/vertices/blockvertices.h \
    engine/render/vertices/spritevertices.h \
    engine/render/vertices/vertexatrribute.h \
    engine/render/vertices/vertexbuffers.h \
    engine/render/window.h \
    engine/time/time.h \
    engine/file/path.h \
    engine/transform/transform.h \
    libs/ini.h \
    libs/stb_image.h \
    libs/vectorsconventers.h \
    scripts/character.h \
    scripts/enemy.h \
    scripts/lightsource.h \
    scripts/player.h \
    scripts/pointlight.h \
    scripts/scenefolder.h \
    scripts/spotlight.h \
    scripts/wall.h

#unix|win32: LIBS += -lreactphysics3d
unix|win32: INCLUDEPATH += $$PWD/libs/glm

DISTFILES += \
    PureFuckingArmaggedon.sln \
    PureFuckingArmaggedon.vcxproj \
    PureFuckingArmaggedon.vcxproj.filters \
    README.md \
    libs/LICENSE
