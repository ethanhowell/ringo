#pragma once

#include <vector>

#include "IRenderManager.h"
#include "SceneInterface.h"

class Ringo {
private:
	IRenderManager* manager;

public:
	Ringo(IRenderManager* manager) : manager(manager) {}

	void render(SceneInterface* scene) const;
};

