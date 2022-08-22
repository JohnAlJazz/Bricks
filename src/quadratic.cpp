#include "quadratic.hpp"
#include <iostream>
#include <math.h>

typedef experis::Quadratic Quadratic;

Quadratic::Quadratic(Rational a_a, Rational a_b, Rational a_c) noexcept
: m_a(a_a.GetNumerator(), a_a.GetDenominator())
, m_b(a_b.GetNumerator(), a_b.GetDenominator())
, m_c(a_c.GetNumerator(), a_c.GetDenominator()) {}


void Quadratic::PrintPolynomial() const noexcept {
    std::cout << m_a.GetNumerator() << "/" << m_a.GetDenominator() << "X^2 + " << m_b.GetNumerator() << "/" << m_b.GetDenominator() << "X + "
    << m_c.GetNumerator() << "/" << m_c.GetDenominator() << " = 0" << std::endl; 
}

void Quadratic::Multiply(int& a_num) noexcept {
    int setA = m_a.GetNumerator() * a_num, setB = m_b.GetNumerator() * a_num, setC = m_c.GetNumerator() * a_num ;
    m_a.SetNumerator(setA);
    m_b.SetNumerator(setB);
    m_c.SetNumerator(setC);
}

void Quadratic::Multiply(const Rational& a_other) noexcept {
    m_a *= a_other;
    m_b *= a_other;
    m_c *= a_other;
}

static experis::Roots QuadraticEquation(experis::Rational a_a, experis::Rational a_b, experis::Rational a_c) {
    double determinant = a_b.GetRational() * a_b.GetRational() - (4 * (a_a.GetRational() * a_c.GetRational()));
    double root1 = (-1 * a_b.GetRational() + sqrt(determinant)) / (2 * a_a.GetRational());
    double root2 = (-1 * a_b.GetRational() - sqrt(determinant)) / (2 * a_a.GetRational());
    experis::Roots roots(root1, root2);
    return roots;
}

experis::Roots Quadratic::CalcRoots() const noexcept {  
    double determinant = m_b.GetRational() * m_b.GetRational() - (4 * (m_a.GetRational() * m_c.GetRational()));   
    if(determinant < 0) {
        Roots roots;
        return roots;
    }
    else if(determinant == 0) {
        Roots roots(-1 * m_b.GetRational() / (2 * m_a.GetRational()));
        return roots;
    }
    else{ // determinant > 0
        return QuadraticEquation(m_a, m_b, m_c);
    }
}