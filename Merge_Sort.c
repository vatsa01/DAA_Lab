#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>

void merge (int a[], int lb, int mid, int ub)
{
  int i, j, k, b[100];
  i = lb;
  j = mid + 1;
  k = lb;
  while (i <= mid && j <= ub)
    {
      if (a[i] < a[j])
	{
	  b[k] = a[i];
	  k++;
	  i++;
	}
      else
	{
	  b[k] = a[j];
	  k++;
	  j++;
	}
    }
  while (i <= mid)
    {
      b[k] = a[i];
      k++;
      i++;
    }
  while (j <= ub)
    {
      b[k] = a[j];
      k++;
      j++;
    }
  for (k = lb; k <= ub; k++)
    {
      a[k] = b[k];
    }
}

void mergesort (int a[], int lb, int ub)
{
  int mid;
  if (lb >= ub)
    {
      return;
    }
  mid = (lb + ub) / 2;
  mergesort (a, lb, mid);
  mergesort (a, mid + 1, ub);
  merge (a, lb, mid, ub);
}

void main ()
{
  int n;
  clock_t s, e;
  double t;
  printf ("enter the size of the array: ");
  scanf ("%d", &n);
  int a[n], min, temp;
  printf ("enter the array elements:\n");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  printf ("entered elements of array are: ");
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", a[i]);
    }
  printf ("\n");
  s = clock ();
  mergesort (a, 0, n - 1);
  e = clock ();
  printf ("sorted array is: ");
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", a[i]);
    }
  printf ("\n");
  t = (double) (e - s) / CLOCKS_PER_SEC;
  printf ("time taken to sort is: %f", t);
}
