#ifndef SPHERE_H
#define SPHERE_H

#include"hittable.h"
#include"vec3.h"

class sphere :public hittable {
public:
	sphere(){}
	sphere(point3 cen, double r) :center(cen), radius(r){}

	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:
	point3 center;
	double radius;
};

// 判斷光纖是否與某個球相交
// 根據推導求得 最終公式為 一元二次函數 A為光纖原點， C為球的原點
// t^2 * dot(b, b) + 2t* dot(b, (A-C)) + dot((A-C), (A-C)) - r^2 = 0
// 求b^2 - 4ac > 0
// 無解返回-1.0， 有解返回解，優先返回小的解

// 令b = 2 * h ,即可进一步化简求根公式。
bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
	vec3 oc = r.origin() - center;
	double a = dot(r.direction(), r.direction());	// dot(b, b)
	double half_b = dot(r.direction(), oc);
	double c = dot(oc, oc) - radius * radius;
	double discriminant = half_b * half_b - a * c;
	if (discriminant > 0) {
		double root = sqrt(discriminant);
		double t = (-half_b - root) / a;
		if (t > t_min && t < t_max) {
			rec.t = t;
			rec.p = r.at(t);
			vec3 outward_normal = (rec.p - center) / radius;
			rec.set_face_normal(r, outward_normal);
			return true;
		}

		t = (-half_b + root) / a;
		if (t > t_min && t < t_max) {
			rec.t = t;
			rec.p = r.at(t);
			vec3 outward_normal = (rec.p - center) / radius;
			rec.set_face_normal(r, outward_normal);
			return true;
		}
	}
	return false;
}

#endif // !SPHERE_H
