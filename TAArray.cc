

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

TextArea* TAArray::get(const string& id) const {
    for (int i = 0; i < size; ++i) {
        if (arr[i]->equals(id)) {  // Assuming TextArea has an equals method that compares it to a string
            return arr[i];
        }
    }
    return nullptr;  // Return nullptr if no match is found
}




void TAArray::print()
{
  cout << endl << endl << "Text Areas:" << endl;
  for (int i=0; i<size; ++i)
    arr[i]->print();

  cout << endl;
}

TextArea* TAArray::remove(const string& id) {
    int index = 0;
    
    // Find the index of the TextArea with the matching id
    while (index < size && !arr[index]->equals(id)) {
        ++index;
    }

    // If the index is valid, remove the element
    if (index < size && arr[index]->equals(id)) {
        return remove(index);  // Call the existing remove function that removes by index
    }

    return nullptr;  // Return nullptr if no matching TextArea was found
}

