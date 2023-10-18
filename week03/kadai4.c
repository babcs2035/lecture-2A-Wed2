#include <stdio.h>

int mod_apm(int a, int p, int m)
{
  if (p == 1)
  {
    return a % m;
  }
  return a * mod_apm(a, p - 1, m) % m;
}

int main()
{
  printf("%d\n", mod_apm(541, 1234, 1299709));
  return 0;
}