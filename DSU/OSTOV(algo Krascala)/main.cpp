#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#define ll long long
#define dl double long
#define ff first
#define ss second

using namespace std;

ll INF = 1e9;
vector <int> p;
vector <int> rg;


int findrt(int x)
{
    if (p[x] == x)
    {
        return x;
    }
    return p[x] = findrt(p[x]);
}


bool unite(int x, int y)
{
    int rx = findrt(x);
    int ry = findrt(y);
    if (rx == ry)
        return false;
    if (rg[rx] > rg[ry])
    {
        swap(rx, ry);
    }
    p[rx] = ry;
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
    rg.assign(n, 0);

    //init:
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        rg[i] = 1;
    }
    return 0;
}

//1. Сортируем рёбра по весам
//2. Для всех рёбер е(а, b) если а и d не соединены, то соединить компоненты связности а и b