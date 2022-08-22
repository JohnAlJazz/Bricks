#ifndef RATIONAL_H
#define RATIONAL_H

namespace experis {

class Rational{
public: 
    explicit Rational(const int& a_num) noexcept;
    explicit Rational(const int& a_first, const int& a_second) noexcept;
    Rational& operator=(const Rational& a_ratio);
    Rational(const Rational& a_ratio) = default;
    ~Rational() = default;

    Rational operator+(const Rational& a_other) noexcept;
    Rational operator-(const Rational& a_other) noexcept;
    Rational operator*(const Rational& a_other) noexcept;
    Rational operator/(const Rational& a_other) noexcept;
    Rational& operator*=(const Rational& a_ratio) noexcept;    

    double GetRational() const noexcept;
    double GetNumerator() const noexcept;
    void SetNumerator(const int& a_num) noexcept;
    double GetDenominator() const noexcept;

private:
    int m_numerator;
    int m_denominator;
};
Rational operator+(const Rational& a_first, const Rational& a_second);

double operator-(const Rational& a_first , int a_num) noexcept;

double operator*(double a_num , const Rational& a_second) noexcept;
Rational operator*(const Rational& a_first , int a_number) noexcept;


Rational operator+(const Rational& a_first , int& a_num) noexcept;
Rational operator+(int& a_num , const Rational& a_second) noexcept;
bool operator<(int& a_num, const Rational& a_ratio) noexcept;
bool operator<(const Rational& a_ratio, int a_num) noexcept;
bool operator>(int& a_num, const Rational& a_ratio) noexcept;
bool operator<(const Rational& a_first , const Rational& a_second) noexcept;
bool operator>(const Rational& a_first , const Rational& a_second) noexcept;
int operator*=(int& a_num, const Rational& a_ratio) noexcept;

} //experis
#endif