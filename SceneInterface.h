#pragma once

#include "Camera.h"
#include "Triangle.h"
#include "LightInterface.h"
#include <vector>

class SceneInterface {
public:
	virtual Camera get_camera() const = 0;
	virtual const std::vector<Triangle*>& get_objects() const = 0;
	virtual const std::vector<LightInterface*>& get_lights() const = 0;
};

