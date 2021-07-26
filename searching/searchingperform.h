#ifndef SEARCHINGPERFORM_H
#define SEARCHINGPERFORM_H

#include "searchingalgo.h"

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

unordered_map<string, int> execSearchingPerform() {
    Variables *var = Variables::getInstance();
    unordered_map<string, int> searchingResults;

    //Array linear search execution time
    auto timerStart = high_resolution_clock::now();
    int x = linearSearch(var->getArray(), var->getElement());
    auto timerStop = high_resolution_clock::now();
    auto timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    searchingResults["linear"] = abs(timerDuration.count());
    cout<<"\nArray linear search done"<<endl;

    //Array binary search execution time
    timerStart = high_resolution_clock::now();
    x = binarySearch(var->getArray(), var->getElement());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    searchingResults["binary"] = abs(timerDuration.count());
    cout<<"Array binary search done"<<endl;

    //Array ternary search execution time
    timerStart = high_resolution_clock::now();
    x = ternarySearch(var->getArray(), var->getElement());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    searchingResults["ternary"] = abs(timerDuration.count());
    cout<<"Array ternary search done"<<endl;

    //Binary search  tree execution time
    timerStart = high_resolution_clock::now();
    x = bstSearch(var->getBstRoot(), var->getElement());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    searchingResults["bst"] = abs(timerDuration.count());
    cout<<"Binary search tree done"<<endl;

    return searchingResults;
}

#endif // SEARCHINGPERFORM_H
