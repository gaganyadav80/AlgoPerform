#ifndef SORTINGPERFORM_H
#define SORTINGPERFORM_H

#include "sortingalgo.h"
#include "globalvariable.h"
#include "debuglog.h"

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

unordered_map<string, int> execSortingPerform() {
    Variables *var = Variables::getInstance();
    unordered_map<string, int> sortingResults;

    //insertion sort execution time
    auto timerStart = high_resolution_clock::now();
    insertionSort(var->getArray(), var->getSize());
    auto timerStop = high_resolution_clock::now();
    auto timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    sortingResults["insertion"] = abs(timerDuration.count());
//    cout<<"Insertion sort done"<<endl;
    printLog("srt#0: Array insertion sort done");

    //bubble sort execution time
    timerStart = high_resolution_clock::now();
    bubbleSort(var->getArray(), var->getSize());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    sortingResults["bubble"] = abs(timerDuration.count());
//    cout<<"bubble sort done"<<endl;
    printLog("srt#1: Array bubble sort done");

    //selection sort execution time
    timerStart = high_resolution_clock::now();
    selectionSort(var->getArray(), var->getSize());
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    sortingResults["selection"] = abs(timerDuration.count());
//    cout<<"selection sort done"<<endl;
    printLog("srt#2: Array selection sort done");

    //quick sort execution time
    timerStart = high_resolution_clock::now();
    quickSort(var->getArray(), 0, var->getSize()-1);
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    sortingResults["quick"] = abs(timerDuration.count());
//    cout<<"quick sort done"<<endl;
    printLog("srt#3: Array quick sort done");


    //merge sort execution time
    timerStart = high_resolution_clock::now();
    mergeSort(var->getArray(), 0, var->getSize()-1);
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    sortingResults["merge"] = abs(timerDuration.count());
//    cout<<"merge sort done"<<endl;
    printLog("str#4: Array merge sort done");

    return sortingResults;
}

#endif // SORTINGPERFORM_H
