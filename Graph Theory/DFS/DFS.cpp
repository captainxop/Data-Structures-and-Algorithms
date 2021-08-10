const int N = 2e5;
vector<int> adj[N];
int vis[N];

void DFS(int s)
{
	vis[s] = 1;

	// cout << s << '\n';

	for (auto node : adj[s]) {
		if (!vis[node])
			DFS(node);
	}
}