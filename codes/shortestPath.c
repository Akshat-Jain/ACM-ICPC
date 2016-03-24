//Djikstra's Shortest Path
#include <stdio.h>
#define MAX 0X7FFFFFFF
int g[101][101];
int used[101];
int dist[101];

int main ()
{
	int n,m,start,end;
	int i,j,a,b,x;
	int min,current;

	scanf ("%d %d", &n, &m);
	scanf ("%d %d", &start, &end);
	for (i=0; i<m; ++i) {
		scanf ("%d %d %d", &a, &b, &x);
		g[a][b] = g[b][a] = x;
	}

	current = start;
	used[current] = 1;
	for (i=0; i<n; ++i) {
		
		for (j=1; j<=n; ++j) {
			if (g[current][j] && !used[j])
				if (!dist[j] || dist[j]>dist[current]+g[current][j])
					dist[j] = dist[current]+g[current][j];
		}
		
		min = MAX;
		for (j=1; j<=n; ++j) {
			if (dist[j] && !used[j])
				if (dist[j] < min) {
					current = j;
					min = dist[j];
				}
		}
		used[current] = 1;
	}	
	printf ("%d\n", dist[end]);

	return 0;
}
