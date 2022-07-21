#ifndef MATERICAL_H
#define METERICAL_H

#include"rtweekend.h"
#include"hittable.h"

// ���c�����Y��
struct hit_record {
	point3 p;		// ���c
	vec3 normal;	// ����
	shared_ptr<material> mat_ptr;
	double t;		// ���x
	bool front_face;

	inline void set_face_normal(const ray& r, const vec3& outward_normal) {
		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class material {
public:
	virtual bool scatter(
		const ray& r_in, const hit_record& rec, color& attenuatuion, ray& scattered
	) const = 0;
};


class lambertian :public material {
public:
	lambertian(const color& a): albedo(a) {}

	virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
		vec3 scatter_direction = rec.normal + random_unit_vector();
		scattered = ray(rec.p, scatter_direction);
		attenuation = albedo;
		return true;
	}

public:
	color albedo;
};

class metal : public material {
public:
	metal(const color& a):albedo(a) {}
	virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
		vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
		scattered = ray(rec.p, reflected);
		attenuation = albedo;
		return (dot(scattered.direction(), rec.normal) > 0);
	}


public:
	color albedo;
 };

#endif // !MATERICAL_H
