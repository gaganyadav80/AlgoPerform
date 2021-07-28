#ifndef DELETIONALGO_H
#define DELETIONALGO_H

#include "globalvariable.h"

#include <bits/stdc++.h>
using namespace std;

int deleteArray(vector<int> arr, int x) {
    int i = 0, n = arr.size();

    for(i = 0; i < n; i++) {
        if(arr[i] == x)
            break;
    }
    if(i == n)
        return n;
    for(int j = i; j < n - 1; j++) {
        arr[j] = arr[j + 1];
    }
    return n-1;
}

// BINARY TREE
BTree *getSuccessor(BTree *curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
}

BTree *deleteBST(BTree *root, int x){
    if(root==NULL)
        return root;
    if(root->key>x)
        root->left=deleteBST(root->left,x);
    else if(root->key<x)
        root->right=deleteBST(root->right,x);
    else{
        if(root->left==NULL){
            BTree *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            BTree *temp=root->left;
            delete root;
            return temp;
        }
        else{
            BTree *succ=getSuccessor(root);
            root->key=succ->key;
            root->right=deleteBST(root->right,succ->key);
        }
    }
    return root;
}

// LINKED LIST
void deleteLList(struct LList *head_ref, int key)
{
    struct LList* temp = head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

#endif // DELETIONALGO_H
