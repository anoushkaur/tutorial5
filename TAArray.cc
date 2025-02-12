

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

TextArea** TAArray::get(int i){
    if(i>-1 && i<size){
        return arr[i];
    }
}



void TAArray::print()
{
  cout << endl << endl << "Text Areas:" << endl;
  for (int i=0; i<size; ++i)
    arr[i]->print();

  cout << endl;
}