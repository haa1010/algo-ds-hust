#include <stdio.h>
#include <math.h>

int x[101];
int arr[101];
int n, i, s;
int sum = 0, dem = 0;

int check(int v, int k)
{
  return 1;
}

void solution()
{
  for (i = 1; i <= n; i++)
  {
    if (x[i] == 1)
      sum += arr[i];
  }
  if (sum == s)
    dem++;
  sum = 0;
}
void try1(int k)
{
  int v;
  for (v = 0; v <= 1; v++)
  {
    if (check(v, k))
    {
      x[k] = v;
      if (k == n)
        solution();
      else
        try1(k + 1);
      sum = 0;
    }
  }
}

int main()
{
  scanf("%d%d", &n, &s);
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &arr[i]);
  }
  try1(1);
  printf("%d", dem);
  return 0;
}