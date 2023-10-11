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
  for (int n = 4; n <= 1000; n += 2)
  {
    for (int i = 2; i <= n / 2; i++)
    {
      if (is_prime(i) && is_prime(n - i))
      {
        printf("%d = %d + %d\n", n, i, n - i);
      }
    }
  }
}
