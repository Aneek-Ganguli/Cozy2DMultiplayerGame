#pragma once
#include <Entity.hpp>
#include <Math.hpp>
#include <Texture.hpp>
#include <UBO.hpp>

class Player {
public:
    Player(Window* window);//custom

    void draw(Window* window);

    void destroy(Window* window);

private:
    Entity entity{};
    UBO ubo{};
    Model model{};
    Texture texture{};
    std::vector<ImageData> imageData{};
};
