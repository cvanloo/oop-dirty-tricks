// We can not only swap vtable pointers, but we can also define our own vtable
// entirely.
//
// Compile:
//    g++ define_own_vtable.cpp
// Run:
//    ./a.out
// Output:
//    This in main: 0x561df154beb0
//    This: 0x561df154beb0
//    Param: 5
//    Walk Function
//    Sound Function
//    Grow Function
#include <iostream>

class Animal {
public:
  virtual void Walk(int i) {
    std::cout << "Animal walks " << i << " meters" << std::endl;
  }
  virtual void Sound() { std::cout << "Animal makes a sound" << std::endl; }
  virtual void Grow() { std::cout << "Animal grows a bit" << std::endl; }
};

// Note that first parameter is implicit `this` pointer!
void Function1(Animal *this_ptr, int x) {
  std::cout << "This: " << this_ptr << std::endl;
  std::cout << "Param: " << x << std::endl;
  std::cout << "Walk Function" << std::endl;
}
void Function2() { std::cout << "Sound Function" << std::endl; }
void Function3() { std::cout << "Grow Function" << std::endl; }

int main() {
  // typedef a function pointer
  typedef void (*fnptr)();

  // User defined vtable!
  fnptr vtable[] = {(fnptr)Function1, Function2, Function3};

  // Define instance of animal
  Animal *animal = new Animal();

  // Point animal-vfptr to the new vtable
  *((unsigned long long *)animal) = (unsigned long long)vtable;

  std::cout << "This in main: " << animal << std::endl;

  // Call virtual functions of vtable
  animal->Walk(5); // "Walk function"
  animal->Sound(); // "Sound function"
  animal->Grow();  // "Grow function"

  return 0;
}
