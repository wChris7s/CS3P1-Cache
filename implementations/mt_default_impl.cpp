#include <chrono>
#include <iostream>
#include <vector>

#include "../shared/operations.h"
#include "../properties/settings.h"

void classic_matrix_multiplication(
  const std::vector<std::vector<double> > &A,
  const std::vector<std::vector<double> > &B,
  std::vector<std::vector<double> > &C) {
  const long n = A.size();
  for (long i = 0; i < n; i++) {
    for (long j = 0; j < n; j++) {
      for (long k = 0; k < n; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

int main() {
  std::vector A(max_value, std::vector<double>(max_value));
  std::vector B(max_value, std::vector<double>(max_value));
  std::vector C(max_value, std::vector<double>(max_value, 0));

  fill_matrix(A, 1, 4);
  fill_matrix(B, 1, 4);

  std::cout << "Default Method --------------\n"
               "max_value="  << max_value << "\n";

  const auto start = std::chrono::high_resolution_clock::now();
  classic_matrix_multiplication(A, B, C);
  const auto end = std::chrono::high_resolution_clock::now();
  const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

  std::cout << "duration=" << duration << "ms\n";
  std::cout << "-----------------------------\n";
  return 0;
}
