#include <Entity.hpp>
#include <iostream>
#include <Texture.hpp>
#include <Window.hpp>

#include <glm/gtc/matrix_transform.hpp>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>


void updateUniformBuffer(UBO& ubo, float time, float aspectRatio) {
    ubo.model = glm::rotate(glm::mat4(1.0f), time * glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 1.0f));

    ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, 4.0f), // Moved camera to see the cube better
                          glm::vec3(0.0f, 0.0f, 0.0f),
                          glm::vec3(0.0f, 1.0f, 0.0f));

    ubo.proj = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 10.0f);

    // VULKAN HIDDEN TRAP: GLM was designed for OpenGL where Y is UP.
    // Vulkan Y is DOWN. This flip is required unless you use a negative viewport.
    ubo.proj[1][1] *= -1;
}



int main() {
    Window window("Cozy 2D Multiplayer Game",800,600);
    Texture texture;
    Model model(0-50, 0-50, 100.0f, 100.0f,window.width,window.height);
    std::vector<ImageData> imageData = solidColor(&model, {1.0f, 0.0f, 0.0f});
    Entity entity(model,imageData,&texture,&window);

    UBO ubo{};
    ubo.model = glm::mat4(1.0f);
    ubo.view = glm::mat4(1.0f);
    ubo.proj = glm::mat4(1.0f);

    while (window.isWindowOpen()) {
        window.pollEvents();

        window.startFrame();

        entity.draw(&ubo,&window);

        window.endFrame();

    }

    texture.cleanUp(&window);
    entity.cleanUp(&window);
    window.cleanUp();
    return 0;
}