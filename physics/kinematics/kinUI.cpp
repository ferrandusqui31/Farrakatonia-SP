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

// Standard message for unexpected values (except when asks for a number).
// When the program asks for a number and any other thing is given it just crashes.
void error(){
    cout << "Please enter a valid value. If you need help type 'help'." << endl;
    cout << "Y/n => Yes/No" << endl;
    kinUI();
}

// Execute the function preferred by the user
void kinUI(){
    string in;
    cin >> in;
    cout << endl;

    if(in == "help"){
        cout << "mov | m - Linear movement (x = x0 + v0*t + 1/2*a*t^2)" << endl;
        cout << "vel | v - Linear movement velocity (v = v0 + a*t) | (v^2 = v0^2 + 2*a*Δx). t and Δx are optional (1 between both)." << endl;
        cout << "par | p - Parabolic movement. Enter the gravity in positive" << endl;
        cout << "cir | c - Circular movement (φ = φ0 + ω0*t + 1/2*α*t^2)" << endl;
        cout << "cvel | cv - Circular movement velocity (ω = ω0 + αt) | (ω^2 = ω0^2 + 2*α*Δφ). t and Δφ are optional (1 between both)." << endl;
        cout << "cl - Switch from circular to linear units and vice versa" << endl;
        cout << "an - Normal acceleration formulas (an = ω^2*R) | (an = v^2/R)" << endl;
        cout << endl;
        kinUI();
    }
    else if(in == "mov" or in == "m"){  // Movement equation
        float x0,t,v0,a;
        cout << "x0: "; cin >> x0;
        cout << "t: "; cin >> t;
        cout << "v0: "; cin >> v0;
        cout << "a: "; cin >> a;

        cout << endl << "x: " << fkPhy::d1Mov(x0, t, v0, a) << "m" << endl;
    }
    else if(in == "vel" or in == "v"){  // Velocity equations
        float v0,a,t,x;
        cout << "v0: "; cin >> v0;
        cout << "a: "; cin >> a;
        cin.ignore();   // Used because the program was skipping next cin
        cout << "t: "; t = isEnter();   // Optional value
        cout << "x|Δx: "; x = isEnter();    // Optional value

        if(t != '\0') cout << endl << "v: " << fkPhy::d1Vel(t, v0, a) << "m/s" << endl;    // Selects between both formulas
        else if(x != '\0') cout << endl << "v: " << fkPhy::d1Qua(x, v0, a) << "m/s" << endl;
        else cout << "You must provide t or x" << endl;
    }
    else if(in == "par" or in == "p"){  // Parabolic movement
        float x0,y0,vx,vy,a,g,t;
        cout << "x0: "; cin >> x0;
        cout << "y0: "; cin >> y0;
        cout << "vx0: "; cin >> vx;
        cout << "vy0: "; cin >> vy;
        cout << "a: "; cin >> a;
        cout << "g: "; cin >> g;
        cout << "t: "; cin >> t;

        array<float, 2> result = fkPhy::d2Par(x0, y0, vx, vy, a, g, t);
        cout << endl << "x: " << result[0] << "m" << endl;
        cout << "y: " << result[1] << "m" << endl;
    }
    else if(in == "cir" or in == "c"){  // Circular movement
        float phi,w0,t,alph;
        cout << "φ0: "; cin >> phi;
        cout << "t: "; cin >> t;
        cout << "ω0: "; cin >> w0;
        cout << "α: "; cin >> alph;
        
        cout << endl << fkPhy::d1Mov(phi, t, w0, alph) << "rad" << endl;
    }
    else if(in == "cvel" or in == "cv"){    // Use circular movement velocity formulas (same as linear but different units)
        float w0,a,t,x;
        cout << "ω0: "; cin >> w0;
        cout << "α: "; cin >> a;
        cin.ignore();   // Used because the program was skipping next cin
        cout << "t: "; t = isEnter();   // Optional value
        cout << "φ|Δφ: "; x = isEnter();    // Optional value

        if(t != '\0') cout << endl << "ω: " << fkPhy::d1Vel(t, w0, a) << "rad/s" << endl;    // Selects between both formulas
        else if(x != '\0') cout << endl << "ω: " << fkPhy::d1Qua(x, w0, a) << "rad/s" << endl;
        else cout << "You must provide t or φ" << endl;
    }
    else if(in == "cl"){    // To use fkPhy::d2CirLin() function
        string reverse;
        float par,r;
        cout << "Reverse mode? (Y/n): "; cin >> reverse;

        if(reverse == "n" or reverse == "N"){
            cout << "φ | ω | α: "; cin >> par;
            cout << "R: "; cin >> r;
            cout << fkPhy::d2CirLin(false, par, r) << endl;
        }
        else if(reverse == "y" or reverse == "Y"){
            cout << "s | v | at: "; cin >> par;
            cout << "R: "; cin >> r;
            cout << fkPhy::d2CirLin(true, par, r) << endl;
        }
        else{
            error();
        }
    }
    else if(in == "an"){
        string linear, reverse;
        float par,r;

        cout << "Using linear or circular velocity? (Y/n): "; cin >> linear;
        cout << "Reverse mode? (Y/n): "; cin >> reverse;
        if((reverse == "n" || reverse == "N") && (linear == "N" || linear == "n")){
            cout << "ω: "; cin >> par;
            cout << "R: "; cin >> r;
            cout << fkPhy::d2NA(false, false, par, r) << "m/s^2" << endl;
        }
        else if((reverse == "y" || reverse == "Y") && (linear == "N" || linear == "n")){
            cout << "an: "; cin >> par;
            cout << "R: "; cin >> r;
            cout << fkPhy::d2NA(true, false, par, r) << "rad/s" << endl;
        }
        else if((reverse == "n" || reverse == "N") && (linear == "Y" || linear == "y")){
            cout << "v: "; cin >> par;
            cout << "R: "; cin >> r;
            cout << fkPhy::d2NA(false, true, par, r) << "m/s^2" << endl;
        }
        else if((reverse == "y" || reverse == "Y") && (linear == "Y" || linear == "y")){
            cout << "an: "; cin >> par;
            cout << "R: "; cin >> r;
            cout << fkPhy::d2NA(true, true, par, r) << "m/s" << endl;
        }
        else{
            error();
        }
    }


    else{   // In case the user doesn't write any possibility
        error();
    }
}

int main(){
    cout << "To see the comands type 'help'. Enter the data in the SI." << endl;
    kinUI();
}