#ifndef MONEY_H
#define MONEY_H
#include <iostream>

class Money {
public:
  explicit Money(int = 0, int = 0);
  Money(const Money &);
  virtual ~Money();
  Money & operator=(const Money &);

  Money operator+(const Money &) const;
  Money operator-(const Money &) const;
  bool operator==(const Money &) const;
  bool operator!=(const Money &) const;
  bool operator>(const Money &) const;
  bool operator<(const Money &) const;
  bool operator>=(const Money &) const;
  bool operator<=(const Money &) const;

  friend Money operator%(double, const Money &);
  void monetaryBase();

  std::istream & ext(std::istream &); //extract
  std::ostream & ins(std::ostream &) const;

private:
  int leva, stotinki;
};

std::istream & operator>>(std::istream &, Money &);
std::ostream & operator<<(std::ostream &, const Money &);


#endif //MONEY_H
