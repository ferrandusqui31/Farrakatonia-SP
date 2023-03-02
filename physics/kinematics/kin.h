#include <math.h>
using namespace std;

namespace fkphy{

// Straight line movement
// Movement equation: x = x0 + v0*t + 1/2*a^2
float d1Mov(float x0, float t, float v0, float a){
    return x0 + v0*t + .5*a*t*t;
}

// Velocity equation: vf = v0 + a*t
float d1Vel(float t, float v0, float a){
    return v0 + a*t;
}

// Quadratic equation: vf^2 = v0^2 + 2*a*x
float d1Qua(float x, float v0, float a){
    return sqrt(v0*v0 + 2*x*a);
}

}