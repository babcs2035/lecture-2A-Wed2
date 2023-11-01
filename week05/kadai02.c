#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
  const char *input_filename = argv[1];
  const char *output_filename = argv[2];

  FILE *input_fp = fopen(input_filename, "r");
  FILE *output_fp = fopen(output_filename, "w");
  if (input_fp == NULL)
  {
    printf("Cannot open %s\n", input_filename);
    return 1;
  }
  if (output_fp == NULL)
  {
    printf("Cannot open %s\n", output_filename);
    return 1;
  }

  char buff;
  int count = 0;
  while ((buff = fgetc(input_fp)) != EOF)
  {
    ++count;
  }

  char *str = (char *)malloc(sizeof(char) * (count + 1));
  fseek(input_fp, 0L, SEEK_SET);
  fgets(str, count, input_fp);

  const int diff = 'A' - 'a';
  for (int i = 0; i < count; ++i)
  {
    int is_first = (i == 0 || (i > 2 && str[i - 2] == '.' && str[i - 1] == ' ') || (i > 3 && str[i - 3] == '.' && str[i - 2] == ' ' && str[i - 1] == '"'));
    int is_i = (i > 1 && str[i - 1] == ' ' && str[i] == 'i' && (str[i + 1] == ' ' || str[i + 1] == '\''));
    int is_char = 'a' <= str[i] && str[i] <= 'z';
    if (is_char && (is_first || is_i))
    {
      str[i] += diff;
    }
  }
  fprintf(output_fp, "%s", str);

  fclose(input_fp);
  fclose(output_fp);
  return 0;
}
