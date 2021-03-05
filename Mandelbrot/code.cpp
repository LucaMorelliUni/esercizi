
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
//#include"doctest.h"
#include <string>

class complex {
private:
  double r;
  double i;

public:
  complex(double x, double y) : r{x}, i{y} {}
  complex(double x) : r{x}, i{0} {}
  double real() { return r; }
  double im() { return i; }
  double mod2() { return r * r + i * i; }
  void radd(double x) { r = r + x; }
  void iadd(double x) { i = i + x; }
};
complex operator+(complex x, complex y) {
  complex result{x.real() + y.real(), x.im() + y.im()};
  return result;
}
complex operator*(complex x, complex y) {
  complex result{x.real() * y.real() - y.im() * x.im(),
                 x.real() * y.im() + x.im() * y.real()};
  return result;
}
complex pow(complex x, int n) {
  complex res = x;
  for (; n > 1; --n) {
    res = res * x;
  }
  return res;
}

bool mandel(complex c) {
  complex z = c;
  int i = 0;
  for (; i < 100 && z.mod2() < 4; i++) {
    z = pow(z, 2) + c;
  }
  return bool{!(i < 100)};
}

int main() {

  int const screen_length_min = 30;
  int const screen_height_min = 30;

  double screen_length, screen_height;

  std::cerr << "Inserire larghezza e altezza dell'area da visualizzare: \n";
  std::cin >> screen_length >> screen_height;

  if (screen_height < screen_height_min) {
    std::cerr << "L'altezza selezionata è insufficiente \nE' stata "
                 "ridimensionata a 30 righe \n";
    screen_height = screen_height_min;
  }
  if (screen_length < screen_length_min) {
    std::cerr << "La larghezza selezionata è insufficiente \nE' stata "
                 "ridimensionata a 30 colonne \n";
    screen_length = screen_length_min;
  }

  auto const x0{-2};
  auto const y0{1.5};
  auto const deltax{2.7};
  auto const deltay{3};

  complex C{x0, y0};
  for (double i = 0; i < screen_height; ++i) {
    C.iadd(-deltay / screen_height);
    std::string line;
    for (double j = 0; j < screen_length; ++j) {
      C.radd(deltax / (screen_length));
      char point;
      mandel(C) ? point = '*' : point = ' ';
      line.push_back(point);

      // std::cout<<C.real()<<"+i"<<C.im()<<'\n';
    }
    C.radd(-deltax);
    std::cout << line << '\n';
  }

  return 0;
}
