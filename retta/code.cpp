#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

struct Result {
  double A;
  double B;
};

class Regression {
  int N{};
  double sum_x{};
  double sum_y{};
  double sum_x2{};
  double sum_xy{};

public:
  void add(double x, double y) {
    ++N;
    sum_x += x;
    sum_y += y;
    sum_x2 += x * x;
    sum_xy += x * y;
  }
  Result fit() {
    double const a =
        (sum_y * sum_x2 - sum_xy * sum_x) / (N * sum_x2 - (sum_x * sum_x));
    double const b =
        (N * sum_xy - sum_x * sum_y) / (N * sum_x2 - (sum_x * sum_x));
    return {a, b};
  }
};

TEST_CASE("Testing Regression Class") {
  Regression reg;
  reg.add(0.3, .4);
  reg.add(1.2, 1.3);
  reg.add(.7, -1.);
  reg.add(3.4, 3.74);
  reg.add(1.5, 2.);
  auto result = reg.fit();
  CHECK(result.B == doctest::Approx(1.3137).epsilon(0.01));
  CHECK(result.A == doctest::Approx(-0.5775).epsilon(0.01));
}