#ifndef SORTINGPERFORM_H
#define SORTINGPERFORM_H

#include "sortingalgo.h"
#include "globalvariable.h"

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

unordered_map<string, int> execSortingPerform(int size) {
    Variables *var = Variables::getInstance();
    unordered_map<string, int> sortingResults;

    //insertion sort execution time
    auto timerStart = high_resolution_clock::now();
    insertionSort(var->getArray(), size);
    auto timerStop = high_resolution_clock::now();
    auto timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    sortingResults["insertion"] = abs(timerDuration.count());

    //bubble sort execution time
    timerStart = high_resolution_clock::now();
    bubbleSort(var->getArray(), size);
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    sortingResults["bubble"] = abs(timerDuration.count());

    //selection sort execution time
    timerStart = high_resolution_clock::now();
    selectionSort(var->getArray(), size);
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    sortingResults["selection"] = abs(timerDuration.count());

    //quick sort execution time
    timerStart = high_resolution_clock::now();
    quickSort(var->getArray(), 0, size-1);
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    sortingResults["quick"] = abs(timerDuration.count());


    //merge sort execution time
    timerStart = high_resolution_clock::now();
    mergeSort(var->getArray(), 0, size-1);
    timerStop = high_resolution_clock::now();
    timerDuration = duration_cast<microseconds>(timerStart - timerStop);
    sortingResults["merge"] = abs(timerDuration.count());

    return sortingResults;
}

#endif // SORTINGPERFORM_H
