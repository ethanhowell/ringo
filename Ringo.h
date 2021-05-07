#pragma once

#include "IRenderManager.h"
#include "Scene.h"
#include <vector>

class Ringo {
private:
	IRenderManager* manager;

public:
	Ringo(IRenderManager* manager) : manager(manager) {}

	void render(const Scene& scene) const;
};

