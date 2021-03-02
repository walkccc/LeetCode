class Solution {
 public:
  int subarraysDivByK(vector<int>& A, int K) {
    int ans = 0;
    int prefix = 0;
    vector<int> count(K);
    count[0] = 1;

    for (int a : A) {
      prefix = (prefix + a % K + K) % K;
      ans += count[prefix];
      ++count[prefix];
    }

    return ans;
  }
};
