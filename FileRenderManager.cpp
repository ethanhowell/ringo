#include "FileRenderManager.h"
#include <stdexcept>

void FileRenderManager::new_image() {
	pixel_queue = new std::queue<Pixel*>();
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			vec3 color = vec3(0, 0, 0);
			image[y][x] = color;
			pixel_queue->push(new Pixel(x, y, color));
		}
	}
}

FileRenderManager::FileRenderManager(int width, int height, const std::string& filename) : width(width), height(height), filename(filename) {
	pixel_queue = nullptr;
	image = std::vector<std::vector<vec3>>(height, std::vector<vec3>(width, vec3(0, 0, 0)));
	// TODO: create some sort of mutex that prevents parallel access
}

Pixel* FileRenderManager::get_next_pixel() {
	if (!pixel_queue)
		throw std::runtime_error("pixel_queue is a NULL pointer");
	if (pixel_queue->size()) {
		Pixel* pixel = pixel_queue->front();
		pixel_queue->pop();
		return pixel;
	}
    return nullptr;
}

void FileRenderManager::draw_pixel(Pixel* pixel) {
	image[pixel->y][pixel->x] = pixel->color;
	delete pixel;
}

FileRenderManager::~FileRenderManager() {
	if (pixel_queue) {
		while (pixel_queue->size()) {
			delete pixel_queue->front();
			pixel_queue->pop();
		}
		delete pixel_queue;
		pixel_queue = nullptr;
	}
}
