#ifndef QUADRATIC_H
#define QUADRATIC_H

#include "rational.hpp"

namespace experis{

class Roots{
public:   
    Roots() : m_numOfRoots{0}, m_x1{-1}, m_x2{-1} {}
    Roots(double m_r1) : m_numOfRoots{1} , m_x1{m_r1}, m_x2{-1} {}
    Roots(double m_r1, double m_r2) : m_numOfRoots{2} , m_x1{m_r1} , m_x2{m_r2} {}  
    int m_numOfRoots;
    double m_x1;
    double m_x2;
};

class Quadratic{
public: 
    Quadratic() = default;
    Quadratic(Rational a_a, Rational a_b, Rational a_c) noexcept;
    Quadratic(const Quadratic& a_other) = default;
    Quadratic& operator=(const Quadratic& a_other) = default;
    ~Quadratic() = default;

    Roots CalcRoots() const noexcept;
    void PrintPolynomial() const noexcept;
    void Multiply(int& a_num) noexcept;
    void Multiply(const Rational& a_other) noexcept;   


private:
    Rational m_a;
    Rational m_b;
    Rational m_c;     
};

#endif
} //experis