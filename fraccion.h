//
// Created by rudri on 8/31/2024.
//

#ifndef PROG3_2024_2_FUNDAMENTOS_FRACCION_H
#define PROG3_2024_2_FUNDAMENTOS_FRACCION_H

class Fraction {
  int num = 0;
  int den = 0;
public:
  Fraction() = default;
  Fraction(int num, int den): num(num), den(den) {}
  double get_real() const { return num*1.0/den; }
  friend class MathOperator;
};

class MathOperator {
public:
  Fraction add(const Fraction& a, const Fraction& b) {
    Fraction result(a.num*b.den + b.num*a.den, a.den*b.den);
    return result;
  }
  Fraction product(const Fraction& a, const Fraction& b) {
    Fraction result(a.num*b.num, a.den*b.den);
    return result;
  }
};

#endif//PROG3_2024_2_FUNDAMENTOS_FRACCION_H
