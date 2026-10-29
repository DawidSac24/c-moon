#include "add.h"

#include <iostream>

int main() {
  const int result = add(2, 3);
  if (result != 5) {
    std::cerr << "Expected 2 + 3 to equal 5, got " << result << '\n';
    return 1;
  }

  std::cout << "2 + 3 = " << result << '\n';
  return 0;
}
