#include <exception>
#include <iostream>

#include "FileScene.h"
#include "Ringo.h"
#include "SceneInterface.h"

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
        Ringo ray_tracer = Ringo();
        SceneInterface scene = FileScene(argv[1]);
        Image image = ray_tracer.render(scene);
        image.write("");
    }
    catch (std::exception& ex) {
        exit_failure(ex.what());
    }
}
