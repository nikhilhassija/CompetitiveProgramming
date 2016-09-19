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

const int max_N = 1e3 + 10;
int P[max_N], K[max_N], R[max_N];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> K[i];
	}
	int ansP = 0, ansK = 0;
	for (int i = 0; i < N; ++i) {
		cin >> R[i];
		ansP += (abs(R[i] - P[i]) < abs(R[i] - K[i]));
		ansK += (abs(R[i] - P[i]) > abs(R[i] - K[i]));
	}
	cout << ansP << ' ' << ansK << endl;
}
