#include <stdio.h>
#include <math.h>

int gcd(int a, int b)
{
  while (b != 0)
  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main()
{
  int r;
  int a = 8733;
  int b = 64681;
  r = gcd(a, b);
  printf("gcd(%d, %d) = %d\n", a, b, r);
  return 0;
}
