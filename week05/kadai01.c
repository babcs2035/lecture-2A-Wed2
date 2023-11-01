#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STR_MAX_LEN 256

double get_max(int N, double *arr)
{
  double res = arr[0];
  for (int i = 0; i < N; ++i)
  {
    if (res < arr[i])
    {
      res = arr[i];
    }
  }
  return res;
}

double get_min(int N, double *arr)
{
  double res = arr[0];
  for (int i = 0; i < N; ++i)
  {
    if (res > arr[i])
    {
      res = arr[i];
    }
  }
  return res;
}

double get_mean(int N, double *arr)
{
  double res = 0;
  for (int i = 0; i < N; ++i)
  {
    res += arr[i];
  }
  return res / N;
}

double get_stdev(int N, double *arr)
{
  double res = 0, mean = get_mean(N, arr);
  for (int i = 0; i < N; ++i)
  {
    const double diff = arr[i] - mean;
    res += diff * diff;
  }
  return sqrtl(res / N);
}

int main(int argc, char *argv[])
{
  const char *filename = argv[1];
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Cannot open %s\n", filename);
    return 1;
  }

  int count = 0;
  char buf[STR_MAX_LEN];
  while (fscanf(fp, "%s\n", buf) != EOF)
  {
    ++count;
  }

  double *ages = (double *)malloc(sizeof(double) * count);
  double *heights = (double *)malloc(sizeof(double) * count);
  double *weights = (double *)malloc(sizeof(double) * count);
  count = 0;
  fseek(fp, 0L, SEEK_SET);
  while (1)
  {
    char name[STR_MAX_LEN];
    if (fscanf(fp, "%[^,],%lf,%lf,%lf\n", name, &ages[count], &heights[count], &weights[count]) == EOF)
    {
      break;
    }
    ++count;
  }

  printf("Age : (max,min,mean,stdev) = (%lf, %lf, %lf, %lf)\n", get_max(count, ages), get_min(count, ages), get_mean(count, ages), get_stdev(count, ages));
  printf("Height : (max,min,mean,stdev) = (%lf, %lf, %lf, %lf)\n", get_max(count, heights), get_min(count, heights), get_mean(count, heights), get_stdev(count, heights));
  printf("Weight : (max,min,mean,stdev) = (%lf, %lf, %lf, %lf)\n", get_max(count, weights), get_min(count, weights), get_mean(count, weights), get_stdev(count, weights));

  fclose(fp);
  return 0;
}
