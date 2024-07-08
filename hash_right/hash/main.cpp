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
int MOD = INF + 7;
int p = 179;


int add(int a, int b, int mod)
{
    int res = a + b;
    if (res > mod)
        res -= mod;
    return res;
}


int sub(int a, int b, int mod)
{
    int res = a - b;
    if (res < 0)
        res += mod;
    return res;
}


int mult(int a, int b, int mod)
{
    return ((ll) a * b % mod);
}


void build_hash(const string &s, vector <int> &h)
{
    h[0] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        h[i + 1] = add(mult(h[i], p, MOD), s[i], MOD);
    }
}


int get_hash(int l, int r, const vector <int> &h, const vector <int> &pw)
{
    return sub(h[r + l], mult(h[l], pw[r - l + 1], MOD), MOD);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("two.in");
    //ofstream cout("two.out");
    //::freopen( "negcycle.in", "r", stdin);
    //::freopen( "negcycle.out", "w", stdout);

    string s;
    cin >> s;
    vector <int> h(s.size() + 1);

    return 0;
}