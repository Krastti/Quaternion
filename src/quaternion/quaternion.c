#include "quaternion.h"
#include <math.h>

QUATERNION_API Quaternion quaternion_create(const double w, const double x, const double y, const double z) {
  Quaternion q;
  q.w = w;
  q.x = x;
  q.y = y;
  q.z = z;
  return q;
}

QUATERNION_API Quaternion quaternion_zero(void) {
  return (Quaternion){0.0, 0.0, 0.0, 0.0};
}

QUATERNION_API Quaternion quaternion_identity(void) {
  return (Quaternion){1.0, 0.0, 0.0, 0.0};
}

QUATERNION_API Quaternion quaternion_conjugate(Quaternion q) {
  return (Quaternion){q.w, -q.x, -q.y, -q.z};
}

QUATERNION_API Quaternion quaternion_inverse(Quaternion quaternion) {
  double norm_sq = quaternion_norm_squared(quaternion);
  if (norm_sq > 0.0) {
    Quaternion conj = quaternion_conjugate(quaternion);
    return quaternion_multiply_by_scalar(conj, 1.0 / norm_sq);
  } else {
    return quaternion_zero();
  }
}

QUATERNION_API Quaternion quaternion_sum(Quaternion a, Quaternion b) {
  return (Quaternion) {
      a.w + b.w,
      a.x + b.x,
      a.y + b.y,
      a.z + b.z
  };
}

QUATERNION_API Quaternion quaternion_sub(Quaternion a, Quaternion b) {
  return (Quaternion) {
      a.w - b.w,
      a.x - b.x,
      a.y - b.y,
      a.z - b.z
  };
}

QUATERNION_API Quaternion quaternion_multiply(Quaternion a, Quaternion b) {
  Quaternion result;
  result.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
  result.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
  result.y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x;
  result.z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w;
  return result;
}

QUATERNION_API Quaternion quaternion_multiply_by_scalar(Quaternion q, double s) {
  return (Quaternion) {
    q.w * s,
    q.x * s,
    q.y * s,
    q.z * s
  };
}

QUATERNION_API Quaternion quaternion_normalize(Quaternion q) {
  double n = quaternion_norm(q);
  if (n > 0.0) {
    return quaternion_multiply_by_scalar(q, 1.0 / n);
  } else {
    return quaternion_zero();
  }
}

QUATERNION_API double quaternion_norm_squared(Quaternion q) {
  return q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z;
}

QUATERNION_API double quaternion_norm(Quaternion q) {
  return sqrt(quaternion_norm_squared(q));
}