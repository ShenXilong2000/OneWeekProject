#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include<iostream>

void write_color(std::ostream& out, color pixel_color) {
	// ����ÿ���@ɫ�����D�Q���ֵ[0, 255]
	out << static_cast<int>(255.99 * pixel_color.x()) << ' '
		<< static_cast<int>(255.99 * pixel_color.y()) << ' '
		<< static_cast<int>(255.99 * pixel_color.z()) << '\n';
}

#endif // !COLOR_H