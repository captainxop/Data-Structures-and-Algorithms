const int MaxN = 1e5 + 10;
int n, m;

struct Edge {
	int u, v, w;
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

void addEdge(Edge &e, int u, int v, int w)
{
	e.u = u, e.v = v, e.w = w;
}

bool comp(Edge &e1, Edge &e2)
{
	return e1.w < e2.w;
}

int krsukalMST(int m)
{
	init();
	int cost = 0, count = 0;
	sort(edges, edges + m, comp);

	for (int i = 0; i < m; i++) {
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		u = find_set(u);
		v = find_set(v);

		if (u != v) {
			cost += w;
			addEdge(MST[count], u, v, w);
			merge(u, v);
			count++;
		}
	}

	return cost;
}