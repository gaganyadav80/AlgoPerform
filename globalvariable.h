#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include <bits/stdc++.h>

using namespace std;

class Variables {
   static Variables *instance;
   int size;
   vector<int> arr;

   // Private constructor so that no objects can be created.
   Variables() {
      size = 10000;

      arr.resize(size);
      auto f = [this]() -> int { return rand() % size; };
      generate(arr.begin(), arr.end(), f);
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

   void setSize(int data) {
      this -> size = data;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Variables *Variables::instance = 0;

#endif // GLOBALVARIABLE_H
