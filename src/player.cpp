#include <Player.hpp>
#include "Math.hpp"

Player::Player(Window* window) {
    texture = Texture("res/player.png",window);

    model = Model(0-50, 0-50, 100.0f, 100.0f,window->width,window->height);
    imageData = squareTexture(&model);

    ubo.model = glm::mat4(1.0f);
    ubo.view = glm::mat4(1.0f);
    ubo.proj = glm::mat4(1.0f);

    entity = Entity(model,imageData,&texture,window);
}

void Player::draw(Window* window) {
    entity.draw(&ubo,window);
}

void Player::destroy(Window* window) {
    entity.cleanUp(window);
    texture.cleanUp(window);

}