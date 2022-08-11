class UF {
 public:
  UF(int n) : count(n), id(n), size(n, 1), rank(n) {
    iota(begin(id), end(id), 0);
  }

  void union_(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = id[j];
      size[j] += size[i];
    } else if (rank[i] > rank[j]) {
      id[j] = id[i];
      size[i] += size[j];
    } else {
      id[i] = id[j];
      size[j] += size[i];
      ++rank[j];
    }
    --count;
  }

  int getCount() const {
    return count;
  }

  int getMaxSize() const {
    return *max_element(begin(size), end(size));
  }

 private:
  int count;
  vector<int> id;
  vector<int> size;
  vector<int> rank;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  vector<int> groupStrings(vector<string>& words) {
    UF uf(words.size());
    unordered_map<int, int> maskToIndex;
    unordered_map<int, int> deletedMaskToIndex;

    for (int i = 0; i < words.size(); ++i) {
      const int mask = getMask(words[i]);
      for (int j = 0; j < 26; ++j)
        if (mask >> j & 1) {
          // going to delete this bit
          const int m = mask ^ 1 << j;
          if (maskToIndex.count(m))
            uf.union_(i, maskToIndex[m]);
          if (deletedMaskToIndex.count(m))
            uf.union_(i, deletedMaskToIndex[m]);
          else
            deletedMaskToIndex[m] = i;
        } else {
          // going to add this bit
          const int m = mask | 1 << j;
          if (maskToIndex.count(m))
            uf.union_(i, maskToIndex[m]);
        }
      maskToIndex[mask] = i;
    }

    return {uf.getCount(), uf.getMaxSize()};
  }

 private:
  int getMask(const string& s) {
    int mask = 0;
    for (const char c : s)
      mask |= 1 << c - 'a';
    return mask;
  }
};
