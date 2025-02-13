#include "TAArray.h"
#include <iostream>
#include <stdexcept>

TAArray::TAArray() {
    size = 0;
    arr = new TextArea*[MAX_ARR];
}

TAArray::~TAArray() {
    delete[] arr;
}

bool TAArray::add(TextArea* t) {
    if (size >= MAX_ARR) return false;

    arr[size++] = t;
    return true;
}

bool TAArray::add(TextArea* t, int index) {
    if (size >= MAX_ARR || index < 0 || index > size) {
        return false;  // Invalid index or array full
    }

    // Shift elements to the right to make space
    for (int i = size; i > index; --i) {
        arr[i] = arr[i - 1];
    }

    // Insert the new TextArea pointer at the specified index
    arr[index] = t;
    ++size;

    return true;
}

void TAArray::print() {
    std::cout << std::endl << std::endl << "Text Areas:" << std::endl;
    for (int i = 0; i < size; ++i) {
        arr[i]->print();
    }
    std::cout << std::endl;
}

TextArea* TAArray::remove(int id) {
    if (id >= 0 && id < size) {
        TextArea* removed = arr[id];
        // Perform removal logic (e.g., shift elements, etc.)
        for (int i = id; i < size - 1; ++i) {
            arr[i] = arr[i + 1];  // Shift elements to the left
        }
        --size;
        return removed;
    }
    return nullptr;  // Return nullptr if index is out of bounds
}

TextArea* TAArray::get(string id){
    for (int i = 0; i < size; ++i){
        if (arr[i]->equals(id)){
            return arr[i];
        }
    }
    return NULL;
}

TextArea* TAArray::get(int index){
    if (index < 0 || index >= size) return NULL;
    return arr[index];
}


TextArea* TAArray::remove(const std::string& id) {
    // Search for the TextArea with the matching id string
    for (int i = 0; i < size; ++i) {
        if (arr[i]->getId() == id) {  // Assuming TextArea has a method getId() that returns the string id
            TextArea* removed = arr[i];
            // Perform removal logic (e.g., shift elements, etc.)
            for (int j = i; j < size - 1; ++j) {
                arr[j] = arr[j + 1];  // Shift elements to the left
            }
            --size;
            return removed;
        }
    }
    std::cerr << id << " not found in order" << std::endl;
    return nullptr;  // Return nullptr if no match is found
}
