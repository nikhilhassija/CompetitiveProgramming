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
const int max_K = 1e3 + 10;

int prevInd[max_N][max_K];
int C[max_N];

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> C[i];
	}
	memset(prevInd, -1, sizeof(prevInd));
	prevInd[0][0] = 0;

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int k = 0; k <= K; ++k) {
			if (k + C[i] <= K && prevInd[i - 1][k + C[i]] != -1) {
				prevInd[i][k] = k + C[i];
				ans = i;
			} else if (k - C[i] >= 0 && prevInd[i - 1][k - C[i]] != -1) {
				prevInd[i][k] = k - C[i];
				ans = i;
			}
		}
	}

	cout << ans << endl;
	int sp = 0;
	for (sp; sp <= K && prevInd[ans][sp] == -1; ++sp)
		;
	assert(sp <= K && prevInd[ans][sp] != -1);

	string temp = "";
	for (int i = ans; i > 0; --i) {
		int nxp = prevInd[i][sp];
		if (nxp < sp) {
			temp += '+';
		} else {
			temp += '-';
		}
		sp = nxp;
	}
	reverse(temp.begin(), temp.end());
	cout << temp << endl;
}
