#ifndef DELETIONPERFORM_H
#define DELETIONPERFORM_H

#include "deletionalgo.h"

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

unordered_map<string, int> execDeletionPerform() {
    Variables *var = Variables::getInstance();
    unordered_map<string, int> results;

    //Array deletion execution time
    auto timerStart = high_resolution_clock::now();
    deleteArray(var->getArray(), var->getElement());
    auto timerStop = high_resolution_clock::now();
    auto timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    results["delarray"] = abs(timerDuration.count());
    cout<<"\nArray deletion of element done"<<endl;

    //Linked list deletion execution time
    timerStart = high_resolution_clock::now();
    deleteLList(var->getListRoot(), var->getElement());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    results["delllist"] = abs(timerDuration.count());
    cout<<"Linked List deletion done"<<endl;

    //Binary tree deletion execution time
    timerStart = high_resolution_clock::now();
    deleteBST(var->getBstRoot(), var->getElement());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    results["delbst"] = abs(timerDuration.count());
    cout<<"Binary Tree deletion done"<<endl;

    return results;
}

#endif // DELETIONPERFORM_H
