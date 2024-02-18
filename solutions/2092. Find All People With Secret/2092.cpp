class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(id.begin(), id.end(), 0);
  }

  void unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
  }

  bool connected(int u, int v) {
    return find(u) == find(v);
  }

  void reset(int u) {
    id[u] = u;
  }

 private:
  vector<int> id;
  vector<int> rank;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                            int firstPerson) {
    vector<int> ans;
    UnionFind uf(n);
    map<int, vector<pair<int, int>>> timeToPairs;

    uf.unionByRank(0, firstPerson);

    for (const vector<int>& m : meetings)
      timeToPairs[m[2]].push_back({m[0], m[1]});

    for (const auto& [_, pairs] : timeToPairs) {
      unordered_set<int> peopleUnioned;
      for (const auto& [x, y] : pairs) {
        uf.unionByRank(x, y);
        peopleUnioned.insert(x);
        peopleUnioned.insert(y);
      }
      for (const int person : peopleUnioned)
        if (!uf.connected(person, 0))
          uf.reset(person);
    }

    for (int i = 0; i < n; ++i)
      if (uf.connected(i, 0))
        ans.push_back(i);

    return ans;
  }
};
