#include "render.h"
PFE::Render& PFE::Render::createRender()
{
    static Render instance;
    return instance;
}
void PFE::Render::load(string mapName)
{
    sceneCreator.create(mapName);
    scene = sceneCreator.getSceneGraph();
}

void PFE::Render::setViewportSize(glm::vec2 viewportSize)
{
    this->viewportSize = viewportSize;
}
void PFE::Render::render()
{

    scene->render(sceneCreator.getCameraView(),viewportSize);
}
void PFE::Render::clear()
{
    delete scene;
    scene = 0;
}