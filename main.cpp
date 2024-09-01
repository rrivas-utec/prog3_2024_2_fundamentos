#include <iostream>
#include <vector>
#include "fraccion.h"

// Sobrecargar el operador << por medio de una función global

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  for (const auto& item: v)
    os << item << " ";
  return os;
}

void ejemplo_1() {
  std::vector<int> v1 {1, 2, 3, 4, 5};
  std::vector<int> v2 {6, 7, 8, 9, 10};
  
  ((std::cout << v1) << std::endl); // operando A << operando B // std::ostream& << std::vector<int>
}

class Coordenadas {
  int x = 0;
  int y = 0;
public:
  Coordenadas() = default;
  Coordenadas(int x, int y): x(x), y(y) {}
  [[nodiscard]] int get_x() const { return x; }
  [[nodiscard]] int get_y() const { return y; }
  
  bool operator==(const Coordenadas& other) {
    return this->x == other.x && this->y == other.y;
  }
  bool operator!=(const Coordenadas& other) {
    return !(*this == other);
  }
  friend Coordenadas operator+(const Coordenadas& a, const Coordenadas& b);
  friend std::ostream& operator<<(std::ostream& os, const Coordenadas& c);
};

Coordenadas operator+(const Coordenadas& a, const Coordenadas& b) {
    Coordenadas result(a.x, a.y);
    result.x += b.x;
    result.y += b.y;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Coordenadas& c) {
  os << c.x << ", " << c.y;
  return os;
}

/*
    - Función Global
    - Método de Clase
*/

void ejemplo_2() {
  Coordenadas c1(10, 20);
  Coordenadas c2(30, 50);
 
  auto c3 = c1 + c2;
  std::cout << c1 << std::endl;
  std::cout << c2 << std::endl;
  std::cout << c3 << std::endl;
  std::cout << std::boolalpha << (c1 == c2) << std::endl;
  std::cout << std::boolalpha << (c1 != c2) << std::endl;
}

void ejemplo_3() {
  Fraction f_1(10, 3);
  Fraction f_2(3, 10);
  
  MathOperator mo;
  
  auto result_1 = mo.add(f_1, f_2);
  auto result_2 = mo.product(f_1, f_2);
  
  std::cout << result_1.get_real() << std::endl;
  std::cout << result_2.get_real() << std::endl;
  
}

int main() {
//  ejemplo_1();
//  ejemplo_2();
  ejemplo_3();
  std::cout << "Ejecucion exitosa" << std::endl;
  return 0;
}
