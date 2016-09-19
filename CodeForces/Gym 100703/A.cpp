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
vector<pii> E[max_N];
unsigned int dist[max_N];
int popped[max_N];
string inp[max_N];

int string_diff(const string &A, const string &B);
int dijkstra(int source, int N);

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> inp[i];
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int temp = string_diff(inp[i], inp[j]);
			E[i].push_back({j, temp});
			E[j].push_back({i, temp});
		}
	}

	cout << dijkstra(1, N) << endl;
}

int string_diff(const string &A, const string &B)
{
	int ans = 0;
	for (int i = 0; i < A.length(); ++i) {
		ans = max(abs(A[i] - B[i]), ans);
	}
	return ans;
}

int dijkstra(int source, int N)
{
	priority_queue< pii, vector<pii>, greater<pii> > dfq;
	memset(dist, 0xFF, sizeof(dist));
	memset(popped, 0, sizeof(popped));

	dist[source] = 0;
	dfq.push({0, source});

	while(!dfq.empty()) {
		int u = dfq.top().second;
		dfq.pop();

		if (popped[u]) {
			continue;
		}
		popped[u] = 1;

		for (auto &temp : E[u]) {
			unsigned v, w;
			tie(v, w) = temp;
			if (dist[v] > max(dist[u], w)) {
				dist[v] = max(dist[u], w);
				dfq.push({dist[v], v});
			}
		}
	}

	unsigned ans = 0;
	for (int i = 1; i <= N; ++i) {
		ans = max(ans, dist[i]);
	}
	return (int)ans;
}
