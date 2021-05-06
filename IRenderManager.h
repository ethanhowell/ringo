#pragma once

#include "Pixel.h"

class IRenderManager {
public:
	virtual Pixel get_next_pixel() = 0;
	virtual void draw_pixel(const Pixel& pixel) = 0;
	virtual int get_width() = 0;
	virtual int get_height() = 0;
	virtual ~IRenderManager() {}
};

