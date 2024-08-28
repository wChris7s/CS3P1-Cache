#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <random>
#include <vector>
#include "../properties/settings.h"

inline double get_random_real_number(const double min, const double max) {
  std::random_device rd;
  std::uniform_real_distribution distribution(min, max);
  return distribution(rd);
}

inline void fill_matrix(std::vector<std::vector<double> > &mat, const double min, const double max) {
  for (long i = 0; i < mat.size(); i++) {
    for (long j = 0; j < mat[0].size(); j++) {
      mat[i][j] = get_random_real_number(min, max);
    }
  }
}

inline void fill_list(double list[max_value]) {
  for (long i = 0; i < max_value; i++) {
    list[i] = 0;
  }
}

inline void fill_list(double list[max_value], const double min, const double max) {
  for (long i = 0; i < max_value; i++) {
    list[i] = get_random_real_number(min, max);
  }
}

inline void fill_arr(double arr[max_value][max_value], const double min, const double max) {
  for (long i = 0; i < max_value; i++) {
    fill_list(arr[i], min, max);
  }
}

#endif //OPERATIONS_H
