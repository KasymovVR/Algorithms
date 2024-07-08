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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("fenwik.in");
    //ofstream cout("fenwik.out");
    //::freopen("fenwik.in", "r", stdin);
    //::freopen("fenwik.out", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);
        vector <int> pref(n);
        int fir = -1, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i > 0)
                pref[i] = pref[i - 1];
            if (a[i])
            {
                cnt++;
                if (fir == -1)
                    fir = i;
            }
            else
            {
                if (fir != -1)
                    pref[i]++;
            }
        }

        int fin = fir, ans = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i])
            {
                int ind = i;
                while (ind >= 0 && a[ind])
            }
        }
    }
    return 0;
}
