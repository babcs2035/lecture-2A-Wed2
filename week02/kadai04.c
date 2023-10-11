#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
  if (n == 1)
    return 0;
  for (int i = 2; i * i <= n; ++i)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main()
{
  double ans = 1;
  for (int i = 2; i <= 10000; ++i)
  {
    if (is_prime(i))
    {
      ans *= (1 - 1. / (i * i));
    }
  }
  ans = 1 / ans;
  ans *= 6;
  ans = sqrt(ans);
  printf("pi = %.15lf\n", ans);
}
