// A class with virtual methods has a vtable containing pointers to the correct
// function. The function pointers in the vtable are in the same order as the
// virtual methods have been declared in code.
//
// Each instance of a class has a pointer to the class' vtable.
//
// While the vtable itself is stored in read-only memory, the vtable pointer is
// contained in the data segment, and can be changed!
//
// Compile:
//    g++ swap_vtables.cpp
// Run:
//    ./a.out
// Output:
//    Dog goes woof
//    Fish go bluuurb!
//    Dog goes woof
#include <iostream>

class Animal {
public:
  virtual void Sound() {
    std::cout << "Animal makes a generic sound" << std::endl;
  }
};

class Dog : public Animal {
public:
  virtual void Sound() { std::cout << "Dog goes woof" << std::endl; }
};

class Fish : public Animal {
public:
  virtual void Sound() { std::cout << "Fish go bluuurb!" << std::endl; }
};

int main() {
  Animal *a = NULL;

  a = new Dog();
  a->Sound(); // "Dog goes woof"

  Fish *fish = new Fish();

  // Read vtable pointers
  unsigned long long *v_table_dog = (unsigned long long *)a;
  unsigned long long *v_table_fish = (unsigned long long *)fish;

  // Swap vtable pointers
  unsigned long long tmp;
  tmp = *v_table_dog;
  *v_table_dog = *v_table_fish;
  *v_table_fish = tmp;

  a->Sound();    // "Fish go bluuurb!"
  fish->Sound(); // "Dog goes woof"

  return 0;
}
