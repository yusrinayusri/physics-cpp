/*
* Kinematics - Motion of the Plane 
* The trajectory of a particle moving on a circle with constant angular velocity
* > g++ circle.cpp -o circle
* > ./circle < circle.in > circle.out
*/

#include <__memory/temporary_buffer.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdlib.h>
#include <string>
#include <cmath>

// define constant PI
#define PI 3.1415926535897932

int main() {

    // declaring variables
    double xO, yO; //center of circle
    double R; //radius of circle
    double x, y; //current position of particle
    double vx, vy; //velocity of particle
    double t, tO, tf, dt; //times variables
    double theta, omega; //theta = angle; omega = angular velocity

    std::string buf; //string declaration for buffer

    // user interface to get values
    std::cout << "## Enter Omega (w) value: \n";
    std::cin >> omega; 
    std::getline(std::cin, buf);

    std::cout << "## Enter centre of circle (xO,yO) and circle's radius, R value: \n";
    std::cin >> xO >> yO >> R;
    std::getline(std::cin, buf);

    std::cout << "## Enter time variables, tO(initial time), tf(final time), dt(delta time): \n";
    std::cin >> tO >> tf >> dt;
    std::getline(std::cin, buf);

    // verify the inputs
    std::cout << "Verify the inputs: \n";
    std::cout << "omega = " << omega << std::endl;
    std::cout << "xO = " << xO << " yO = " << yO  
              << " R = " << R << std::endl;
    std::cout << "tO = " << tO << " tf = " << tf 
              << " dt = " << dt << std::endl;

    // verification value of circle radius and omega  
    if (R <= 0.0) {
        std::cerr << "Illegal value of R \n";
        exit(1);
    }

    if (omega <= 0.0) {
        std::cerr << "Illegal value of omega \n";
        exit(1);
    }

    // cout the T value
    std::cout << "# T =  " << 2.0*PI/omega << std::endl;

    // parse values into file circle.dat
    std::ofstream myfile("Circle.dat");
    myfile.precision(17);

    // main calculation
    // loop to prevent unnecessary infinite loop or immature loop
    t = tO;
    while (t <= tf) {
        theta = omega * (t - tO);
        x = xO + R * cos(theta);
        y = yO + R * sin(theta);
        vx = -omega * R * sin(theta);
        vy = omega * R * cos(theta);

        myfile << t << " " 
            << x << " " << y << " "
            << vx << " " << vy << " " << std::endl;
        t = t + dt;
    }

    return 0;
}




