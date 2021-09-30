const int MAXN = 2e5 + 10;
const int LOG = 20;
vector<int> adj[MAXN];
int up[MAXN][LOG];
int lv[MAXN];

void dfs(int u, int p)
{
	lv[u] = lv[p] + 1;
	up[u][0] = p;

	for (auto v : adj[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
}

void precompute()
{
	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i < n; i++) {
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}
}

int getLCA(int u, int v)
{
	if (lv[u] < lv[v])
		swap(u, v);

	int diff = lv[u] - lv[v];

	for (int j = LOG - 1; j >= 0; j--) {
		if (diff & (1 << j)) {
			u = up[u][j];
		}
	}

	if (u == v)
		return u;

	for (int j = LOG - 1; j >= 0; j--) {
		if (up[u][j] != up[v][j]) {
			u = up[u][j];
			v = up[v][j];
		}
	}

	return up[u][0];
}

int dist(int u, int v)
{
	return lv[u] + lv[v] - 2 * lv[getLCA(u, v)];
}