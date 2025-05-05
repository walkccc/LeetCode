class Matrix3D {
 public:
  Matrix3D(int n) {
    isSet = vector<vector<vector<bool>>>(
        n, vector<vector<bool>>(n, vector<bool>(n)));
    count = vector<int>(n);
    for (int x = 0; x < n; ++x)
      pairs.insert({0, x});
  }

  void setCell(int x, int y, int z) {
    if (isSet[x][y][z])
      return;
    isSet[x][y][z] = true;
    pairs.erase({count[x], x});
    pairs.insert({++count[x], x});
  }

  void unsetCell(int x, int y, int z) {
    if (!isSet[x][y][z])
      return;
    isSet[x][y][z] = false;
    pairs.erase({count[x], x});
    pairs.insert({--count[x], x});
  }

  int largestMatrix() {
    return pairs.rbegin()->second;
  }

 private:
  vector<vector<vector<bool>>> isSet;
  vector<int> count;  // count[x] := the number of cells set in the x-th layer

  struct PairCompare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
      return a.first == b.first ? b.second > a.second : b.first > a.first;
    }
  };

  set<pair<int, int>, PairCompare> pairs;  // (count[x], x)
};
