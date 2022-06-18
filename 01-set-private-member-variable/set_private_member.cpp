// Access modifiers are only a compiler check. When we know the address of `x`
// in RAM, we can create a pointer to it and just change it.
//
// Member variables are stored at the beginning of the class (if we would've
// virtual methods, the vtable pointer would come first!).
//
// To change the correct member variable, we need to account for memory
// alignment.
//
// Compile:
// g++ set_private_member.cpp && ./a.out
//
// Output:
// x is 4
// x is 123
// b is 456
#include <iostream>

class SomeClass {
private:
  int x;  // 4B
  char c; // 1B + 3B padding
  int b;  // 4B

public:
  void SetX(int x) { this->x = x; }
  void PrintX() { std::cout << "x is " << x << std::endl; }
  void PrintB() { std::cout << "b is " << b << std::endl; }
};

int main() {
  SomeClass a;

  a.SetX(4);
  a.PrintX(); // "4"

  // a.x = 123; // error: ‘int SomeClass::x’ is private within this context

  int *i = (int *)&a;
  *i = 123;   // works!
  a.PrintX(); // "x is 123"

  i++; // Points to c+padding now.
  i++; // Points to b now.
  *i = 456;
  a.PrintB(); // "b is 456"

  return 0;
}
