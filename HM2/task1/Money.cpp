#include "Money.h"
#include <cmath>
#include <iostream>

Money::Money(int leva, int stotinki): leva(leva), stotinki(stotinki) {
    monetaryBase();
}

Money::Money(const Money & rhs) : leva(rhs.leva), stotinki(rhs.stotinki) {

}

Money::~Money() {
}

Money & Money::operator=(const Money & rhs) {
    if (this != & rhs) {
        leva = rhs.leva;
        stotinki = rhs.stotinki;
    }
    return *this;
}

Money Money::operator+(const Money & rhs) const {
    return Money(leva + rhs.leva, stotinki + rhs.stotinki);
}

Money Money::operator-(const Money & rhs) const {
    return Money(leva - rhs.leva, stotinki - rhs.stotinki);
}

bool Money::operator==(const Money & rhs) const {
    return leva == rhs.leva && stotinki == rhs.stotinki;
}

bool Money::operator!=(const Money & rhs) const {
    return !(*this == rhs);
}

bool Money::operator<(const Money & rhs) const {
    return leva < rhs.leva || (leva == rhs.leva && stotinki < rhs.stotinki);// 1 < 2 || 1.50 < 1.99
}

bool Money::operator>(const Money & rhs) const {
    return rhs < *this;
}

bool Money::operator<=(const Money & rhs) const {
    return !(*this > rhs);
}

bool Money::operator>=(const Money & rhs) const {
    return !(*this < rhs);
}

Money operator%(double n, const Money & m) { //n %(procentage) of m
    int totalResultStotinki = static_cast<int>((n / 100.0) * (m.leva * 100 + m.stotinki));
    return Money(totalResultStotinki / 100, totalResultStotinki % 100);
}

void Money::monetaryBase() {
    if (stotinki >= 100) {
        leva += stotinki / 100;
        stotinki %= 100;
    }
    if (stotinki < 0) {
        int stotinkiX = (abs(stotinki) + 99) / 100; //stotinki -= stotinkiX * 100;
        leva -= stotinkiX;
        stotinki += stotinkiX * 100;
    }
}

std::istream & Money::ext(std::istream & in) { //extract
    in >> leva >> stotinki;
    monetaryBase();
    return in;
}

std::ostream & Money::ins(std::ostream & out) const {
    out << leva << " lv " << stotinki << " st";
    return out;
}

std::ostream & operator<<(std::ostream & out, const Money & rhs) {
    return rhs.ins(out);
}

std::istream & operator>>(std::istream & in, Money & rhs) {
    return rhs.ext(in);
}

