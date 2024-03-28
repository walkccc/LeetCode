class Solution {
 public:
  long long getMaxFunctionValue(vector<int>& receiver, long long k) {
    const int n = receiver.size();
    const int m = log2(k) + 1;
    long long ans = 0;
    // jump[i][j] := the the node you reach after jumping 2^j steps from i
    vector<vector<int>> jump(n, vector<int>(m));
    // sum[i][j] := the sum of the first 2^j nodes you reach when jumping from i
    vector<vector<long long>> sum(n, vector<long long>(m));

    for (int i = 0; i < n; ++i) {
      jump[i][0] = receiver[i];
      sum[i][0] = receiver[i];
    }

    // Calculate binary lifting.
    for (int j = 1; j < m; ++j)
      for (int i = 0; i < n; ++i) {
        const int midNode = jump[i][j - 1];
        //   the the node you reach after jumping 2^j steps from i
        // = the node you reach after jumping 2^(j - 1) steps from i
        // + the node you reach after jumping another 2^(j - 1) steps
        jump[i][j] = jump[midNode][j - 1];
        //   the sum of the first 2^j nodes you reach when jumping from i
        // = the sum of the first 2^(j - 1) nodes you reach when jumping from i
        // + the sum of another 2^(j - 1) nodes you reach
        sum[i][j] = sum[i][j - 1] + sum[midNode][j - 1];
      }

    for (int i = 0; i < n; ++i) {
      long long currSum = i;
      int currPos = i;
      for (int j = 0; j < m; ++j)
        if (k >> j & 1) {
          currSum += sum[currPos][j];
          currPos = jump[currPos][j];
        }
      ans = max(ans, currSum);
    }

    return ans;
  }
};
