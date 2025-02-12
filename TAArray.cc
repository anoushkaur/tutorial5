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

TextArea* TAArray::get(int id) const {
    if (id >= 0 && id < size) {
        return arr[id];
    }
    return nullptr;  // Return nullptr if index is out of bounds
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

TextArea* TAArray::get(const std::string& id) const {
    try {
        int index = std::stoi(id);  // Convert the string to an int
        return get(index);  // Call the get(int) version
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid string input for index: " << id << std::endl;
        return nullptr;  // Handle error if conversion fails
    } catch (const std::out_of_range& e) {
        std::cerr << "Index out of range: " << id << std::endl;
        return nullptr;  // Handle error if the index is out of range
    }
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
