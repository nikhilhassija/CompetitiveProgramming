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

int main()
{
	int N;
	cin >> N;
	int Q[11], C[11], P[11], mx = 0;
	for (int i = 0; i < N; ++i) {
		cin >> Q[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
		mx = max(mx, Q[i] / C[i] + (Q[i] % C[i] > 0));
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
		ans += (mx * C[i] - Q[i]) * P[i];
	}
	cout << ans << endl;
}
