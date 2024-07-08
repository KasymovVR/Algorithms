#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#define ll long long
#define dl double long
#define ff first
#define ss second

using namespace std;

int INF = 1e9;
vector <int> p;
vector <int> rg;


int findrt(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = findrt(p[x]);
}


bool unite(int x, int y)
{
    int rx = findrt(x);
    int ry = findrt(y);
    if (rx == ry)
        return false;

    if (rg[rx] > rg[ry])
        swap(rx, ry);
    p[rx] = ry;
    rg[ry] += rg[rx];
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("two.in");
    //ofstream cout("two.out");

    int n;
    cin >> n;

    p.assign(n, 0);
    rg.assign(n, 1);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }

    int m;
    cin >> m;
    vector <array <int, 4>> len(m);
    for (int i = 0; i < m; i++)
    {
        int x, y, l;
        cin >> x >> y >> l;
        x--;
        y--;
        len[i] = {l, x, y, i + 1};
    }
    sort(len.begin(), len.end());

    int p5, q5, p6, q6;
    cin >> p5 >> q5 >> p6 >> q6;
    bool f = false;
    if (p6 < p5)
    {
        swap(p5, p6);
        swap(q5, q6);
        f = true;
    }

    int cnt = 0, sm = 0;
    vector <pair <int, int>> res;
    for (auto el : len)
    {
        int l = el[0], x = el[1], y = el[2];
        if (unite(x, y))
        {
            cnt++;
            sm += l;
            res.push_back({l, el[3]});
        }

        if (cnt == n - 1)
            break;
    }
//до этого места всё работает, наверное______________________________________________________
    if (sm > q5 + q6 || cnt != n - 1)
    {
        cout << "Impossible";
    }
    else
    {
// рюкзак__________________________________________________________________________

        int t = q5;
        vector <vector <int>> dp(n, vector <int> (t + 1, -INF));
        dp[0][0] = 1;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j <= t; j++)
            {
                dp[i + 1][j] = dp[i][j];
                if (res[i].ff <= j && dp[i][j - res[i].ff] != -INF)
                {
                    dp[i + 1][j] = 1;
                }
            }
        }

        int a = 0, ind = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = t; j >= 0; j--)
            {
                if (dp[i][j] == 1 && j > a)
                {
                    a = j;
                    ind = i;
                    break;
                }
            }
        }

        set <int> st;
        int ti = ind, tj = a;
        while (ti > 0 && tj >= res[ti - 1].ff)
        {
            if (dp[ti - 1][tj] != dp[ti][tj])
            {
                st.insert(res[ti - 1].ss);
                tj -= res[ti - 1].ff;
            }
            ti--;
        }
//конеу рюкзака________________________________________________________________________
        int len_q6 = 0;
        for (auto el : res)
        {
            if (st.find(el.ss) == st.end())
            {
                len_q6 += el.ff;
            }
        }
        if (len_q6 > q6)
        {
            cout << "Impossible";
        }
        else
        {
            int t_sm = 0;
            vector <pair <int, int>> answer;
            for (auto el : res)
            {
                if (st.find(el.ss) != st.end())
                {
                    answer.push_back({el.ss, 5});
                    t_sm += p5 * el.ff;
                }
                else
                {
                    answer.push_back({el.ss, 6});
                    t_sm += p6 * el.ff;
                }
            }

            cout << t_sm << "\n";
            sort(answer.begin(), answer.end());
            for (auto el : answer)
            {
                cout << el.ff << " ";
                if (f)
                {
                    if (el.ss == 5)
                    {
                        cout << 6 << "\n";
                    }
                    else
                    {
                        cout << 5 << "\n";
                    }
                }
                else
                {
                    if (el.ss == 6)
                    {
                        cout << 6 << "\n";
                    }
                    else
                    {
                        cout << 5 << "\n";
                    }
                }
            }
        }
    }
    return 0;
}