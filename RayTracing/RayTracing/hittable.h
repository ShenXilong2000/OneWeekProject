#ifndef HITTABLE_H
#define HITTABLE_H

#include"ray.h"

struct hit_record
{
	point3 p;		// 交點
	vec3 normal;	// 法線向量
	double t;		// 距離
};

class hittable
{
public:
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif // !HITTABLE_H
