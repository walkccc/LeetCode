class Solution {
 public:
  int minKBitFlips(vector<int>& A, int K) {
    int ans = 0;
    int flippedTime = 0;

    for (int r = 0; r < A.size(); ++r) {
      if (r >= K && A[r - K] == 2)
        --flippedTime;
      if (flippedTime % 2 == A[r]) {
        if (r + K > A.size())
          return -1;
        ++ans;
        ++flippedTime;
        A[r] = 2;
      }
    }

    return ans;
  }
};
