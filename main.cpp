//
//  main.cpp
//  Daily 6
//
//  Created by Ojas Mehta on 10/11/17.
//  Copyright © 2017 Ojas Mehta. All rights reserved.
//

#include <iostream>
using namespace std;

class Rational
{
public:
    Rational();
    Rational(int user_numerator);
    Rational(int user_numerator, int user_denominator);
    friend ostream& operator <<(ostream& outputStream, Rational rational);
    friend Rational operator+ (const Rational& a,const Rational& b);
    friend Rational operator- (const Rational& a,const Rational& b);
    friend Rational operator* (const Rational& a,const Rational& b);
    friend Rational operator/ (const Rational& a,const Rational& b);
    friend bool operator< (const Rational& lhs,const Rational& rhs);
    friend bool operator> (const Rational& lhs,const Rational& rhs);
    friend bool operator<= (const Rational& lhs,const Rational& rhs);
    friend bool operator>= (const Rational& lhs,const Rational& rhs);
    friend bool operator== (const Rational& lhs,const Rational& rhs);
    friend bool operator!= (const Rational& lhs,const Rational& rhs);
    //friend Rational operator++ ();
    
    const Rational operator++ ();//pre-increment
    const Rational operator++ (int);//post-increment
    const Rational operator-- ();//pre-decrement
    const Rational operator--(int);//post-decrement
    //  friend ostream& operator pre++(ostream& outputStream, Rational rational);
    //  friend ostream& operator pre--(ostream& outputStream, Rational rational);
    //  friend ostream& operator post++(ostream& outputStream, Rational rational);
    //  friend ostream& operator post++(ostream& outputStream, Rational rational);
    
private:
    int numerator;
    int denominator;
    
};
int simplify(int a, int b);

int main(int argc, const char * argv[]) {
    
    Rational rational_fraction_1(2,3);
    Rational rational_fraction_2(7,10);
    
    Rational rational_fraction_add = rational_fraction_1 + rational_fraction_2;
    Rational rational_fraction_sub = rational_fraction_1 - rational_fraction_2;
    Rational rational_fraction_mult = rational_fraction_1 * rational_fraction_2;
    Rational rational_fraction_div = rational_fraction_1 / rational_fraction_2;
    int rational_fraction_less_than = (rational_fraction_1 < rational_fraction_2);
    int rational_fraction_greater_than = (rational_fraction_1 > rational_fraction_2);
    int rational_fraction_less_than_equal_to = (rational_fraction_1 <= rational_fraction_2);
    int rational_fraction_greater_than_equal_to = (rational_fraction_1 >= rational_fraction_2);
    int rational_fraction_bool_equal = (rational_fraction_1 == rational_fraction_2);
    int rational_fraction_bool_not_equal = (rational_fraction_1 != rational_fraction_2);
    cout << "Fraction 1:";
    cout << rational_fraction_1 << endl;
    
    cout << "Fraction 2:";
    cout << rational_fraction_2 << endl;
    
    cout << "Their addition equals to ";
    cout << rational_fraction_add << endl;
    
    cout << "Their subtraction equals to ";
    cout << rational_fraction_sub << endl;

    cout << "Their multiplication equals to ";
    cout << rational_fraction_mult << endl;

    cout << "Their division equals to ";
    cout << rational_fraction_div << endl;

    cout << "The value for Fraction 1 < Fraction 2 is :";
    cout << rational_fraction_less_than<< endl;
    
    cout << "The value for Fraction 1 > Fraction 2 is :";
    cout << rational_fraction_greater_than<< endl;
    
    cout << "The value for Fraction 1 <= Fraction 2 is :";
    cout << rational_fraction_less_than_equal_to<< endl;

    cout << "The value for Fraction 1 >= Fraction 2 is :";
    cout << rational_fraction_greater_than_equal_to<< endl;
    
    cout << "The value for Fraction 1 == Fraction 2 is :";
    cout << rational_fraction_bool_equal << endl;
    
    cout << "The value for Fraction 1 != Fraction 2 is :";
    cout << rational_fraction_bool_not_equal << endl;
    
    cout << "The pre-increment return value for Fraction 1 is:";
    cout << ++rational_fraction_1 << endl;
    
    cout << "The post-increment return value for Fraction 1 is:";
    cout << rational_fraction_1++ << endl;
    
    cout << "Final Fraction 1 value:";
    cout << rational_fraction_1 << endl;

    cout << "The pre-decrement return value for Fraction 1 is:";
    cout << ++rational_fraction_1 << endl;
    
    cout << "The post-decrement return value for Fraction 1 is:";
    cout << rational_fraction_1++ << endl;
    
    cout << "Final Fraction 1 value:";
    cout << rational_fraction_1 << endl;
}
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int user_numerator)
{
    numerator = user_numerator;
    denominator = 1;
}

