class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    vector<vector<int>> ans;
    short i = 0;
    short j = 0;

    while (i < firstList.size() && j < secondList.size()) {
      // lo := the start of the intersection
      // hi := the end of the intersection
      const int lo = max(firstList[i][0], secondList[j][0]);
      const int hi = min(firstList[i][1], secondList[j][1]);
      if (lo <= hi)
        ans.push_back({lo, hi});
      firstList[i][1] < secondList[j][1] ? ++i : ++j;
    }

    return ans;
  }
};
