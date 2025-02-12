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

    TextArea* get(const string& id) const;
    TextArea* remove(const string& id);
    bool isFull(){return size == MAX_ARR;}
    int getSize(){return size;}
    void print();
    

  private:
    TextArea** arr;
    int size;
   
};

#endif

