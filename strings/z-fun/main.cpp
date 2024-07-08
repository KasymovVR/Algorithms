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

    string st;
    cin >> st;

    vector <int> z(st.size());
    z[0] = st.size();
    int lt = 0, rt = 0;
    for (int i = 0; i < st.size(); i++)
    {
        if (i <= rt)
            z[i] = min(rt - i, z[i - lt]);
        else
            z[i] = 0;
        while (i + z[i] < st.size() && st[i + z[i]] == st[z[i]])
        {
            z[i]++;
            if (i + z[i] > rt)
            {
                lt = i;
                rt = i + z[i];
            }
        }
    }
    return 0;
}