#include <stdio.h>

void uppercase(char *s)
{
  for (int i = 0; s[i] != '\0'; ++i)
  {
    if ('a' <= s[i] && s[i] <= 'z')
    {
      s[i] += ('A' - 'a');
    }
  }
}

int main()
{
  char s[] = "hello world";
  uppercase(s);
  printf("%s\n", s);
  return 0;
}
