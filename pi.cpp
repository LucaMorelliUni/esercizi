#include <iostream>

int main() {
  std::cout << "Inserire il numero di iterazioni da eseguire:";
  double n;
  double pi = 0, x = 0;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    pi = pi + (4 / (1 + x * x) * 1 / n);
    x = x + 1 / n;
    // std::cout<<pi<<"-"<<x<<"\n";
  }
  std::cout << pi << "\n";
}