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

const long long INF = (long long)1000000000 * 1000000000;
int T;
int n;
int fa[200000];
int x[200000];
long long maxx[200000], maxy[200000], minx[200000], miny[200000];
long long ansmax, ansmin;
long long maxmaxy, minminy;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 2; i <= n; i++)
		{
			fa[i] = read();
		}
		for (int i = 1; i <= n; i++)
		{
			x[i] = read();
		}
		for (int i = 0; i <= n; i++)
		{
			maxx[i] = maxy[i] = -INF;
			minx[i] = miny[i] = INF;
		}
		for (int i = 1; i <= n; i++)
		{
			if (x[i] > maxx[fa[i]])
			{
				maxy[fa[i]] = maxx[fa[i]];
				maxx[fa[i]] = x[i];
			}
			else
			{
				if (x[i] > maxy[fa[i]])
				{
					maxy[fa[i]] = x[i];
				}
			}
			if (x[i] < minx[fa[i]])
			{
				miny[fa[i]] = minx[fa[i]];
				minx[fa[i]] = x[i];
			}
			else
			{
				if (x[i] < miny[fa[i]])
				{
					miny[fa[i]] = x[i];
				}
			}
		}
		ansmax = 0;
		maxmaxy = -INF;
		for (int i = 0; i <= n; i++)
		{
			ansmax += std::max(0ll, maxx[i]);
			maxmaxy = std::max(maxmaxy, maxy[i]);
		}
		ansmax += std::max(0ll, maxmaxy);
		ansmin = 0;
		minminy = INF;
		for (int i = 0; i <= n; i++)
		{
			ansmin += std::min(0ll, minx[i]);
			minminy = std::min(minminy, miny[i]);
		}
		ansmin += std::min(0ll, minminy);
		printf("%lld %lld\n", ansmax, ansmin);
	}
	return 0;
}
