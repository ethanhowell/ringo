#pragma once

#include <string>

#include "IRenderManager.h"

class FileRenderManager: public IRenderManager {
private:
	int width, height;
	std::string filename;

public:
	FileRenderManager(int width, int height, const std::string& filename) : width(width), height(height), filename(filename) {
		// TODO: construct the image array that will store pixel values, as well as some sort of queue or mutex that prevents parallel access
	}

	Pixel get_next_pixel() override;
	void draw_pixel(const Pixel& pixel) override;

	int get_width() { return width; }
	int get_height() { return height; }
};

