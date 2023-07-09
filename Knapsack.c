#include<stdio.h>
#include<stdlib.h> 

int max(int a,int b) {
    return a > b ? a : b;
}

void printknapsack (int W, int wt[], int val[], int n)
{
  int K[n][W];
  int i, j;
  for (i = 0; i <= n; i++)
  {
      for (j = 0; j <= W; j++)
	{
	  if (i == 0 || j == 0)
	    K[i][j] = 0;
	  else if (wt[i - 1] <= j)
	    K[i][j] = max (K[i - 1][j], val[i - 1] + K[i - 1][j - wt[i - 1]]);
	  else
	    K[i][j] = K[i - 1][j];
	}
  }
  int res = K[n][W];
  printf ("res is %d\n", res);
  printf ("selected items are : ");
  int w = W;
  for (int i = n; i > 0 && res > 0; i--)
    {
      if (res != K[i - 1][w])
	 {
	  printf ("item %d ", i);
	  w = w - wt[i - 1];
	  res = res - val[i - 1];
	 }
    }
}

int main ()
{
  int W, n;
  printf ("enter number of elements\n");
  scanf ("%d", &n);
  int wt[n], val[n];
  printf ("enter weight of elements\n");
  for (int i = 0; i < n; i++)
    scanf ("%d", &wt[i]);
  printf ("enter value of elements\n");
  for (int i = 0; i < n; i++)
    scanf ("%d", &val[i]);
  printf ("enter capacity of bag \n");
  scanf ("%d", &W);
  printknapsack (W, wt, val, n);
}
