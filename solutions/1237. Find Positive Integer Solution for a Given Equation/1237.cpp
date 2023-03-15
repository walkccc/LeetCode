class Solution {
 public:
  vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> ans;
    int x = 1;
    int y = 1000;

    while (x <= 1000 && y >= 1) {
      int f = customfunction.f(x, y);
      if (f < z)
        ++x;
      else if (f > z)
        --y;
      else
        ans.push_back({x++, y--});
    }

    return ans;
  }
};
