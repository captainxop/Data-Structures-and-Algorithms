Dijkstra Using Priority Queue:

vector<pair<int, int>> adj[N];
int dist[N], p[N], vis[N];

void Dijkstra(int source, int destination)
{
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
		p[i] = -1;
		vis[i] = 0;
	}

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dist[source] = 0;
	q.push({0, source});

	while (!q.empty()) {
		int x = q.top().second;
		int distance = q.top().first;
		q.pop();
		vis[x] = true;

		if (distance != dist[x]) {
			continue;
		}

		for (auto it : adj[x]) {
			int node = it.first, wt = it.second;

			if (!vis[node] && dist[x] + wt < dist[node]) {
				dist[node] = dist[x] + wt;
				p[node] = x;
				q.push({dist[node], node});
			}
		}
	}

	if (!vis[destination]) {
		cout << "No Path" << '\n';
		return;
	}

	vector<int> path;
	for (int i = destination; i != source; i = p[i]) {
		path.push_back(i);
	}
	path.push_back(source);
	reverse(path.begin(), path.end());

	for (auto it : path)
		cout << it << " ";
}

----------------------------------------------------------------------------------------------------------------------------------------

Dijkstra Using Set:

vector<pair<int, int>> adj[N];
int dist[N], p[N];

void Dijkstra(int source, int destination)
{
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
		p[i] = -1;
	}

	set<pair<int, int>> s;
	s.insert({0, source});
	dist[source] = 0;

	while (!s.empty()) {
		int x = s.begin()->second;
		s.erase(s.begin());

		for (auto it : adj[x]) {
			int node = it.first, wt = it.second;

			if (dist[x] + wt < dist[node]) {
				s.erase({dist[node], node});
				dist[node] = dist[x] + wt;
				p[node] = x;
				s.insert({dist[node], node});
			}
		}
	}

	if (dist[destination] == INF) {
		cout << "No Path" << '\n';
		return;
	}

	vi path;
	for (int i = destination; i != source; i = p[i]) {
		path.pb(i);
	}
	path.pb(source);
	reverse(all(path));

	for (auto x : path) {
		cout << x << " ";
	}
}
