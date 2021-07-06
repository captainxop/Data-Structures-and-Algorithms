Floyd-Warshall with Path:-
    
int dist[N][N], p[N][N];

void FloydWarshall(int n, int source, int destination)
{
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    p[i][j] = p[i][k];
                }
            }
        }
    }
    
    if (p[source][destination] == -1) {
        cout << "No Path" << '\n';
        return;
    }
    
    vector<int> path;
    path.push_back(source);
    while (source != destination) {
        source = p[source][destination];
        path.push_back(source);
    }
    
    for (auto x : path) 
        cout << x << " ";
}
