#include <stdio.h>
#include <math.h>
#include "quaternion/quaternion.h"

#ifdef _WIN32
  #include <windows.h>
#endif

#ifndef M_PI
#define M_PI = 3.1415
#endif

void print_q(const char* label, Quaternion q) {
  printf("%-3s: w=%.3f, x=%.3f, y=%.3f, z=%.3f\n", label, q.w, q.x, q.y, q.z);
}

void print_vector(const char* label, Quaternion v) {
  printf("%-5s: (%.3f, %.3f, %.3f)\n", label, v.x, v.y, v.z);
}

Quaternion quaternion_from_axis_angle(double x, double y, double z, double angle_degrees) {
  double angle_rad = angle_degrees * M_PI / 180.0;
  double half_angle = angle_rad / 2.0;
  double sin_half = sin(half_angle);

  double len = sqrt(x*x + y*y + z*z);
  if (len > 0) {
    x /= len;
    y /= len;
    z /= len;
  }

  return quaternion_create(
      cos(half_angle),
      x * sin_half,
      y * sin_half,
      z * sin_half
  );
}

Quaternion rotate_vector(Quaternion q, Quaternion v) {
  Quaternion q_conj = quaternion_conjugate(q);
  Quaternion temp = quaternion_multiply(q, v);
  Quaternion result = quaternion_multiply(temp, q_conj);
  return result;
}

int main() {
  #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
  #endif

  printf("\n\n\nВывод в консоль\n");
  printf("Ось вращения: Z(0, 0, 1)\n");

  Quaternion v = quaternion_create(0.0, 1.0, 0.0, 0.0);
  printf("Исходный вектор: X(1, 0, 0)\n\n");

  Quaternion q = quaternion_from_axis_angle(0.0, 0.0, 1.0, 90.0);
  printf("Кватернион поворота:\n");
  print_q("q", q);

  Quaternion v_rotated = rotate_vector(q, v);

  printf("Результат поворота:\n");
  print_vector("v_rotated", v_rotated);

  return 0;
}