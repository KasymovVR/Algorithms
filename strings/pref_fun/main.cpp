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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("two.in");`
    //ofstream cout("two.out");
    //::freopen( "negcycle.in", "r", stdin);
    //::freopen( "negcycle.out", "w", stdout);

    string s;
    cin >> s;
    int n = s.size();

    vector <int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int cur = p[i - 1];
        while (cur > 0 && s[cur] != s[i])
            cur = p[cur - 1];

        if (s[cur] != s[i])
            p[i] = cur + 1;
    }
    return 0;
}