#pragma once

#include "Camera.h"
#include "ILight.h"
#include "Triangle.h"
#include <vector>

class Scene {
public:
	Camera get_camera() const;
	const std::vector<Triangle*>& get_objects() const;
	const std::vector<ILight*>& get_lights() const;
};

