#ifndef RGB_H
#define RGB_H

#include<iostream>
#include<string>
#include "defs.h"

using namespace std;

class RGB {
private:
    int r, g, b;

public:
    // Default constructor
    RGB();

    // Parameterized constructor with validation
    RGB(int r, int g, int b);

    // Getter methods for each color channel
    int getR() const;
    int getG() const;
    int getB() const;

    // Setter methods for each color channel
    void setR(int r);
    void setG(int g);
    void setB(int b);
    
    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();

};

#endif 
