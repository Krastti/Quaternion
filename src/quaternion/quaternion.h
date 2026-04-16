#ifndef QUATERNION_QUATERNION_H
#define QUATERNION_QUATERNION_H

#ifdef _WIN32
  #ifdef QUATERNION_BUILDING_DLL
    #define QUATERNION_API __declspec(dllexport)
  #else
    #define QUATERNION_API __declspec(dllimport)
  #endif
#else
  #define QUATERNION_API
#endif

typedef struct {
  double w, x, y, z;
} Quaternion;

// Создание кватерниона
QUATERNION_API Quaternion quaternion_create(const double w, const double x,const double y, const double z);

// Нейтральный элемент по сложению
QUATERNION_API Quaternion quaternion_zero(void);

// Нейтральный элемент по умножению
QUATERNION_API Quaternion quaternion_identity(void);

// Вычисление сопряженного кватерниона
QUATERNION_API Quaternion quaternion_conjugate(Quaternion quaternion);

// Вычисление обратного кватерниона
QUATERNION_API Quaternion quaternion_inverse(Quaternion quaternion);

// Сумма кватернионов
QUATERNION_API Quaternion quaternion_sum(Quaternion a, Quaternion b);

// Разность кватернионов
QUATERNION_API Quaternion quaternion_sub(Quaternion a, Quaternion b);

// Умножение кватернионов
QUATERNION_API Quaternion quaternion_multiply(Quaternion a, Quaternion b);

// Умножение кватерниона на скаляр
QUATERNION_API Quaternion quaternion_multiply_by_scalar(Quaternion q, double s);

// Нормализация кватерниона
QUATERNION_API Quaternion quaternion_normalize(Quaternion quaternion);

// Вычисление нормы кватерниона
QUATERNION_API double quaternion_norm_squared(Quaternion quaternion);

// Вычисление длины кватерниона
QUATERNION_API double quaternion_norm(Quaternion quaternion);

#endif // QUATERNION_QUATERNION_H
