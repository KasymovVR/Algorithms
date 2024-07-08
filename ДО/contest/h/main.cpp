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

struct Poll{
    ll x;
    ll y;
};

struct Segment{
    Poll st;
    Poll fn;
};


ll n;
vector <ll> vec;
vector <array <ll, 4>> px;
vector <array <ll, 4>> py;
vector <Segment> seg;
vector <Segment> seg_new;
vector <Segment> seg_comp;
map <ll, ll> comp;

vector <ll> b;
vector <ll> tree;

ll get(ll ind, ll nl, ll nr, ll ql, ll qr)
{
    if (nr < ql || qr < nl)
        return 0;

    if (ql <= nl && nr <= qr)
        return tree[ind];

    ll m = (nl + nr) / 2, ls = 2 * ind, rs = 2 * ind + 1;
    ll ansl = get(ls, nl, m, ql, qr);
    ll ansr = get(rs, m + 1, nr, ql, qr);

    return ansl + ansr;
}


void upd(ll ind, ll nl, ll nr, ll i, ll v)
{
    if (nl == nr)
    {
        tree[ind] += v;
        return;
    }

    ll m = (nl + nr) / 2, ls = 2 * ind, rs = 2 * ind + 1;
    if (nl <= i && i <= m)
        upd(ls, nl, m, i, v);
    if (m + 1 <= i && i <= nr)
        upd(rs, m + 1, nr, i, v);

    tree[ind] = tree[ls] + tree[rs];
}


void compression()
{
    std::sort(vec.begin(), vec.end());
    auto last = unique(vec.begin(), vec.end());
    vec.resize(last - vec.begin());

    for (ll i = 0; i < vec.size(); i++)
    {
        comp[vec[i]] = i;
    }
}


ll coutn_sq_x()
{
    ll ans = 0;
    map <ll, pair <ll, ll>> used;
    for (auto el : px)
    {
        if (el[1] == 0)
        {
            if (used[seg[el[2]].st.y].ss == 0)
            {
                used[seg[el[2]].st.y].ff = el[2];
                used[seg[el[2]].st.y].ss = 1;
            }
            else
                used[seg[el[2]].st.y].ss++;
        }
        else
        {
            used[seg[el[2]].st.y].ss--;
            if (!used[seg[el[2]].st.y].ss)
            {
                seg_new.push_back({seg[used[seg[el[2]].st.y].ff].st.x, seg[used[seg[el[2]].st.y].ff].st.y, el[0], el[3]});
                ans += el[0] - seg[used[seg[el[2]].st.y].ff].st.x + 1;
            }
        }
    }
    return ans;
}


ll coutn_sq_y()
{
    ll ans = 0;
    map <ll, pair <ll, ll>> used;
    for (auto el : py)
    {
        if (el[1] == 0)
        {
            if (used[seg[el[2]].st.x].ss == 0)
            {
                used[seg[el[2]].st.x].ff = el[2];
                used[seg[el[2]].st.x].ss = 1;
            }
            else
                used[seg[el[2]].st.x].ss++;
        }
        else
        {
            used[seg[el[2]].st.x].ss--;
            if (!used[seg[el[2]].st.x].ss)
            {
                seg_new.push_back({seg[used[seg[el[2]].st.x].ff].st.x, seg[used[seg[el[2]].st.x].ff].st.y, el[3], el[0]});
                ans += el[0] - seg[used[seg[el[2]].st.x].ff].st.y + 1;
            }
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("two.in");
    //ofstream cout("two.out");

    cin >> n;

    vec.resize(4 * n);

    seg.resize(n);
    set <int> test;
    for (ll i = 0; i < n; i++)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        test.insert(x1);
        test.insert(y1);
        test.insert(x2);
        test.insert(y2);
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        vec[i * 4] = x1;
        vec[i * 4 + 1] = y1;
        vec[i * 4 + 2] = x2;
        vec[i * 4 + 3] = y2;

        if (x1 == x2)
        {
            py.push_back({y1, 0, i, x1});
            py.push_back({y2, 1, i, x2});
        }
        else
        {
            px.push_back({x1, 0, i, y1});
            px.push_back({x2, 1, i, y2});
        }

        seg[i] = {x1, y1, x2, y2};
    }
    std::sort(px.begin(), px.end());
    std::sort(py.begin(), py.end());

    //compression;

    ll sq = 0;
    sq += coutn_sq_x();
    sq += coutn_sq_y();
    //cout << sq << "\n";

    compression();
    ll m = seg_new.size();
    seg_comp.resize(m);
    for (ll i = 0; i < m; i++)
    {
        seg_comp[i] = {comp[seg_new[i].st.x], comp[seg_new[i].st.y], comp[seg_new[i].fn.x], comp[seg_new[i].fn.y]};
    }

//    for (auto el : seg_comp)
//        cout << el.st.x << " " << el.st.y << " " << el.fn.x << " " << el.fn.y << "\n";

    vector <vector <ll>> sl;
    for (ll i = 0; i < m; i++)
    {
        //cout << seg_comp[i].st.x << " " << seg_comp[i].st.y << " " << seg_comp[i].fn.x << " " << seg_comp[i].fn.y << "\n";
        if (seg_comp[i].st.x == seg_comp[i].fn.x)
        {
            sl.push_back({seg_comp[i].st.y, 0, i, seg_comp[i].st.x});
            sl.push_back({seg_comp[i].fn.y, 2, i, seg_comp[i].st.x});
        }
        else
        {
            sl.push_back({seg_comp[i].st.y, 1, i, seg_comp[i].st.x, seg_comp[i].fn.x});
        }
    }
    //cout << "\n";

    std::sort(sl.begin(), sl.end());

    tree.assign(4 * comp.size(), 0);
    for (auto el : sl)
    {
//        for (auto el2  : el)
//            cout << el2 << " ";
//        cout << "\n";
        if (el[1] == 0)
        {
            upd(1, 0, comp.size() - 1, el[3], 1);
        }
        else if (el[1] == 2)
        {
            upd(1, 0, comp.size() - 1, el[3], -1);
        }
        else
        {
            //cout << el[0] << " " << el[3] << " " << el[4] << " " << get(1, 0, comp.size() - 1, el[3], el[4]) << "\n";
            sq -= get(1, 0, comp.size() - 1, el[3], el[4]);
        }
    }

    cout << sq << "\n";
    return 0;
}