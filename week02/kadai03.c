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
  for (int i = 2; i <= 1000; ++i)
  {
    if (is_prime(i))
    {
      printf("%d is prime\n", i);
    }
  }
}
