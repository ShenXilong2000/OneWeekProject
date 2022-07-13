#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include<cmath>
#include<cstdlib>
#include<limits>
#include<memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// 常量
const double infinity = std::numeric_limits<double>::infinity();	//無窮大
const double pi = 3.1415926535897932385;

// 函數
inline double degrees_to_radians(double degrees) {	// 度數到弧度
	return degrees * pi / 180.0;
}

// 公共頭文件
#include"ray.h"
#include"vec3.h"

#endif // !RTWEEKEND_H
