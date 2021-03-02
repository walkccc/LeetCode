class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                           vector<vector<int>>& B) {
    vector<vector<int>> ans;
    short i = 0;
    short j = 0;

    while (i < A.size() && j < B.size()) {
      const int maxL = max(A[i][0], B[j][0]);
      const int minR = min(A[i][1], B[j][1]);
      if (maxL <= minR)
        ans.push_back({maxL, minR});
      if (A[i][1] < B[j][1])
        ++i;
      else
        ++j;
    }

    return ans;
  }
};
