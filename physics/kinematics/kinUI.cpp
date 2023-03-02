// File to calculate 1-dimension rectilinear movement accelerated.
#include <iostream>
#include <vector>
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
    float x, y, t, vx, vy, a, g;   // Using x as x0 and Δx since there's not the necessity of having more than one. If necessary add more variables.
    string in;
    cin >> in;
    cout << endl;

    if(in == "help"){
        cout << "mov | m - Movement equation (x = x0 + v0*t + 1/2*a^2)" << endl;
        cout << "vel | v - Velocity equations (vf = v0 + a*t) | (vf^2 = v0^2 + 2*a*Δx)" << endl;
        cout << "par | p - Parabolic movement. Enter the gravity in positive" << endl;
        cout << endl;
        kinUI();
    }
    else if(in == "mov" or in == "m"){
        cout << "x0: "; cin >> x;
        cout << "t: "; cin >> t;
        cout << "v0: "; cin >> vx;
        cout << "a: "; cin >> a;

        cout << endl << "x: " << fkphy::d1Mov(x, t, vx, a) << "m" << endl;
    }
    else if(in == "vel" or in == "v"){
        cout << "v0: "; cin >> vx;
        cout << "a: "; cin >> a;
        cin.ignore();   // Used because the program was skipping next cin
        cout << "t: "; t = isEnter();   // Optional value
        cout << "x|Δx: "; x = isEnter();    // Optional value

        if(t != '\0') cout << endl << "vf: " << fkphy::d1Vel(t, vx, a) << "m/s" << endl;
        else if(x != '\0') cout << endl << "vf: " << fkphy::d1Qua(x, vx, a) << "m/s" << endl;
        else cout << "You must provide t or x" << endl;
    }
    else if(in == "par" or in == "p"){
        cout << "x0: "; cin >> x;
        cout << "y0: "; cin >> y;
        cout << "vx0: "; cin >> vx;
        cout << "vy0: "; cin >> vy;
        cout << "a: "; cin >> a;
        cout << "g: "; cin >> g;
        cout << "t: "; cin >> t;

        array<float, 2> result = fkphy::d2Par(x, y, vx, vy, a, g, t);
        cout << "x: " << result[0] << "m" << endl;
        cout << "y: " << result[1] << "m" << endl;
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