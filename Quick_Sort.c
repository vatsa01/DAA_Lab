#include<stdio.h>
#include<stdlib.h> 
#include<time.h>

int partition (int a[], int low, int high)
{
  int pivot, start, end, temp;
  pivot = a[low];
  start = low + 1;
  end = high;
  while (start <= end)
    {
      while (a[start] <= pivot)
	start++;
      while (a[end] > pivot)
	end--;
      if (start < end)
	{
	  temp = a[start];
	  a[start] = a[end];
	  a[end] = temp;
	}
      else
	{
	  temp = a[low];
	  a[low] = a[end];
	  a[end] = temp;
	}
    }
  return end;
}

//Sorts array in ascending order 

void quicksort(int a[],int low,int high) {
int pos;
if (low < high)
  {
    pos = partition (a, low, high);
    quicksort (a, low, pos - 1);
    quicksort (a, pos + 1, high);
  }
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
  quicksort (a, 0, n - 1);
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
