#define _USE_MATH_DEFINES

#include <math.h>
#include "Ray.h"
#include "Ringo.h"


void Ringo::render(const Scene& scene) const {
    manager->new_image();
    double window_y = sqrt(2) * tan(M_PI / 180 * scene.get_camera().get_fov());
    double window_x = manager->get_width() / manager->get_height() * window_y;

    vec3 scaled_u = scene.get_camera().get_u() * window_x;
    vec3 scaled_v = scene.get_camera().get_v() * window_y;

    vec3 scale_p_x = scaled_u * 2 / manager->get_width();
    vec3 scale_p_y = scaled_v * 2 / manager->get_height();

    vec3 constant_term = scaled_u + scaled_v + scene.get_camera().get_n();

    while (Pixel* pixel = manager->get_next_pixel()) {
        vec3 direction = scale_p_x * pixel->x + scale_p_y * pixel->y - constant_term;
        Ray ray = Ray(scene.get_camera().get_look_from(), direction);
        pixel->color = ray.get_color(scene.get_objects(), scene.get_lights());
        manager->draw_pixel(pixel);
    }
}