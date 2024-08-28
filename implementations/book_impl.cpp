#include <chrono>
#include <iostream>
#include <random>

#include "../shared/operations.h"
#include "../properties/settings.h"

int main() {
  double A[max_value][max_value], x[max_value], y[max_value];
  std::chrono::time_point<std::chrono::system_clock> start;
  std::chrono::time_point<std::chrono::system_clock> end;

  fill_list(y);
  fill_list(x, 1, 4);
  fill_arr(A, 1, 4);

  std::cout << "Book Implementation ----------\n";
  std::cout << "max_value= " << max_value << "\n";

  // Primer bucle
  start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < max_value; i++) {
    for (int j = 0; j < max_value; j++) {
      y[i] += A[i][j] * x[j];
    }
  }
  end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> t1 = end - start;
  std::cout << "1th " << t1.count() << "ms\n";

  fill_list(y);

  // Segundo bucle
  start = std::chrono::high_resolution_clock::now();
  for (int j = 0; j < max_value; j++) {
    for (int i = 0; i < max_value; i++) {
      y[i] += A[i][j] * x[j];
    }
  }
  end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> t2 = end - start;
  std::cout << "2nd " << t2.count() << "ms\n";
  std::cout << "-----------------------------\n";

  return 0;
}
