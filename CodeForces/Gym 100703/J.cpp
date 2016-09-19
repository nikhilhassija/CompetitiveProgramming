#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

template<typename has_less>
using ordered_set =
tree<has_less,
	null_type,
	less<has_less>,
	rb_tree_tag,
	tree_order_statistics_node_update>;

//insert using pref_trie.insert
//get range for prefix using pref_trie.prefix_range
//use iterator from range.first until != range.second
typedef
trie<string,
	null_type,
	trie_string_access_traits<>,
	pat_trie_tag,
	trie_prefix_search_node_update>
	pref_trie;

#define fast_cin() ios_base::sync_with_stdio(false)

const int max_N = 1e5 + 10;
const int max_P = 2e5 + 10;

int playing[max_N], thresh[max_N], bound[max_N];
ll games[max_P];
int sz[max_N], par[max_N];
vector<int> player_joining[max_P], E[max_N];

int root(int x);
void join(int a, int b);

int main()
{
	fast_cin();

	int N, M, P;
	cin >> N >> M >> P;

	set<pii> player;
	for (int i = 2; i <= N; ++i) {
		cin >> thresh[i];
		player.insert({thresh[i], i});
	}

	bound[1] = P; //will play all the games.
	for (int i = 1; i <= P; ++i) {
		cin >> games[i];
		while(!player.empty() && player.begin()->first < games[i]) {
			int idx = player.begin() -> second;
			bound[idx] = i - 1;
			player.erase(player.begin());
		}
	}
	for (auto &p : player) {
		bound[p.second] = P; //will play all the games.
	}
	for (int i = 1; i <= N; ++i) {
		player_joining[bound[i]].push_back(i);
	}
	for (int i = 1; i <= M; ++i) {
		int x, y;
		cin >> x >> y;
		E[x].push_back(y);
		E[y].push_back(x);
	}

	for (int i = 1; i <= N; ++i) {
		sz[i] = 1;
		par[i] = i;
	}

	vector<ll> ans;
	for (int i = P; i > 0; --i) {
		for (auto &p : player_joining[i]) {
			for (auto &v : E[p]) {
				if (bound[v] >= i) {
					join(p, v);
				}
			}
		}
		ans.push_back(sz[root(1)] * games[i]);
	}
	reverse(ans.begin(), ans.end());

	for (auto &x : ans) {
		cout << x << ' ';
	}
	cout << endl;
}

int root(int x)
{
	while(x != par[x]) {
		x = par[x];
	}
	return x;
}

void join(int a, int b)
{
	a = root(a);
	b = root(b);
	if (a == b) {
		return;
	} else {
		if (sz[a] > sz[b]) {
			par[b] = a;
			sz[a] += sz[b];
		} else {
			par[a] = b;
			sz[b] += sz[a];
		}
	}
}
