class Solution {
 public:
  int numSubarraysWithSum(vector<int>& A, int S) {
    int ans = 0;
    int prefixSum = 0;
    unordered_map<int, int> count{{0, 1}};

    for (int a : A) {
      prefixSum += a;
      if (count.count(prefixSum - S)) ans += count[prefixSum - S];
      ++count[prefixSum];
    }

    return ans;
  }
};