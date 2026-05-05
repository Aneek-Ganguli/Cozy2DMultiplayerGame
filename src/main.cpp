#include <iostream>
#include <Window.hpp>


int main() {
    Window window("Cozy 2D Multiplayer Game",800,600);

    while (window.isWindowOpen()) {
        window.pollEvents();

        window.startFrame();


        window.endFrame();

    }

    window.cleanUp();
    return 0;
}