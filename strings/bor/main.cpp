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

struct Node{
    vector <int> link = vector <int>(26, -1);
    bool term = false;
};


void insert(string s, vector <Node> &tree)
{
    int cur = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int ind = s[i] - 'a';

        if (tree[cur].link[ind] == -1)
        {
            tree.push_back(Node());
            tree[cur].link[ind] = tree.size() - 1;
        }

        cur = tree[cur].link[ind];
    }
    tree[cur].term = true;
}


void traverse(stack <int> st, int cur, vector <Node> &tree)
{
    if (tree[cur].term)
    {
        //вывести st
    }

    for (int ind = 0; ind < 26; ind++)
    {
        if (tree[cur].link[ind] >= 0)
        {
            st.push('a' + ind);
            traverse(st, tree[cur].link[ind], tree);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("two.in");`
    //ofstream cout("two.out");
    //::freopen( "negcycle.in", "r", stdin);
    //::freopen( "negcycle.out", "w", stdout);

    vector <Node> tree(1);

    return 0;
}