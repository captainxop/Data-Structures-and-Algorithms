const int MaxN = 1e5 + 10;
int n, m;

struct Edge {
	int u, v, wt;
};

Edge edges[MaxN], MST[MaxN];
int p[MaxN], r[MaxN];

void init()
{
	for (int i = 0; i < MaxN; i++) {
		p[i] = i;
		r[i] = 1;
	}
}

int find_set(int x)
{
	if (x == p[x])
		return x;

	return p[x] = find_set(p[x]);
}

void merge(int a, int b)
{
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		if (r[a] < r[b])
			swap(a, b);

		p[b] = a;
		r[a] += r[b];
	}
}

void addEdge(Edge &e, int u, int v, int wt)
{
	e.u = u, e.v = v, e.wt = wt;
}

bool comp(Edge &e1, Edge &e2)
{
	return e1.wt < e2.wt;
}

int krsukalMST(int m)
{
	init();
	int cost = 0, count = 0;
	sort(edges, edges + m, comp);

	for (int i = 0; i < m; i++) {
		int u = edges[i].u, v = edges[i].v, wt = edges[i].wt;
		u = find_set(u);
		v = find_set(v);

		if (u != v) {
			cost += wt;
			addEdge(MST[count], u, v, wt);
			merge(u, v);
			count++;
		}
	}

	return cost;
}