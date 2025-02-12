#include "RGB.h"

RGB::RGB() {
    r = 0;
    g = 0;
    b = 0;
}

RGB::RGB(int r, int g, int b) {
    if (r < 0 || r > 255) {
        cout << "Invalid R value, assigning 0";
        this->r = 0;
    } else {
        this->r = r;
    }
    if (g < 0 || g > 255) {
        cout << "Invalid G value, assigning 0";
        this->g = 0;
    } else {
        this->g = g;
    }
    if (b < 0 || b > 255) {
        cout << "Invalid B value, assigning 0";
        this->b = 0;
    } else {
        this->b = b;
    }
}


int RGB::getR() const{
    return r;
}

int RGB::getG() const{
    return g;
}

int RGB::getB() const{
    return b;
}

void RGB::setR(int r){
    if (r >= 0 && r <= 255) {
        this->r = r;
    } else {
        cout << "Invalid R value\n";
    }
}

void RGB::setG(int g){
    if (g >= 0 && g <= 255) {
        this->g = g;
    } else {
        cout << "Invalid G value\n";
    }
}

void RGB::setB(int b){
    if (b >= 0 && b <= 255) {
        this->b = b;
    } else {
        cout << "Invalid B value\n";
    }
}

RGB RGB::WHITE(){
    return RGB(255,255,255);
}

RGB RGB::BLACK(){
    return RGB(0,0,0);
}

RGB RGB::RED(){
    return RGB(255,0,0);
}

RGB RGB::GREEN(){
    return RGB(0,255,0);
}

RGB RGB::BLUE(){
    return RGB(0,0,255);
}

