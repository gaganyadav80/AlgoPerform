#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include "globalvariable.h"

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> arr, int X)
{
    int i, N = arr.size();
    for (i = 0; i < N; i++) {
        if (arr[i] == X)
            return i;
    }
    return -1;
}

int binarySearch(vector<int> arr, int x)
{
    int l=0, r=arr.size()-1;

    sort(arr.begin(), arr.end());
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}


int ternarySearch(vector<int> arr, int key)
{
    int l=0, r=arr.size()-1;

    sort(arr.begin(), arr.end());
    while (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }

        if (key < arr[mid1]) {
            r = mid1 - 1;
        }
        else if (key > arr[mid2]) {
            l = mid2 + 1;
        }
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}

// BINARY SEARCH TREE
int bstSearch(BTree *root, int x) {
    while(root!=NULL) {
        if(root->key == x)
            return 1;
        else if(root->key < x)
            root=root->right;
        else
            root=root->left;
    }
    return -1;
}

// LINKED LISTS
int listSearch(LList * head, int x){
    int pos=1;
    LList *curr=head;
    while(curr!=NULL){
        if(curr->data==x)
            return pos;
        else{
            pos++;
            curr=curr->next;
        }
    }
    return -1;
}


#endif // SEARCHINGALGO_H
