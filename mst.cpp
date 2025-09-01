// From UNSW COMP4128 lecture code, topic 4. Data Structures
// TODO: clean up? e.g. add N, perhaps add union find code

/*
 * kruskal
 */

struct edge {
    int u, v, w;
};  // endpoint, endpoint, weight
bool operator<(const edge& a, const edge& b) { return a.w < b.w; }

edge edges[N];

int root(int u);          // union-find root with path compression
void join(int u, int v);  // union-find join with size heuristic

long long kruskal() {
    sort(edges, edges + m);  // sort by increasing weight
    long long total_weight = 0;
    for (int i = 0; i < m; i++) {
        edge& e = edges[i];
        // if the endpoints are in different trees, join them
        if (root(e.u) != root(e.v)) {
            total_weight += e.w;
            join(e.u, e.v);
        }
    }
    return total_weight;
}

/*
 * prim
 */

typedef pair<int, int> ii;

vector<ii> edges[N];  // (weight, destination)
bool in_tree[N];
// use 'greater' comparator for min-heap
priority_queue<ii, vector<ii>, greater<ii>> pq;

long long prim() {
    long long total_weight = 0;
    pq.emplace(0, 0);  // start at vertex 0 with total 0
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int weight = cur.first, v = cur.second;
        // if this vertex was already seen before
        // it must have been seen at a better distance
        if (in_tree[v]) {
            continue;
        }
        in_tree[v] = true;
        total_weight += weight;
        // add all edges from this vertex
        for (auto nxt : edges[v]) {
            pq.push(nxt);
        }
    }
    return total_weight;
}
