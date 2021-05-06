#include <exception>
#include <iostream>

#include "FileRenderManager.h"
#include "JsonScene.h"
#include "Ringo.h"

void exit_failure(const char* message) {
    std::cerr << message << std::endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    // Expects command line arguments of the form 
    // ringo path-to-scene-json
    if (argc != 2)
        exit_failure("Please provide exactly one argument that is a valid path to a scene file.");
 
    try {
        FileRenderManager manager = FileRenderManager(500, 500, "test.png");
        Ringo ray_tracer = Ringo(&manager);
        JsonScene scene = JsonScene(argv[1]);
        ray_tracer.render(&scene);
    }
    catch (std::exception& ex) {
        exit_failure(ex.what());
    }
}
