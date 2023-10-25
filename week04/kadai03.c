#include <stdio.h>

void reverse(char *s)
{
  int length = 0;
  while (s[length] != '\0')
  {
    length++;
  }
  for (int i = 0; i < length / 2; ++i)
  {
    char tmp = s[i];
    s[i] = s[length - i - 1];
    s[length - i - 1] = tmp;
  }
}

int main()
{
  char s[] = "hello";
  reverse(s);
  printf("%s\n", s);
  return 0;
}
