#include <Entity.hpp>
#include <iostream>
#include <Texture.hpp>
#include <Window.hpp>

#include <glm/gtc/matrix_transform.hpp>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

#include "Player.hpp"


int main() {
    Window window("Cozy 2D Multiplayer Game",800,600);


    Player player(&window);


    while (window.isWindowOpen()) {
        window.pollEvents();

        window.startFrame();

        player.draw(&window);

        window.endFrame();

    }

    player.destroy(&window);


    window.cleanUp();
    return 0;
}
