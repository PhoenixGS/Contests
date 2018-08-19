#include <cstdio>
#include <algorithm>

long long read()
{
	char last = '+', ch = getchar();
	while (ch < '0' || ch > '9') last = ch, ch = getchar();
	long long tmp = 0;
	while (ch >= '0' && ch <= '9') tmp = tmp * 10 + ch - 48, ch = getchar();
	if (last == '-') tmp = -tmp;
	return tmp;
}

const int M = 1000000007;
int T;
int n, m;
int x[200000];
int edgenum;
int vet[300000], nextx[300000], head[200000];
int vis[200000];
int last;
int v[200000];
int ans;

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

void dfs(int u)
{
	vis[u] = 1;
	last++;
	v[last] = x[u];
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (! vis[v])
		{
			dfs(v);
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		edgenum = 0;
		for (int i = 1; i <= n; i++)
		{
			head[i] = 0;
			vis[i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			x[i] = read();
		}
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			u = read();
			v = read();
			add(u, v);
			add(v, u);
		}
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (! vis[i])
			{
				last = 0;
				dfs(i);
				std::sort(v + 1, v + last + 1);
				for (int j = 0; j < 31; j++)
				{
					int cnt = 0;
					for (int k = 1; k <= last; k++)
					{
						if (v[k] & (1 << j))
						{
							ans = ((long long)ans + (long long)(1 << j) * cnt % M * v[k] % M) % M;
							cnt++;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
