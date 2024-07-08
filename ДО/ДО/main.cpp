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

ll INF = 1e9;
ll MOD = INF + 7;

vector <int> b;
vector <int> tree;

int get(int ind, int nl, int nr, int ql, int qr) //4 * log2(qr - ql)
{
    if (nr < ql || qr < nl) //[nl, nr] не пересекается с [ql, qr]
        return 0;

    if (ql <= nl && nr <= qr) // [nl, nr] целиком принадлежит [ql, qr]
        return tree[ind];

    int m = (nl + nr) / 2, ls = 2 * ind, rs = 2 * ind + 1;
    int ansl = get(ls, nl, m, ql, qr);
    int ansr = get(rs, m + 1, nr, ql, qr);

    return ansl + ansr;
}


void upd(int ind, int nl, int nr, vector <int> &arr, int i, int v) //
{
    if (nl == nr)
    {
        arr[nl] += v;
        tree[ind] = arr[nl];
        return;
    }

    int m = (nl + nr) / 2, ls = 2 * ind, rs = 2 * ind + 1;
    if (nl <= i && i <= m)
        upd(ls, nl, m, arr, i, v);
    if (m + 1 <= i && i <= nr)
        upd(rs, m + 1, nr, arr, i, v);

    tree[ind] = tree[ls] + tree[rs];
}


void build(int ind, int nl, int nr, vector <int> &arr) //n
{
    if (nl == nr)
    {
        tree[ind] = arr[nl];
        return;
    }

    int m = (nl + nr) / 2, ls = 2 * ind, rs = 2 * ind + 1;
    build(ls, nl, m, arr);
    build(rs, m + 1, nr, arr);

    tree[ind] = tree[ls] + tree[rs];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("two.in");
    //ofstream cout("two.out");

    int n;
    cin >> n;

    vector <int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    tree.assign(4 * n, 0);
    build(1, 0, n - 1, vec);
    return 0;
}