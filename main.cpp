#include <iostream>
#include "engine/render/window.h"
#include "engine/render/render.h"
using namespace PFE;
int main()
{
    Window app(800,600,"Pure Fucking Armaggedon");
    app.render();
    app.destroy();
    return 0;
}

