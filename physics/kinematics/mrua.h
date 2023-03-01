#include <math.h>
using namespace std;

namespace fkphy{

// Movement equation: x = x0 + v0*t + 1/2*a^2
float mruaMov(float x0, float t, float v0, float a){
    return x0 + v0*t + .5*a*t*t;
}

// Velocity equation: vf = v0 + a*t
float mruaVel(float t, float v0, float a){
    return v0 + a*t;
}

// Quadratic equation: vf^2 = v0^2 + 2*a*x
float mruaQua(float x, float v0, float a){
    return sqrt(v0*v0 + 2*x*a);
}

}