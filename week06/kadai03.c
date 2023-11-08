#include <stdio.h>
#include <string.h>
#define STR_MAX_LEN 256

struct person
{
  char name[20];
  int age;
  double weight;
  double height;
  struct person *prev;
  struct person *next;
  int exist;
};

void delete(struct person *h, char *s)
{
  struct person *dat = h;
  while (1)
  {
    if (dat == NULL)
    {
      break;
    }
    if (strcmp(dat->name, s) == 0)
    {
      if (dat->prev != NULL)
      {
        dat->prev->next = dat->next;
      }
      if (dat->next != NULL)
      {
        dat->next->prev = dat->prev;
      }
      dat->exist = 0;
    }
    dat = dat->next;
  }
}

void print(struct person *h)
{
  struct person *dat = h;
  while (1)
  {
    if (dat == NULL)
    {
      break;
    }
    if (dat->exist)
    {
      printf("%s,%d,%lf,%lf,%p\n", dat->name, dat->age, dat->height, dat->weight, dat->next);
    }
    dat = dat->next;
  }
}

int main(int argc, char *argv[])
{
  const char *filename = argv[1];
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("file open error\n");
    return 1;
  }

  int count = 0;
  char buf[STR_MAX_LEN];
  while (fscanf(fp, "%s\n", buf) != EOF)
  {
    ++count;
  }
  struct person data[count];
  int N = count;
  fseek(fp, 0L, SEEK_SET);

  for (int i = 0; i < N; ++i)
  {
    struct person *dat = &data[i];
    fscanf(fp, "%[^,],%d,%lf,%lf\n", dat->name, &dat->age, &dat->height, &dat->weight);
    if (i > 0)
    {
      dat->prev = dat - 1;
    }
    else
    {
      dat->prev = NULL;
    }
    if (i < N - 1)
    {
      dat->next = dat + 1;
    }
    else
    {
      dat->next = NULL;
    }
    dat->exist = 1;
  }

  char name[100];
  scanf("%s", name);
  delete (data, name);
  print(data);
}
