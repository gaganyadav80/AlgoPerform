#ifndef INSERTIONPERFORM_H
#define INSERTIONPERFORM_H

#include "insertionalgo.h"
#include "debuglog.h"

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

unordered_map<string, int> execInsertionPerform() {
    Variables *var = Variables::getInstance();
    unordered_map<string, int> insertResults;

    //Array insertion at given index execution time
    auto timerStart = high_resolution_clock::now();
    insertArray(var->getArray(), var->getElement(), var->getIndex());
    auto timerStop = high_resolution_clock::now();
    auto timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    insertResults["instarray"] = abs(timerDuration.count());
//    cout<<"\nArray insertion done"<<endl;
    printLog("int#0: Array insertion done");

    //Linked list insertion at end execution time
    timerStart = high_resolution_clock::now();
    insertLList(var->getListRoot(), var->getElement());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    insertResults["instllist"] = abs(timerDuration.count());
//    cout<<"Linked List done"<<endl;
    printLog("int#1: Linked list done");

    //Binary tree insertion execution time
    timerStart = high_resolution_clock::now();
    insertBst(var->getBstRoot(), var->getElement());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    insertResults["instbst"] = abs(timerDuration.count());
//    cout<<"Binary Tree insertion done"<<endl;
    printLog("int#2: Binary search tree done");

    return insertResults;
}

#endif // INSERTIONPERFORM_H
