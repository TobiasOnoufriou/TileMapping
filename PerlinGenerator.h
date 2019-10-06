#pragma once
#include "SFML\Graphics.hpp"

class PerlinGenerator {
public:
	float fade(float t) {
		return t*t*t*(t*(t*6.0 - 15.0) + 10.0);
	}
	float grad(float p) {
		const float texture_width = 256.0;
		float v = p / texture_width;
		return v > 0.5 ? 1.0 : -1.0;
	}
	float noise(float p) {
		float p0 = floor(p);
		float p1 = p0 + 1.0;

		float t = p - p0;
		float fade_t = fade(t);

		float g0 = grad(p0);
		float g1 = grad(p1);

		return (1.0 - fade_t)*g0*(p - p0) + fade_t * g1 * (p - p1);
	}

private:
};