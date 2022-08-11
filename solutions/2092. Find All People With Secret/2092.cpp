class UF {
 public:
  UF(int n) : id(n) {
    iota(begin(id), end(id), 0);
  }

  void union_(int u, int v) {
    id[find(u)] = id[find(v)];
  }

  bool connected(int u, int v) {
    return find(u) == find(v);
  }

  void reset(int u) {
    id[u] = u;
  }

 private:
  vector<int> id;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                            int firstPerson) {
    vector<int> ans;
    UF uf(n);
    map<int, vector<pair<int, int>>> timeToPairs;

    uf.union_(0, firstPerson);

    for (const auto& m : meetings)
      timeToPairs[m[2]].push_back({m[0], m[1]});

    for (const auto& [_, pairs] : timeToPairs) {
      unordered_set<int> peopleUnioned;
      for (const auto& [x, y] : pairs) {
        uf.union_(x, y);
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
