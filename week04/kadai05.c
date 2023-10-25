#include <stdio.h>

int roman2num(char *s)
{
  char *s_ = s;

  int length = 0;
  while (s[length] != '\0')
  {
    if (s[length] == 'I')
      s[length] = 'a';
    if (s[length] == 'V')
      s[length] = 'b';
    if (s[length] == 'X')
      s[length] = 'c';
    if (s[length] == 'L')
      s[length] = 'd';
    if (s[length] == 'C')
      s[length] = 'e';
    if (s[length] == 'D')
      s[length] = 'f';
    if (s[length] == 'M')
      s[length] = 'g';
    length++;
  }

  int ans = 0;
  for (int i = 0; i < length; ++i)
  {
    char c1 = s[i];
    char c2 = 'A';
    if (i + 1 < length)
      c2 = s[i + 1];
    int res;
    if (c1 == 'a')
      res = 1;
    if (c1 == 'b')
      res = 5;
    if (c1 == 'c')
      res = 10;
    if (c1 == 'd')
      res = 50;
    if (c1 == 'e')
      res = 100;
    if (c1 == 'f')
      res = 500;
    if (c1 == 'g')
      res = 1000;
    if (c1 < c2)
      res *= -1;
    ans += res;
  }

  s = s_;
  return ans;
}

int main()
{
  char s[100];
  scanf("%s", s);
  printf("%d\n", roman2num(s));
  return 0;
}
