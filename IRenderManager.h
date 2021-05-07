#pragma once

#include "Pixel.h"
#include <vector>

class IRenderManager {
public:
	virtual Pixel* get_next_pixel() = 0;
	virtual void draw_pixel(Pixel* pixel) = 0;
	virtual void new_image() = 0;
	virtual const std::vector<std::vector<vec3>>& get_image() const = 0;
	virtual int get_width() = 0;
	virtual int get_height() = 0;
	virtual ~IRenderManager() {}
};

