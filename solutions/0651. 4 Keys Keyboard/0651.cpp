class Solution {
 public:
  int maxA(int N) {
    int ans = N;

    for (int i = 1; i <= N - 3; ++i)
      ans = max(ans, maxA(i) * (N - i - 1));

    return ans;
  }
};
