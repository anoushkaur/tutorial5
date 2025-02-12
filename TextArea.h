#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <string>
#include <iostream>
#include <iomanip>
#include "RGB.h"
#include <X11/Xlib.h>
#include "defs.h"

class TextArea {
private:
    Rectangle dimensions;   
    string text; 
    string id;   
    RGB fill;        
    RGB border;       

public:

    TextArea();

    TextArea(const TextArea& other);

    TextArea(int x, int y, int width, int height, const string& id, const string& label, 
             const RGB& fill = RGB(255, 255, 255), const RGB& border = RGB(0, 0, 0));


    TextArea(const Rectangle& rect, const string& id, const string& label, 
             const RGB& fill = RGB(255, 255, 255), const RGB& border = RGB(0, 0, 0));

    
    Rectangle getRectangle() const;
    std::string getText() const;
    std::string getId() const;
    RGB getFill() const;
    RGB getBorder() const;

    
    void setRectangle(const Rectangle& rect);
    void setText(const std::string& text);
    void setId(const std::string& id);
    void setFill(const RGB& fill);
    void setBorder(const RGB& border);

    
    void draw(Display* display, Window win, GC gc, int x, int y);

    
    bool overlaps(const TextArea& ta) const;

    
    void print() const;
};

#endif 
