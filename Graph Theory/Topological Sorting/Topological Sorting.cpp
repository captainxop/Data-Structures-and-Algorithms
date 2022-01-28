vector<bool> visited(300010, 0), stk(300010, 0);
vector<int> toposort; // Stores the Topological Order

bool check_cycle(int u)
{
	visited[u] = 1;
	stk[u] = 1;

	for (auto v : adj[u]) {
		if (!visited[v]) {
			bool cycle = check_cycle(v);
			if (cycle) {
				return true;
			}
		}
		else if (stk[v]) {
			return true;
		}
	}

	stk[u] = 0;
	return false;
}

void dfs(int u)
{
	visited[u] = 1;

	for (auto v : adj[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}

	toposort.push_back(u);
}

reverse(toposort.begin(), toposort.end());