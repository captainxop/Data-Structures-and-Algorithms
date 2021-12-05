const int MAXN = (int)2e5 + 10;
const int LOG = 20;
vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int u, int p = -1)
{
	for (auto v : adj[u]) {
		if (v == p) continue;

		up[v][0] = u;
		depth[v] = depth[u] + 1;
		for (int j = 1; j < LOG; j++) {
			up[v][j] = up[up[v][j - 1]][j - 1];
		}

		dfs(v, u);
	}
}

int get_lca(int u, int v)
{
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	int k = depth[u] - depth[v];
	for (int j = LOG - 1; j >= 0; j--) {
		if (k & (1 << j)) {
			u = up[u][j];
		}
	}

	if (u == v) return u;

	for (int j = LOG - 1; j >= 0; j--) {
		if (up[u][j] != up[v][j]) {
			u = up[u][j];
			v = up[v][j];
		}
	}

	return up[u][0];
}

int get_distance(int u, int v)
{
	return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
}