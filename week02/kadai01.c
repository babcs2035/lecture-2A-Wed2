#include <stdio.h>
#include <math.h>

int main()
{
  double ans = 0;
  for (int n = 1; n < 500; ++n)
  {
    ans += 1 / (n * n * pow(2, n - 1));
  }
  ans += log(2) * log(2);
  ans *= 6;
  ans = sqrt(ans);
  printf("%.15lf\n", ans);
  return 0;
}
