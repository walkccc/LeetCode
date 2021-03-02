class Solution {
 public:
  bool isMonotonic(vector<int>& A) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < A.size(); ++i) {
      increasing &= A[i] >= A[i - 1];
      decreasing &= A[i] <= A[i - 1];
    }

    return increasing || decreasing;
  }
};
