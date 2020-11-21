// http://poj.org/problem?id=1004
#include <cstdio>

int main()
{
  double avg, sum = 0.0, a[12] = {0};
  for (int i = 0; i < 12; i++)
  {
    scanf("%lf", &a[i]);
    sum += a[i];
  }
  avg = sum / 12;

  printf("$%.2f\n", avg);
  return 0;
}