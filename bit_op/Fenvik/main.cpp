#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <stack>
#include <set>
#define ll long long
#define dl double long
#define ff first
#define ss second

using namespace std;

ll INF = 1e18;
ll MOD = INF + 7;

vector <int> b;

int get(int k) //log2(n)
{
    int s = 0;
    for (int t = k; t >= 0; t = (t & (t + 1)) - 1)
    {
        s += b[t];
    }
    return s;
}


void upd(int k, int x) //log2(n)
{
    for (int t = k; t < b.size(); t = t | (t + 1))
    {
        b[t] += x;
    }
}


void build(int n,  vector <int> &a) //n
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("two.in");
    //ofstream cout("two.out");



    return 0;
}