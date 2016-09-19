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

const int max_N = 210;
const int max_M = 1e3 + 10;

pair<int, pii> inp[max_N][max_M];
int M[max_N], currP[max_N];

int main()
{
	fast_cin();

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> M[i];
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M[i]; ++j) {
			cin >> inp[i][j].first;
			inp[i][j].second = {i, j};
		}
		sort(inp[i] + 1, inp[i] + 1 + M[i]);
	}

	set< pair <int, pii> > curr;
	for (int i = 1; i <= N; ++i) {
		curr.insert(inp[i][1]);
		currP[i] = 1;
	}

	int ans = INT_MAX;
	while(true) {
		auto small = *curr.begin();
		auto it = curr.end();
		--it;
		auto big = *it;
		ans = min(ans, big.first - small.first);
		int i;
		i = small.second.first;
		curr.erase(small);
		if (currP[i] == M[i]) {
			break;
		} else {
			currP[i]++;
			curr.insert(inp[i][currP[i]]);
		}
	}

	cout << ans << endl;
	curr.clear();

	for (int i = 1; i <= N; ++i) {
		curr.insert(inp[i][1]);
		currP[i] = 1;
	}

	while(true) {
		auto small = *curr.begin();
		auto it = curr.end();
		--it;
		auto big = *it;
		if (big.first - small.first == ans) {
			break;
		} else {
			int i;
			i = small.second.first;
			curr.erase(small);
			if (currP[i] == M[i]) {
				break;
			} else {
				currP[i]++;
				curr.insert(inp[i][currP[i]]);
			}
		}
	}

	assert(curr.size() == N);
	vector<int> ans_actual(N + 1, 0);
	for (auto &x : curr) {
		int i, j;
		tie(i, j) = x.second;
		ans_actual[i] = j;
	}

	for (int i = 1; i <= N; ++i) {
		cout << ans_actual[i] << ' ';
	}
	cout << endl;
}
