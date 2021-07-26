#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  Node(int k){
      key=k;
      left=right=NULL;
  }
};


class Variables {
   static Variables *instance;
   int size;
   int element;
   vector<int> arr;
   Node *bstroot;

   // Private constructor so that no objects can be created.
   Variables() {
      srand(time(0));
      size = 1000;
      element = rand() % 1000;
      this -> fillArray();
      this -> fillBST();
   }

   void fillArray() {
       if(!arr.empty()) arr.clear();
       arr.resize(size);
       auto f = [this]() -> int { return rand() % size + 1; };
       generate(arr.begin(), arr.end(), f);
   }

   Node* bstInsert(Node *root, int x) {
       Node *temp=new Node(x);
       Node *parent=NULL,*curr=root;
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

   void fillBST() {
       bstroot =new Node(arr[0]);
       int n = arr.size();
       for(int i=1; i<n; i++) {
           bstroot = bstInsert(bstroot, arr[i]);
       }
   }

   public:
   static Variables *getInstance() {
      if (!instance)
      instance = new Variables;
      return instance;
   }

   vector<int> getArray() {
       return this -> arr;
   }

   int getSize() {
       return this -> size;
   }

   void setSize(int s) {
       this -> size = s;
       this -> fillArray();
       this -> fillBST();
       cout<<"\nRoot node value "<<bstroot->key<<endl;
       cout<<"Array filled with new size of "<<size<<endl;
       cout<<"Binary Tree filled with new size of "<<size<<endl<<endl;
   }

   int getElement() {
       return this->element;
   }
   void setElement(int e) {
       this->element = e;
       cout<<"New element to be searched is "<<element<<endl;
   }

   Node* getBstRoot() {
       return this->bstroot;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance


//Node* Variables::bstInsert(Node *root, int x) {}

#endif // GLOBALVARIABLE_H
