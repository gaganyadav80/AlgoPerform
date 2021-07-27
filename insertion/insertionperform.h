#ifndef INSERTIONPERFORM_H
#define INSERTIONPERFORM_H

#include "insertionalgo.h"

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

unordered_map<string, int> execInsertionPerform() {
    Variables *var = Variables::getInstance();
    unordered_map<string, int> insertionResults;

    //Array insertion at given index execution time
    auto timerStart = high_resolution_clock::now();
    insertArray(var->getArray(), var->getElement(), var->getIndex());
    auto timerStop = high_resolution_clock::now();
    auto timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    insertionResults["instarray"] = abs(timerDuration.count());
    cout<<"\nArray insertion done"<<endl;

    //Linked list insertion at end execution time
    timerStart = high_resolution_clock::now();
    insertLList(var->getListRoot(), var->getElement());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    insertionResults["instllist"] = abs(timerDuration.count());
    cout<<"Linked List done"<<endl;

    //Binary tree insertion execution time
    timerStart = high_resolution_clock::now();
    insertBst(var->getBstRoot(), var->getElement());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    insertionResults["instbst"] = abs(timerDuration.count());
    cout<<"Binary Tree insertion done"<<endl;

    return insertionResults;
}

#endif // INSERTIONPERFORM_H
