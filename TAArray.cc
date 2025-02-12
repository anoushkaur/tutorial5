

#include "TAArray.h"

TAArray::TAArray(){
    size = 0;
    arr = new TextArea*[MAX_ARR];
}

TAArray::~TAArray(){
    delete [] arr;
}

bool TAArray::add(TextArea* t){
    if (size >= MAX_ARR)return false;

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

void TAArray::print()
{
  cout << endl << endl << "Text Areas:" << endl;
  for (int i=0; i<size; ++i)
    arr[i]->print();

  cout << endl;
}

TextArea* TAArray::get(int id) const {
    if (id >= 0 && id < size) {
        return elements[id];
    }
    return nullptr;  // Return nullptr if index is out of bounds
}

TextArea* TAArray::remove(int id) {
    if (id >= 0 && id < size) {
        TextArea* removed = elements[id];
        // Perform removal logic (e.g., shift elements, etc.)
        return removed;
    }
    return nullptr;  // Return nullptr if index is out of bounds
}

TextArea* TAArray::get(const string& id) const {
    try {
        int index = stoi(id);  // Convert the string to an int
        return get(index);  // Call the get(int) version
    } catch (const invalid_argument& e) {
        cerr << "Invalid string input for index: " << id << endl;
        return nullptr;  // Handle error if conversion fails
    } catch (const out_of_range& e) {
        cerr << "Index out of range: " << id << endl;
        return nullptr;  // Handle error if the index is out of range
    }
}

TextArea* TAArray::remove(const string& id) {
    try {
        int index = stoi(id);  // Convert the string to an int
        return remove(index);  // Call the remove(int) version
    } catch (const invalid_argument& e) {
        cerr << "Invalid string input for index: " << id << endl;
        return nullptr;  // Handle error if conversion fails
    } catch (const out_of_range& e) {
        cerr << "Index out of range: " << id << endl;
        return nullptr;  // Handle error if the index is out of range
    }
}

