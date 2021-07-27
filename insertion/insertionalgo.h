#ifndef INSERTIONALGO_H
#define INSERTIONALGO_H

#include "globalvariable.h"

#include <bits/stdc++.h>
using namespace std;

int insertArray(vector<int> arr, int e, int pos)
{
    int n = arr.size();
    arr.resize(n+1);
    int idx = pos - 1;

    for(int i = n - 1; i >= idx; i--) {
        arr[i + 1] = arr[i];
    }

    arr[idx] = e;

    return n + 1;
}

void insertLList(struct LList* head_ref, int new_data)
{
    LList* new_node = new LList(new_data);

    struct LList *last = head_ref;
//    new_node->data  = new_data;
//    new_node->next = NULL;
//    if (head_ref == NULL) {
//       head_ref = new_node;
//       return;
//    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

BTree* insertBst(BTree *root, int x) {
    BTree *temp=new BTree(x);
    BTree *parent=NULL,*curr=root;
    while(curr!=NULL){
        parent=curr;
        if(curr->key>x)
            curr=curr->left;
        else if(curr->key<x)
            curr=curr->right;
        else
            return root;
    }
    if(parent==NULL)
        return temp;
    if(parent->key>x)
        parent->left=temp;
    else
        parent->right=temp;
    return root;
}


#endif // INSERTIONALGO_H
