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
int n;
int l[200], r[200];
int inv[30000];
int ans;
int maxr;

int sum(int l, int r)
{
	if (l > r)
	{
		return 0;
	}
	return (long long)(l + r) * (r - l + 1) % M * inv[2] % M;
}

int main()
{
	inv[1] = 1;
	for (int i = 2; i <= 20000; i++)
	{
		inv[i] = (long long)(M - M / i) * inv[M % i] % M;
	}
	scanf("%d", &T);
	while (T--)
	{
		maxr = 0;
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			l[i] = read();
			r[i] = read();
			maxr = std::max(maxr, r[i]);
		}
		for (int i = 1; i <= maxr + 5; i++)
		{
			int nows = 1, pres = 1;
			for (int j = 1; j <= n; j++)
			{
				if (i < l[j])
				{
					nows = 0;
					pres = 0;
					break;
				}
				if (i > r[j])
				{
					nows = (long long)nows * sum(i - r[j] + 1, i - l[j] + 1) % M;
					pres = (long long)pres * sum(i - r[j] + 1, i - l[j] + 1) % M;
				}
				else
				{
					nows = (long long)nows * sum(1, i - l[j] + 1) % M;
					pres = (long long)pres * sum(2, i - l[j] + 1) % M;
				}
			}
			ans = (ans + ((nows - pres) % M + M) % M) % M;
		}
		for (int i = 1; i <= n; i++)
		{
			ans = (long long)ans * inv[r[i] - l[i] + 1] % M;
		}
		printf("%d\n", ans);
	}
	return 0;
}
