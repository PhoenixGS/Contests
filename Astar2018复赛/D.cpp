#include <cstdio>
#include <vector>
#include <algorithm>

struct node
{
	int x[5];
};

const int M = 1000000007;
int T;
int k, n;
int x[10][2000];
std::vector<int> vec[10][2000];
int last;
node v[500000];
int tmp[100];
int ans;
int f[500000];

bool comp(node x, node y)
{
	for (int i = 0; i < k; i++)
	{
		if (x.x[i] < y.x[i])
		{
			return true;
		}
		if (x.x[i] > y.x[i])
		{
			return false;
		}
	}
	return false;
}

bool cmp(node x, node y)
{
	for (int i = 0; i < k; i++)
	{
		if (! (x.x[i] < y.x[i]))
		{
			return false;
		}
	}
	return true;
}

void dfs(int t, int cas)
{
	if (t > k)
	{
		last++;
		for (int i = 0; i < k; i++)
		{
			v[last].x[i] = tmp[i + 1];
		}
		return;
	}
	for (int i = 0; i < (int)vec[t][cas].size(); i++)
	{
		tmp[t] = vec[t][cas][i];
		dfs(t + 1, cas);
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &k, &n);
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				vec[i][j].clear();
			}
		}
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &x[i][j]);
				vec[i][x[i][j]].push_back(j);
			}
		}
		last = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				tmp[j] = 0;
			}
			dfs(1, i);
		}
		std::sort(v + 1, v + last + 1, comp);
		ans = 0;
		for (int i = 1; i <= last; i++)
		{
			f[i] = 1;
			for (int j = 1; j < i; j++)
			{
				if (cmp(v[j], v[i]))
				{
					f[i] = (f[i] + f[j]) % M;
				}
			}
			ans = (ans + f[i]) % M;
		}
		printf("%d\n", ans);
	}
	return 0;
}
