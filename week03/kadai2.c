#include <stdio.h>

double f(double z, int d)
{
  if (d == 0)
  {
    return 0;
  }
  return (z - 1) / (2 + f(z, d - 1));
}

int main()
{
  double z = 3;
  printf("%f\n", 1 + f(z, 10));
  return 0;
}