#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <cmath>
#include <array>
#include <queue>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <iomanip>
#define ll long long
#define dl double long
#define ff first
#define ss second

using namespace std;

ll INF = 1e9;
ll MOD = INF + 7;

vector <int> b;


ll get(int k)
{
    int s = 0;
    for (int i = k; i >= 0; i = (i & (i + 1)) - 1)
    {
        s += b[i];
    }
    return s;
}


void upd(int k, int d)
{
    for (int i = k; i < b.size(); i = (i | (i + 1)))
    {
        b[i] += d;
    }
}


void build(int n, vector <int> &a)
{
    b.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        b[i] += a[i];
        if ((i | (i + 1)) < n)
            b[i | (i + 1)] += b[i];
    }
}


int main() {
    //ios_base::sync_with_stdio(false);
    //ifstream cin("fenwik.in");
    //ofstream cout("fenwik.out");
    //::freopen("fenwik.in", "r", stdin);
    //::freopen("fenwik.out", "w", stdout);

    b.assign(1e6, 0);

    string st;
    cin >> st;

    int cnt = 0, ans = 0;
    while (st != "QUIT")
    {
        if (st == "BID")
        {
            double x;
            cin >> x;
            x *= 100;
            int y = x;
            upd(y, 1);
            cnt++;
        }
        else if (st == "SALE")
        {
            double x;
            int y, c;
            cin >> x >> c;
            y = x * 100;
            ans += cnt - get(x);
        }
        else
        {
            double x;
            int y;
            cin >> x;
            y = x * 100;
            cnt--;
            upd(x, -1);
        }
    }

    double res = ans;
    printf()
    return 0;
}