Rational::Rational(int user_numerator,int user_denominator)
{
    int simplify_val = simplify(user_numerator, user_denominator);
    
    numerator = user_numerator;
    denominator = user_denominator;
    numerator /= simplify_val;
    denominator /= simplify_val;
}
int simplify(int a, int b)
{
    if (a == 0)
        return b;
    return (simplify(b % a, a));
}

ostream& operator <<(ostream& outputStream, const Rational rational)
{
    outputStream << rational.numerator << " / " << rational.denominator;
    return outputStream;
}

Rational operator+ (const Rational& a,const Rational& b)
{
    double frac1Num = a.numerator*b.denominator;
    double frac1Den = a.denominator*b.denominator;
    double frac2Num = b.numerator*a.denominator;
   // double frac2Den = b.numerator*a.denominator;
    
    Rational finalFraction((frac1Num+frac2Num), (frac1Den));
    return finalFraction;
}
Rational operator- (const Rational& a,const Rational& b)
{
    double frac1Num = a.numerator*b.denominator;
    double frac1Den = a.denominator*b.denominator;
    double frac2Num = b.numerator*a.denominator;
    // double frac2Den = b.numerator*a.denominator;
    
    Rational finalFraction((frac1Num-frac2Num), (frac1Den));
    return finalFraction;
}
Rational operator* (const Rational& a,const Rational& b)
{
    double newNumerator = a.numerator*b.numerator;
    double newDenominator = a.denominator*b.denominator;
    Rational myRational((newNumerator),(newDenominator));
    
    return myRational;
}
Rational operator/ (const Rational& a,const Rational& b)
{
    double newNumerator = a.numerator*b.denominator;
    double newDenominator = a.denominator*b.numerator;
    Rational myRational((newNumerator),(newDenominator));
    
    return myRational;
}
bool operator< (const Rational& lhs,const Rational& rhs)
{
    double leftVal = (double) lhs.numerator/lhs.denominator;
    double rightVal =(double) rhs.numerator/rhs.denominator;
    
    return (leftVal < rightVal);
}
bool operator> (const Rational& lhs,const Rational& rhs)
{
    double leftVal = (double) lhs.numerator/lhs.denominator;
    double rightVal =(double) rhs.numerator/rhs.denominator;
    
    return (leftVal > rightVal);
}
bool operator<= (const Rational& lhs,const Rational& rhs)
{
    double leftVal = (double) lhs.numerator/lhs.denominator;
    double rightVal =(double) rhs.numerator/rhs.denominator;
    
    return (leftVal <= rightVal);
}
bool operator>= (const Rational& lhs,const Rational& rhs)
{
    double leftVal = (double) lhs.numerator/lhs.denominator;
    double rightVal =(double) rhs.numerator/rhs.denominator;
    
    return (leftVal >= rightVal);
    
}
bool operator== (const Rational& lhs,const Rational& rhs)
{
    double leftVal = (double) lhs.numerator/lhs.denominator;
    double rightVal =(double) rhs.numerator/rhs.denominator;
    
    return (leftVal == rightVal);
}
bool operator!= (const Rational& lhs,const Rational& rhs)
{
    double leftVal = (double) lhs.numerator/lhs.denominator;
    double rightVal =(double) rhs.numerator/rhs.denominator;
    
    return (leftVal != rightVal);
}
const Rational Rational::operator++ ()
{
    Rational sub_one(1);
    *this = *this + Rational(1);
    
    return *this;
}
const Rational Rational::operator++ (int)//post-increment
{
    Rational result(*this);
    ++(*this);
    return result;
}
const Rational Rational::operator-- ()//pre-decrement
{
    
    Rational sub_one(1);
    *this = *this - Rational(1);
    
    return *this;
}
const Rational Rational::operator-- (int)//post-decrement
{
    Rational result(*this);
    --(*this);
    return result;
}

