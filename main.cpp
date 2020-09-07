#include <iostream>
#include "window.h"
#include "render.h"
using namespace PFE;
int main()
{
    Window app(800,600,"Pure Fucking Armaggedon");
    app.render();
    app.destroy();
    return 0;
}

