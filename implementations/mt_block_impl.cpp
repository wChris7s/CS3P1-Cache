#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "../shared/operations.h"
#include "../properties/settings.h"


void block_matrix_multiplication(
  const std::vector<std::vector<double> > &A,
  const std::vector<std::vector<double> > &B,
  std::vector<std::vector<double> > &C,
  const long block_size) {
  const long n = A.size();
  for (long ii = 0; ii < n; ii += block_size) {
    for (long jj = 0; jj < n; jj += block_size) {
      for (long kk = 0; kk < n; kk += block_size) {
        for (long i = ii; i < std::min(ii + block_size, n); i++) {
          for (long j = jj; j < std::min(jj + block_size, n); j++) {
            double sum = 0.0;
            for (long k = kk; k < std::min(kk + block_size, n); k++) {
              sum += A[i][k] * B[k][j];
            }
            C[i][j] += sum;
          }
        }
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

  std::cout << "Block Method ----------------\n"
      "max_value=" << max_value << "\t"
      "block_size=" << block_size << "\n";

  const auto start = std::chrono::high_resolution_clock::now();
  block_matrix_multiplication(A, B, C, block_size);
  const auto end = std::chrono::high_resolution_clock::now();
  const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

  std::cout << "duration=" << duration << "ms\n";
  std::cout << "-----------------------------\n";

  return 0;
}
