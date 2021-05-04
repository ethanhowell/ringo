#pragma once

#include <string>

#include "SceneInterface.h"

class FileScene: public SceneInterface {
public:
	FileScene(char* filename);
};

