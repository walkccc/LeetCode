class Solution {
 public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                          vector<int>& king) {
    vector<vector<int>> ans;
    unordered_set<int> queensSet;

    for (vector<int>& queen : queens)
      queensSet.insert(hash(queen[0], queen[1]));

    vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    for (vector<int> d : directions)
      for (int i = king[0] + d[0], j = king[1] + d[1];
           0 <= i && i < 8 && 0 <= j && j < 8; i += d[0], j += d[1])
        if (queensSet.count(hash(i, j))) {
          ans.push_back({i, j});
          break;
        }

    return ans;
  }

 private:
  int hash(int i, int j) {
    return i * 8 + j;
  }
};
