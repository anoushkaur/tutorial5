#include "TextArea.h"

TextArea::TextArea() 
    : id(""), text(""), fill(RGB(255, 255, 255)), border(RGB(0, 0, 0)) {
    dimensions.x = 0;
    dimensions.y = 0;
    dimensions.width = 0;
    dimensions.height = 0;
}

TextArea::TextArea(int x, int y, int width, int height, const std::string& id, const std::string& label, 
                   const RGB& fill, const RGB& border)  
    : id(id), fill(fill), border(border), text(label) {
    dimensions.x = x;
    dimensions.y = y;
    dimensions.width = width;
    dimensions.height = height;
}

TextArea::TextArea(const Rectangle& rect, const std::string& id, const std::string& label, 
                   const RGB& fill, const RGB& border)  
    : dimensions(rect), id(id), fill(fill), border(border), text(label) {}

TextArea::TextArea(const TextArea& other) 
    : dimensions(other.dimensions), id(other.id), fill(other.fill), border(other.border) {
    text = "DUPLICATE";
}

Rectangle TextArea::getRectangle() const { return dimensions; }
std::string TextArea::getText() const { return text; }
std::string TextArea::getId() const { return id; }
RGB TextArea::getFill() const { return fill; }
RGB TextArea::getBorder() const { return border; }

void TextArea::setRectangle(const Rectangle& rect) { dimensions = rect; }
void TextArea::setText(const std::string& newText) { text = newText; }
void TextArea::setId(const std::string& newId) { id = newId; }
void TextArea::setFill(const RGB& newFill) { fill = newFill; }
void TextArea::setBorder(const RGB& newBorder) { border = newBorder; }

void TextArea::draw(Display *display, Window win, GC gc, int x, int y) {
    XFillRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);
    XDrawString(display, win, gc, x, y + dimensions.height, text.c_str(), text.length());
}

bool TextArea::overlaps(const TextArea& ta) const {
    return dimensions.overlaps(ta.dimensions);
}

void TextArea::print() const {
    std::cout << "TextArea id: " << id << std::endl;
    std::cout << "Preferred location: " << dimensions.x << ", " << dimensions.y << std::endl;
    std::cout << "Size: " << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Text: " << text << std::endl;
}

// Inside TextArea class
bool TextArea::equals(const string& id) const {
    // Assuming the TextArea has an id member
    return this->id == id;
}

