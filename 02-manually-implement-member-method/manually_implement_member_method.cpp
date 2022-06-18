// If we try to compile this...
//    g++ manually_implement_member_method.cpp
//
// ... we would get:
//    manually_implement_member_method.cpp:(.text+0x62): undefined reference to
//    `Point2F::Add(Point2F const&)'
//
// Bc. I have no idea of asm, let's first implement `Add` in here, compile, and
// then just copy paste the generated assembly for `Add` into
// `manually_implement_member_method.asm`.
//
// Then assemble:
//    as manually_implement_member_method.asm -o asm.o
//
// And finally, compile:
//    g++ manually_implement_member_method.cpp asm.o
//
// Run:
//    ./a.out
//
// Output:
//    "[25, 5]"
#include <iostream>

class Point2F {
public:
  float x, y;

  Point2F(float x, float y) {
    this->x = x;
    this->y = y;
  }

  void Print() { std::cout << "[" << x << "," << y << "]" << std::endl; }

  void Add(const Point2F &o); // Not implemented

  /*void Add(const Point2F &o) {
    this->x += o.x;
    this->y += o.y;
  }*/
};

int main() {
  Point2F a(10, 3);
  Point2F b(15, 2);

  a.Add(b);  // Manually implemented in `manually_implement_member_method.asm`
  a.Print(); // "[25, 5]"

  return 0;
}
