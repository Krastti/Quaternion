# Библиотека кватернионов на Си
## Работу выполнил студент первого курса — Сальцев Ярослав Б25-507

## Описание
Проект представляет собой библиотеку на языке C для работы с кватернионами. Библиотека реализует основные алгебраические операции над кватернионами и предоставляет функционал для поворота векторов в трёхмерном пространстве.

## Реализованные функции
Библиотека поддерживает следующие операции:
- **Создание**: Инициализация кватерниона.
- **Арифметика**: Сложение, вычитание, умножение кватернионов, умножение на скаляр.
- **Свойства**: Вычисление нормы, квадрата нормы, нормализация.
- **Операции**: Вычисление сопряжённого кватерниона и обратного.
- **Нейтральные элементы**: Нулевой по сложению и единичный по умножению.

## Тестовый пример
В файле `main.c` реализован тестовый пример для проверки корректности поворота векторов.

Параметры теста:
- **Ось вращения**: Вектор Z (0, 0, 1)
- **Исходный вектор**: Ось X (1, 0, 0)
- **Угол поворота**: 90 градусов

Поворот выполняется по формуле:

$$v_{rotated} = q \cdot v \cdot q'$$

---

## Сборка проекта

### Требования

| Инструмент | Версия | Где скачать |
|---|---|---|
| CMake | ≥ 3.10 | https://cmake.org/download/ |
| Компилятор C (GCC / Clang / MSVC) | любая с поддержкой C99 | см. ниже |

### Linux

```bash
# Установка зависимостей (Debian/Ubuntu)
sudo apt update && sudo apt install -y cmake gcc

# Клонирование / переход в папку проекта
cd /path/to/project

# Сборка
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Запуск
./build/test_quaternion
```

> **Примечание.** На Linux разделяемая библиотека (`libquaternion.so`) собирается в `build/`. Благодаря `RPATH=$ORIGIN` исполняемый файл находит её автоматически — выставлять `LD_LIBRARY_PATH` не нужно.

### macOS

```bash
# Установка зависимостей (требуется Homebrew)
brew install cmake

# Xcode Command Line Tools (если ещё не установлены)
xcode-select --install

# Сборка
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Запуск
./build/test_quaternion
```

### Windows

**Вариант 1 — Visual Studio (рекомендуется)**

1. Установить [Visual Studio 2019/2022](https://visualstudio.microsoft.com/) с компонентом «Разработка классических приложений на C++».
2. Установить [CMake](https://cmake.org/download/) (или использовать встроенный в Visual Studio).
3. Открыть папку проекта в Visual Studio: `Файл → Открыть → Папку…`
4. Visual Studio автоматически обнаружит `CMakeLists.txt` и настроит проект.
5. Выбрать конфигурацию `Release` и нажать `Сборка → Собрать все`.

**Вариант 2 — командная строка (Developer Command Prompt)**

```bat
cmake -B build -G "Visual Studio 17 2022"
cmake --build build --config Release

:: Скопировать DLL рядом с exe перед запуском
copy build\Release\quaternion.dll build\Release\
build\Release\test_quaternion.exe
```

**Вариант 3 — MinGW (MSYS2)**

```bash
# В терминале MSYS2 MINGW64
pacman -S mingw-w64-x86_64-cmake mingw-w64-x86_64-gcc

cmake -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build

./build/test_quaternion.exe
```

---

## Структура проекта

```
.
├── CMakeLists.txt
└── src/
    ├── main.c
    └── quaternion/
        ├── quaternion.h
        └── quaternion.c
```
