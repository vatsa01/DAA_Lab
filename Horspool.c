#include<stdio.h>
#include<stdlib.h>

void main ()
{
  int n, m, k, i;
  int table[256];
  char t[200], p[100];
  printf ("enter the text: ");
  gets (t);
  printf ("enter the pattern: ");
  gets (p);
  n = strlen (t);
  m = strlen (p);
  for (i = 0; i < 256; i++)
    {
      table[i] = m;
    }
  for (int j = 0; j < m - 1; j++)
    {
      table[p[j]] = m - j - 1;
    }
  i = m - 1;
  while (i < n)
    {
      k = 0;
      while (k < m && (p[m - 1 - k] == t[i - k]))
	k++;
      if (k == m)
	{
	  printf ("pattern found in the position %d", i - m + 2);
	  break;
	}
      else
	i = i + table[t[i]];
    }
  if (k != m)
    {
      printf ("pattern not found in the text\n");
    }
}
