#include "lab_types.h"
#include "math.h"
#include <iostream>

void IVec3::Print() {
    std::cout << "[" << x << ", " << y << ", " << z << "]" << std::endl;
}

int IVec3::Sum() {
    return x + y + z;
}

int IVec3::Magnitude() {
    return sqrt(x*x + y*y + z*z);
}

void DVec3::Print() {
    std::cout << "[" << x << ", " << y << ", " << z << "]" << std::endl;
}

double DVec3::Sum() {
    return x + y + z;
}

double DVec3::Magnitude() {
    return sqrt(x*x + y*y + z*z);
}