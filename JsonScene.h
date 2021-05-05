#pragma once

#include <string>

#include "SceneInterface.h"

class JsonScene: public SceneInterface {
public:
	JsonScene(char* filename);
};

