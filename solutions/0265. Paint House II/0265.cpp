class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    int prevIndex = -1;  // The previous minimum index
    int prevMin1 = 0;    // Minimum cost so far
    int prevMin2 = 0;    // 2nd minimum cost so far

    for (const vector<int>& cost : costs) {  // O(n)
      int index = -1;  // The painted index s.t. achieve the minimum cost after
                       // Painting current house
      int min1 = INT_MAX;  // The minimum cost after painting current house
      int min2 = INT_MAX;  // The 2nd minimum cost after painting current house
      for (int i = 0; i < cost.size(); ++i) {  // O(k)
        const int theCost = cost[i] + (i == prevIndex ? prevMin2 : prevMin1);
        if (theCost < min1) {
          index = i;
          min2 = min1;
          min1 = theCost;
        } else if (theCost < min2) {  // Min1 <= theCost < min2
          min2 = theCost;
        }
      }
      prevIndex = index;
      prevMin1 = min1;
      prevMin2 = min2;
    }

    return prevMin1;
  }
};
