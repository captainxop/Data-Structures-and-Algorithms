const int MAXN = (int)2e5 + 10;
const int LOG = 20;
vector<int> adj[MAXN];
int up[MAXN][LOG], depth[MAXN];

void dfs(int u, int p = -1)
{
	for (auto v : adj[u]) {
		if (v == p) continue;

		depth[v] = depth[u] + 1;
		up[v][0] = u;
		for (int j = 1; j < LOG; j++) {
			up[v][j] = up[up[v][j - 1]][j - 1];
		}

		dfs(v, u);
	}
}

int getkthAncestor(int node, int k)
{
	if (depth[node] < k) return -1;
	for (int j = LOG - 1; j >= 0; j--) {
		if (k & (1 << j)) {
			node = up[node][j];
		}
	}

	return node;
}

void preprocess()
{
	dfs(root);
}