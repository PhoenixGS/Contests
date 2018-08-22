#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>

struct node
{
    int x, y, cas;
};

const int INF = 1000000000;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int T;
int n, m, K;
int x[30][30];
int trans[1000];
int f[300][30][30];
std::queue<node> que;
int ans;

int solve()
{
    while (! que.empty())
    {
        que.pop();
    }
    for (int i = 1; i <= n * m; i++)
    {
        trans[i] = rand() % K;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < (1 << K); k++)
            {
                f[i][j][k] = INF;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i][j] > 0)
            {
                f[i][j][1 << trans[x[i][j]]] = 0;
                que.push((node){i, j, x[i][j] == 0 ? 0 : (1 << trans[x[i][j]])});
            }
        }
    }
    while (! que.empty())
    {
        node tmp = que.front();
        que.pop();
        int xx = tmp.x;
        int yy = tmp.y;
        int cas = tmp.cas;
        for (int i = 0; i < 4; i++)
        {
            int xxx = xx + dx[i];
            int yyy = yy + dy[i];
            if (xxx >= 1 && xxx <= n && yyy >= 1 && yyy <= m && x[xxx][yyy] != -1)
            {
                int cass = tmp.cas | (x[xxx][yyy] == 0 ? 0 : (1 << trans[x[xxx][yyy]]));
                if (f[xx][yy][cas] + 1 < f[xxx][yyy][cass])
                {
                    f[xxx][yyy][cass] = f[xx][yy][cas] + 1;
                    que.push((node){xxx, yyy, cass});
                    if (cass == (1 << K) - 1)
                    {
                        return f[xxx][yyy][cass];
                    }
                }
            }
        }
    }
    return INF;
}

int main()
{
    srand(time(NULL));
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &K);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &x[i][j]);
            }
        }
        ans = INF;
        for (int i = 1; i <= 500; i++)
        {
            ans = std::min(ans, solve());
        }
        printf("%d\n", ans == INF ? -1 : ans);
    }
    return 0;
}
