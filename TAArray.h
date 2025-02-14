#ifndef LIST_H
#define LIST_H

#define MAX_ARR 64
#include <iostream>
using namespace std;

#include "defs.h"
#include "TextArea.h"

class TAArray
{
  public:
    TAArray();
    ~TAArray();

    bool add(TextArea*);
    bool add(TextArea* t, int index) ;

    TextArea* get(int index) const;        // Add const here
    TextArea* get(const string& id) const; // Add const here
    TextArea* remove(int index);           // No const, since it modifies the object
    TextArea* remove(const string& id);    // No const, since it modifies the object

    bool isFull(){return size == MAX_ARR;}
    int getSize(){return size;}
    void print();
    

  private:
    TextArea** arr;
    int size;
   
};

#endif

