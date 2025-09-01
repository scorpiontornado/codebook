// Union find (DSU), size heuristic + path compression
// From UNSW COMP4128 lecture slides, topic 4. Data Structures
// TODO: wrap all in struct? Eg atcoder library / dsu class
// https://codeforces.com/contest/2135/submission/335965466

const int N = 100100;  //! change as necessary
int parent[N];
int subtree_size[N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        subtree_size[i] = 1;
    }
}

int root(int x) {
    // only roots are their own parents
    // otherwise apply path compression
    return parent[x] == x ? x : parent[x] = root(parent[x]);
}

void join(int x, int y) {
    // join roots
    x = root(x);
    y = root(y);
    // test whether already connected
    if (x == y) return;
    // size heuristic
    // hang smaller subtree under root of larger subtree
    if (subtree_size[x] < subtree_size[y]) {
        parent[x] = y;
        subtree_size[y] += subtree_size[x];
    } else {
        parent[y] = x;
        subtree_size[x] += subtree_size[y];
    }
}
