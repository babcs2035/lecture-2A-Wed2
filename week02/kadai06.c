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
  for (int x = 1; x < 1000; ++x)
  {
    for (int y = x; y < 1000; ++y)
    {
      for (int z = y; z < 1000; ++z)
      {
        if (x * x + y * y == z * z && gcd(x, y) == 1 && gcd(x, z) == 1 && gcd(y, z) == 1)
        {
          printf("%d^2 + %d^2 = %d^2\n", x, y, z);
        }
      }
    }
  }
  return 0;
}
