#ifndef RAY_H
#define RAY_H

#include"vec3.h"


// 光纖 假象成 一個點加上一個方向的衍生
class ray {
public:
	ray() {}
	ray(const point3& origin, const vec3& direction) :orig(origin), dir(direction) {}

	point3 origin() const { return orig; };
	vec3 direction() const { return dir; };

	point3 at(double t) const {
		return orig + t * dir;
	}

public:
	point3 orig;
	vec3 dir;
};

#endif // !RAY_H
