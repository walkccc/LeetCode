class Solution {
 public:
  int digArtifacts(int n, vector<vector<int>>& artifacts,
                   vector<vector<int>>& dig) {
    unordered_set<int> digged;

    for (const auto& d : dig)
      digged.insert(hash(d[0], d[1]));

    return count_if(begin(artifacts), end(artifacts),
                    [&](const auto& a) { return canExtract(a, digged); });
  }

 private:
  int hash(int i, int j) {
    return i << 16 | j;
  }

  bool canExtract(const vector<int>& a, const unordered_set<int>& digged) {
    for (int i = a[0]; i <= a[2]; ++i)
      for (int j = a[1]; j <= a[3]; ++j)
        if (!digged.count(hash(i, j)))
          return false;
    return true;
  }
};
