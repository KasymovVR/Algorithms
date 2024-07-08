#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>
#include <set>
#define ll long long
#define dl double long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
//#pragma GCC optimaze("O3")
//#pragma GCC optimaze("unroll-loops")
//#pragma GCC target("avx,avx2,bmi2,fma")
using namespace std;

ll INF = 1e9;

int timer = 0;
vector <int> tin;
vector <int> tout;
vector <vector <int>> g;
vector <vector <int>> up;

bool is_a_anc_b(int a, int b)
{
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}


void dfs(int v, int p)
{
    tin[v] = timer++;

    up[v][0] = p;
    for (int i = 1; i < 17; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (auto to : g[v])
    {
        if (to == p)
            continue;
        dfs(to, v);
    }

    tout[v] = timer++;
}


int lca(int a, int b)
{
    if (is_a_anc_b(a, b)) return a;
    if (is_a_anc_b(b, a)) return b;
    for (int i = 17; i >= 0; i--)
    {
        if (!is_a_anc_b(up[a][i], b))
            a = up[a][i];
    }
    return up[a][0];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("two.in");`
    //ofstream cout("two.out");
    //::freopen( "prller.in", "r", stdin);
    //::freopen( "prller.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    tin.assign(n, 0);
    tout.assign(n, 0);
    g.assign(n, vector <int> ());
    up.assign(n, vector <int> (17, 0));

    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(0, 0);


    return 0;
}

//4
//abba
//abit
//curent
//efewe