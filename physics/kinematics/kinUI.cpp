// File to calculate 1-dimension rectilinear movement accelerated.
#include <iostream>
#include "kin.h"
using namespace std;

// Function for the values that can be skipped
float isEnter(){
    string input;
    getline(cin, input);    // Way to get inputs but can get ENTER
    if(input == "") return '\0';    // '\0' is equivalent to NULL
    else return stof(input);
}

// Execute the function preferred by the user
void kinUI(){
    string in;
    cin >> in;
    cout << endl;

    if(in == "help"){
        cout << "mov | m - Linear movement (x = x0 + v0*t + 1/2*a*t^2)" << endl;
        cout << "vel | v - Linear movement velocity (vf = v0 + a*t) | (vf^2 = v0^2 + 2*a*Δx). t and Δx are optional (1 between both)." << endl;
        cout << "par | p - Parabolic movement. Enter the gravity in positive" << endl;
        cout << "cir | c - Circular movement (φ = φ0 + ω0*t + 1/2*α*t^2)" << endl;
        cout << endl;
        kinUI();
    }
    else if(in == "mov" or in == "m"){
        float x0,t,v0,a;
        cout << "x0: "; cin >> x0;
        cout << "t: "; cin >> t;
        cout << "v0: "; cin >> v0;
        cout << "a: "; cin >> a;

        cout << endl << "x: " << fkphy::d1Mov(x0, t, v0, a) << "m" << endl;
    }
    else if(in == "vel" or in == "v"){
        float v0,a,t,x;
        cout << "v0: "; cin >> v0;
        cout << "a: "; cin >> a;
        cin.ignore();   // Used because the program was skipping next cin
        cout << "t: "; t = isEnter();   // Optional value
        cout << "x|Δx: "; x = isEnter();    // Optional value

        if(t != '\0') cout << endl << "vf: " << fkphy::d1Vel(t, v0, a) << "m/s" << endl;    // Selects between voth formulas
        else if(x != '\0') cout << endl << "vf: " << fkphy::d1Qua(x, v0, a) << "m/s" << endl;
        else cout << "You must provide t or x" << endl;
    }
    else if(in == "par" or in == "p"){
        float x0,y0,vx,vy,a,g,t;
        cout << "x0: "; cin >> x0;
        cout << "y0: "; cin >> y0;
        cout << "vx0: "; cin >> vx;
        cout << "vy0: "; cin >> vy;
        cout << "a: "; cin >> a;
        cout << "g: "; cin >> g;
        cout << "t: "; cin >> t;

        array<float, 2> result = fkphy::d2Par(x0, y0, vx, vy, a, g, t);
        cout << endl << "x: " << result[0] << "m" << endl;
        cout << "y: " << result[1] << "m" << endl;
    }
    else if(in == "cir" or in == "c"){
        float phi,w0,t,alph;
        cout << "φ0: "; cin >> phi;
        cout << "ω0: "; cin >> w0;
        cout << "t: "; cin >> t;
        cout << "α: "; cin >> alph;
        
        cout << endl << fkphy::d2Cir(phi, w0, t, alph) << "rad" << endl;
    }
    else{   // In case the user doesn't write any possibility
        cout << "Please type a valid command. If you need to see them type 'help'" << endl;
        kinUI();
    }
}

int main(){
    cout << "To see the comands type 'help'. Enter the data in the SI." << endl;
    kinUI();
}