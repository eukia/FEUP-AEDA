#include "disjointSets.h"

DisjointSets::DisjointSets()
= default;

// create n disjoint sets (one for each item)
DisjointSets::DisjointSets(int n) {
    for (int i = 0; i < n; i++)
        set.push_back(-1);
}

// Find the root of the set in which element v belongs
int DisjointSets::find(int v) const {
    if (set[v] < 0)
        return v;
    return find(set[v]);
}

// Perform Union of two subsets
void DisjointSets::unionSets(int root1, int root2) {
    set[root2] = root1;
}


int DisjointSets::getNumberOfSets() const {
    return std::count_if(set.begin(), set.end(), [](int i){
        return i == -1;
    });
}

