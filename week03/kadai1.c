#include <stdio.h>

// n が大きい時に再帰呼び出しが大量に発生し，処理が短時間では終わらない
double legendre(int n, double x)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  return ((2 * n - 1) * x * legendre(n - 1, x) - (n - 1) * legendre(n - 2, x)) / n;
}

int main()
{
  printf("%lf\n", legendre(16, 0.5));
  printf("%lf\n", legendre(32, 0.7));
  return 0;
}
