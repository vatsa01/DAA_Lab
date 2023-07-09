#include<stdio.h> 
#include<stdlib.h>

void heapify (int a[], int n, int i)
{
  int largest, left, right;
  largest = i;
  left = 2 * i + 1;
  right = 2 * i + 2;
  if (right < n && a[right] > a[largest])
    largest = right;
  if (left < n && a[left] > a[largest])
    largest = left;
  if (largest != i)
    {
      int temp = a[i];
      a[i] = a[largest];
      a[largest] = temp;
      heapify (a, n, largest);
    }
}

void heapsort (int a[], int n)
{
  int i;
  for (i = n / 2 - 1; i >= 0; i--)
    {
      heapify (a, n, i);
    }
  for (i = n - 1; i > 0; i--)
    {
      int temp = a[0];
      a[0] = a[i];
      a[i] = temp;
      heapify (a, i, 0);
    }
}

void main ()
{
  int n;
  int a[100];
  printf ("enter the size of array: ");
  scanf ("%d", &n);
  printf ("enter the array elements:\n");
  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  heapsort (a, n);
  printf ("the sorted elements are: ");
  for (int i = 0; i < n; i++)
    {
      printf ("%d ", a[i]);
    }
}
