class Solution {
 public:
  int subarraysDivByK(vector<int>& A, int K) {
    int ans = 0;
    int prefixSum = 0;
    vector<int> count(K);
    count[0] = 1;

    for (int a : A) {
      prefixSum = (prefixSum + a % K + K) % K;
      ans += count[prefixSum];
      ++count[prefixSum];
    }

    return ans;
  }
};