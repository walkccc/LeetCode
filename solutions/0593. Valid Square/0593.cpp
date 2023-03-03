class Solution {
 public:
  bool validSquare(vector<int>& p1, vector<int>& p2,
                   vector<int>& p3, vector<int>& p4) {
    unordered_set<int> distSet;
    vector<vector<int>> points{p1, p2, p3, p4};

    for (int i = 0; i < 4; ++i)
      for (int j = i + 1; j < 4; ++j)
        distSet.insert(dist(points[i], points[j]));

    return !distSet.count(0) && distSet.size() == 2;
  }

 private:
  int dist(vector<int>& p1, vector<int>& p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) +
           (p1[1] - p2[1]) * (p1[1] - p2[1]);
  }
};
