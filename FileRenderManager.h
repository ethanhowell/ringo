#pragma once

#include "IRenderManager.h"
#include <queue>
#include <string>

class FileRenderManager: public IRenderManager {
private:
	int width, height;
	std::string filename;
	std::queue<Pixel*>* pixel_queue;
	std::vector<std::vector<vec3>> image;

public:
	FileRenderManager(int width, int height, const std::string& filename);

	Pixel* get_next_pixel() override;
	void draw_pixel(Pixel* pixel) override;

	void new_image() override;
	const std::vector<std::vector<vec3>>& get_image() const override { return image; }

	int get_width() override { return width; }
	int get_height() override { return height; }

	~FileRenderManager();
};

