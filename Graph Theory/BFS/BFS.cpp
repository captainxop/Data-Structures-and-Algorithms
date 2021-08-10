// dist[] stores the levels of the node from the source node

const int N = 2e5;
vector<int> adj[N];
int vis[N], dist[N];

void BFS(int s)
{
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	dist[s] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		// cout << node << '\n';

		for (auto it : adj[node]) {
			if (!vis[it]) {
				q.push(it);
				vis[it] = 1;
				dist[it] = dist[node] + 1;
			}
		}
	}
}