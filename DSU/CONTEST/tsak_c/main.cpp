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

ll INF = 1e9;
vector <int> p;
vector <int> rg;
map <int, vector <int>> mp;


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
    for (auto el : mp[rx])
    {
        mp[ry].push_back(el);
    }
    mp[rx].clear();
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

    rg.assign(n, 1);
    p.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        mp[i] = {i};
    }

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        unite(x, y);
    }

    for (auto el : mp)
    {
        if (el.second.size() != 0)
        {
            for (auto elem : el.second)
            {
                cout << elem + 1 << " ";
            }
            break;
        }
    }
    return 0;
}