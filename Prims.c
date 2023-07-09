#include<stdio.h> 
#include<stdlib.h>

void prims (int n, int cost[10][10])
{
  int i, j, min_cost = 0, u, v, visited[10], ne = 1, min;
  for (i = 1; i <= n; i++)
    {
      visited[i] = 0;
    }
  printf ("the edges considered for MST are:\n");
  visited[1] = 1;
  while (ne < n)
    {
      min = 999;
      for (i = 1; i <= n; i++)
	{
	  for (j = 1; j <= n; j++)
	    {
	      if (cost[i][j] < min && i != j && visited[i] == 1)
		{
		  min = cost[i][j];
		  u = i;
		  v = j;
		}
	    }
	}
      if (visited[u] == 0 || visited[v] == 0)
	{
	  printf ("edge %d (%d -> %d) = %d\n", ne++, u, v, min);
	  min_cost = min_cost + min;
	  visited[v] = 1;
	}
      cost[u][v] = cost[v][u] = 999;
    }
  printf ("cost of the MST is %d", min_cost);
}

void main ()
{
  int n, i, j, cost[10][10];
  printf ("enter the number of nodes: ");
  scanf ("%d", &n);
  printf ("enter the cost matrix:\n");
  for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
	{
	  scanf ("%d", &cost[i][j]);
	  if (cost[i][j] == 0)
	    {
	      cost[i][j] = 999;
	    }
	}
      printf ("\n");
    }
  prims (n, cost);
}
