#include <stdio.h>
#include <math.h>

const double EPS = 1e-10;

double f(double x)
{
  return exp(x) + x;
}

double dfdx(double x)
{
  return exp(x) + 1;
}

double newton(double x)
{
  double next_x = x - f(x) / dfdx(x);
  if (fabs(next_x - x) < EPS)
  {
    return next_x;
  }
  return newton(next_x);
}

int main()
{
  printf("%lf\n", newton(0));
  return 0;
}