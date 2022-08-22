#include "rational.hpp"
#include <stdio.h>
typedef experis::Rational Rational;

/***** STATIC *****/

static Rational AddRationals(const Rational& a_first, const Rational& a_second);
static Rational SubstructRationals(const Rational& a_first, const Rational& a_second);
static Rational MultiplyRationals(const Rational& a_first, const Rational& a_second);
static Rational DivideRationals(const Rational& a_first, const Rational& a_second);
static void GCD(int* a_smaller, int* a_bigger);
static void SimplifiedFractions(int* a_numerator, int* a_denominator);

/********************************************************************************************/

Rational::Rational(const int& a_num) noexcept
: m_numerator(a_num)
, m_denominator(1) {}

Rational::Rational(const int& a_first, const int& a_second) noexcept
: m_numerator()
, m_denominator() 
{    
    int nom = a_first, denom = a_second;
    SimplifiedFractions(&nom, &denom); 
    m_numerator = nom;
    m_denominator = denom;    
}

Rational& Rational::operator=(const Rational& a_ratio) {
    m_numerator = a_ratio.m_numerator;
    m_denominator = a_ratio.m_denominator;
    return *this;
}

double Rational::GetRational() const noexcept {
    return m_numerator / m_denominator;
}

void Rational::SetNumerator(const int& a_num) noexcept {
    m_numerator = a_num;
}

double Rational::GetNumerator() const noexcept {
    return m_numerator;
}

double Rational::GetDenominator() const noexcept {
    return m_denominator;
}

Rational& Rational::operator*=(const Rational& a_ratio) noexcept {
    m_numerator *= a_ratio.m_numerator;
    m_denominator *= a_ratio.m_denominator;
    return *this;
}

Rational Rational::operator+(const Rational& a_other) noexcept {
    return AddRationals(*this, a_other);
}

Rational Rational::operator-(const Rational& a_other) noexcept {
    return SubstructRationals(*this, a_other);
}

Rational Rational::operator*(const Rational& a_other) noexcept {
    return MultiplyRationals(*this, a_other);
}

Rational Rational::operator/(const Rational& a_other) noexcept {
    return DivideRationals(*this, a_other);
}

int operator*=(int& a_num, const Rational& a_ratio) noexcept {
    a_num *= a_ratio.GetNumerator() / a_ratio.GetDenominator();
    return a_num;
}



Rational operator+(const Rational& a_first, const Rational& a_second) {
    Rational r(a_first);
    r = r + a_second;
    return r;
}

bool operator<(int& a_num, const Rational& a_ratio) noexcept {
    return a_num < a_ratio.GetRational();
}

bool operator<(const Rational& a_ratio, int a_num) noexcept {
    return a_ratio.GetRational() < a_num;
}

bool operator<(const Rational& a_first , const Rational& a_second) noexcept {
    return a_first.GetRational() < a_second.GetRational();
}

bool operator>(const Rational& a_first , const Rational& a_second) noexcept {
    return a_first.GetRational() > a_second.GetRational();
}

double operator-(const Rational& a_first , int a_num) noexcept {
    return a_first.GetRational() - a_num;
}

double operator*(double a_num , const Rational& a_second) noexcept {
    return a_num * a_second.GetRational();
}
/******************************************************************************/

static void GCD(int* a_smaller, int* a_bigger) {
    for(int i = *a_smaller; i > 1; i -= 2) {
        if(*a_smaller % i == 0 && *a_bigger % i == 0) {
            *a_smaller /= i;
            *a_bigger /= i;
            return;
        }
    }
}

static void SimplifiedFractions(int* a_numerator, int* a_denominator) {      
    if(*a_numerator == *a_denominator) {        
        *a_numerator = 1;
        *a_denominator = 1;
        return;
    } 
    else if(*a_numerator < *a_denominator) {
        GCD(a_numerator, a_denominator);       
    }
    else{
        return GCD(a_denominator, a_numerator);
    }              
}

static Rational AddRationals(const Rational& a_first, const Rational& a_second) {
    Rational ratio(a_first.GetNumerator() * a_second.GetDenominator() + a_second.GetNumerator() * a_first.GetDenominator()
    , a_first.GetDenominator() * a_second .GetDenominator());      
    return ratio;  
}

static Rational SubstructRationals(const Rational& a_first, const Rational& a_second) {
    Rational ratio(a_first.GetNumerator() * a_second.GetDenominator() - (a_second.GetNumerator() * a_second.GetDenominator())
    , a_first.GetDenominator() * a_second .GetDenominator());  
    return ratio;  
}

static Rational MultiplyRationals(const Rational& a_first, const Rational& a_second) {
    Rational ratio(a_first.GetNumerator() * a_second.GetNumerator(), a_first.GetDenominator() * a_second .GetDenominator());  
    return ratio;  
}

static Rational DivideRationals(const Rational& a_first, const Rational& a_second) {
    Rational ratio(a_first.GetNumerator() * a_second.GetDenominator(), a_first.GetDenominator() * a_second.GetNumerator());  
    return ratio;  
}