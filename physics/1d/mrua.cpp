// File to calculate 1-dimension rectilinear movement accelerated.
#include <iostream>
#include <math.h>
using namespace std;

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

// Execute the function preferred by the user
void mruaUI(){
    float x0, x, t, v, a;
    string in;
    cin >> in;
    cout << endl;

    if(in == "help"){
        cout << "mov | m - Movement equation (x = x0 + v0*t + 1/2*a^2)" << endl;
        cout << "vel | v - Velocity equation (vf = v0 + a*t)" << endl;
        cout << "qua | q - Quadratic equation (vf^2 = v0^2 + 2*a*x)" << endl << endl;
        mruaUI();
    }
    else if(in == "mov" or in == "m"){
        cout << "x0: "; cin >> x0;
        cout << "t: "; cin >> t;
        cout << "v0: "; cin >> v;
        cout << "a: "; cin >> a;

        cout << endl << "x: " << mruaMov(x0, t, v, a) << "m" << endl;
    }
    else if(in == "vel" or in == "v"){
        cout << "v0: "; cin >> v;
        cout << "a: "; cin >> a;
        cout << "t: "; cin >> t;

        cout << endl << "vf: " << mruaVel(t, v, a) << "m/s" << endl;
    }
    else if(in == "qua" or in == "q"){
        cout << "v0: "; cin >> v;
        cout << "a: "; cin >> a;
        cout << "x: "; cin >> x0;

        cout << endl << "vf: " << mruaQua(x0, v, a) << "m/s" << endl;
    }
    else{   // In case the user doesn't write any possibility
        cout << "Please type a valid command. If you need to see them type 'help'" << endl;
        mruaUI();
    }
}

int main(){
    cout << "To see the comands type 'help'. Enter the data in the SI." << endl;
    mruaUI();
}