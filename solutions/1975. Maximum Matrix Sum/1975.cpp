class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long absSum = 0;
    int minAbs = INT_MAX;
    int oddNeg = 0;  // 0 := even neg, 1 := odd neg

    for (const vector<int>& row : matrix)
      for (const int num : row) {
        absSum += abs(num);
        minAbs = min(minAbs, abs(num));
        if (num < 0)
          oddNeg ^= 1;
      }

    return absSum - oddNeg * minAbs * 2;
  }
};
