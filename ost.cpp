// Order statistics tree (GNU PBDS)
// Note: No native multiset; emulate with pair<value, unique_id>
//
// Operations (all O(log n)):
//  - it = t.find_by_order(k): 0-indexed k-th element (iterator)
//  - k = t.order_of_key(x): number of elements strictly less than x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename Key, typename T = null_type, typename Cmp = less<Key>>
using ost = tree<Key, T, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ost<int> myset;
    myset.insert(2);
    myset.insert(4);
    myset.insert(1);
    printf("%d\n", *(myset.find_by_order(0)));   // 1
    printf("%d\n", (int)myset.order_of_key(3));  // 2
    printf("%d\n", (int)myset.order_of_key(4));  // 2
    printf("%d\n", (int)myset.size());           // 3

    ost<int, char> mymap;
    mymap[2] = 'a';
    mymap[4] = 'b';
    mymap[1] = 'c';
    pair<int, char> pic = *mymap.find_by_order(0);
    printf("%d %c\n", pic.first, pic.second);    // 1 c
    printf("%d\n", (int)mymap.order_of_key(3));  // 2
    printf("%d\n", (int)mymap.order_of_key(4));  // 2
    printf("%d\n", (int)mymap.size());           // 3

    // multiset with duplicates
    ost<pair<int, int>> ms;
    int uid = 0;
    auto add = [&](int x) { ms.insert({x, uid++}); };
    auto rem = [&](int x) {  // erase one occurrence
        auto it = ms.lower_bound({x, -1});
        if (it != ms.end() && it->first == x) ms.erase(it);
    };
}
