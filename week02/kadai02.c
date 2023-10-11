#include <stdio.h>
#include <math.h>

int zeller(int y, int m, int d);

int main()
{
  int year = 2023, month = 1, day = 10;
  int w;
  w = zeller(year, month, day);
  printf("%d/%d/%d is ", month, day, year);
  switch (w % 7)
  {
  case 0:
    printf("Sat.\n");
    break;
  case 1:
    printf("Sun.\n");
    break;
  case 2:
    printf("Mon.\n");
    break;
  case 3:
    printf("Tue.\n");
    break;
  case 4:
    printf("Wed.\n");
    break;
  case 5:
    printf("Thurs.\n");
    break;
  case 6:
    printf("Fri.\n");
    break;
  }
  return 0;
}

int zeller(int y, int m, int d)
{
  if (m == 1 || m == 2)
  {
    y--;
    m += 12;
  }
  int h = y / 100;
  y = y % 100;
  return y + floor(y / 4.0) + floor(h / 4.0) - 2 * h + floor(13 * (m + 1) / 5.) + d;
}
