#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include <bits/stdc++.h>

using namespace std;

struct BTree {
  int key;
  struct BTree *left;
  struct BTree *right;
  BTree(int k){
      key=k;
      left=right=NULL;
  }
};

struct LList
{
  int data;
  struct LList *next;
  LList(int k) {
      data=k;
      next=NULL;
  }
};


class Variables {
   static Variables *instance;
   int size;
   int element;
   int index;
   vector<int> arr;
   BTree *bstroot;
   LList *listroot;

   // Private constructor so that no objects can be created.
   Variables() {
      srand(time(0));
      size = 1000;
      element = rand() % 1000;
      index = rand() % 1000 + 3;
      fillArray();
      fillBST();
      fillLList();
   }

   void fillArray() {
       if(!arr.empty()) arr.clear();
       arr.resize(size);
       auto f = [this]() -> int { return rand() % size + 1; };
       generate(arr.begin(), arr.end(), f);
   }

   void bstInsert(BTree *root, int x) {
       BTree *temp=new BTree(x);
       BTree *parent=NULL,*curr=root;
       while(curr!=NULL){
           parent=curr;
           if(curr->key>x)
               curr=curr->left;
           else if(curr->key<x)
               curr=curr->right;
           else
               return;
       }

       if(parent->key>x)
           parent->left=temp;
       else
           parent->right=temp;
       return;
   }

   void fillBST() {
       bstroot =new BTree(arr[0]);
       int n = arr.size();
       for(int i=1; i<n; i++) {
           bstInsert(bstroot, arr[i]);
       }
   }

   void fillLList() {
       listroot =new LList(arr[0]);
       int n = arr.size();
       struct LList *last = listroot;
       for(int i=1; i<n; i++) {
           LList* new_node = new LList(arr[i]);
           last->next = new_node;
           last = new_node;
       }
   }

   public:
   static Variables *getInstance() {
      if (!instance)
      instance = new Variables;
      return instance;
   }

   vector<int> getArray() {
       return this->arr;
   }

   int getSize() {
       return this->size;
   }

   void setSize(int s) {
       size = s;
       index = rand() % s + 3;
       fillArray();
       fillBST();
       fillLList();
       cout<<"\nRoot node value "<<bstroot->key<<endl;
       cout<<"Array filled with new size of "<<size<<endl;
       cout<<"Binary Tree filled with new size of "<<size<<endl<<endl;
   }

   int getElement() {
       return element;
   }
   void setElement(int e) {
       element = e;
       cout<<"New element to be searched is "<<element<<endl;
   }

   int getIndex() {
       return index;
   }

   BTree* getBstRoot() {
       return bstroot;
   }

   LList* getListRoot() {
       return listroot;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance


//Node* Variables::bstInsert(Node *root, int x) {}

#endif // GLOBALVARIABLE_H
