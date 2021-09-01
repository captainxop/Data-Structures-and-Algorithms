vector<pair<int, int>> adj[N];
vector<int> d;

void bfs(int s)
{
	d.assign(N, INF);
	deque<int> q;
	q.push_front(s);
	d[s] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop_front();

		for (auto it : adj[x]) {
			int node = it.ff, wt = it.ss;

			if (d[x] + wt < d[node]) {
				d[node] = d[x] + wt;

				if (wt == 0) q.push_front(node);
				else q.push_back(node);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << d[i] << " ";
	}
}