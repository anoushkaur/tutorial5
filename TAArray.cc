

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

    for (int i = size; i > 0 ; --i){
        if (t->lessThan(*arr[i-1])){
            //keep making space by copying elements
            //one location to the right
            arr[i]=arr[i-1];
        }else{
            //we have found where s should go
            arr[i] = t;
            ++size;
            return true;
        }
    }

    //we went through every location, and s was less than 
    //all of them. Therefore s goes in location 0
    arr[0] = t;
    ++size;
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




void StudentArray::print()
{
  cout << endl << endl << "Students:" << endl;
  for (int i=0; i<size; ++i)
    arr[i]->print();

  cout << endl;
}