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

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
  vector<int> rank;
};

class Solution {
 public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    string ans;
    UnionFind uf(s.length());
    unordered_map<int, priority_queue<char, vector<char>, greater<>>> map;

    for (const vector<int>& pair : pairs)
      uf.unionByRank(pair[0], pair[1]);

    for (int i = 0; i < s.length(); ++i)
      map[uf.find(i)].push(s[i]);

    for (int i = 0; i < s.length(); ++i)
      ans += map[uf.find(i)].top(), map[uf.find(i)].pop();

    return ans;
  }
};
