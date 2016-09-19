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
	string S;
	cin >> S;

	int ans = INT_MAX;
	for (int i = 0; i < N; ++i) {
		int curr = 0;
		int f = 0, a = 0;
		for (int j = 0; j <= i; ++j) {
			f += (S[j] == 'F');
		}
		for (int j = i + 1; j < N; ++j) {
			a += (S[j] == 'A');
		}
		curr += (f * a);

		int targetF = i;
		for (int j = i; j >= 0; --j) {
			if (S[j] == 'F') {
				curr += (targetF - j);
				--targetF;
			}
		}
		assert(targetF == i - f);

		int targetA = i + 1;
		for (int j = i + 1; j < N; ++j) {
			if (S[j] == 'A') {
				curr += (j - targetA);
				++targetA;
			}
		}
		assert(targetA == i + 1 + a);

		ans = min(ans, curr);
	}

	cout << ans << endl;
}

