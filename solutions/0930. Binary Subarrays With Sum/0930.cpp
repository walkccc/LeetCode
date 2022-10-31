class Solution {
 public:
  int numSubarraysWithSum(vector<int>& A, int S) {
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> count{{0, 1}};

    for (int a : A) {
      prefix += a;
      if (count.count(prefix - S))
        ans += count[prefix - S];
      ++count[prefix];
    }

    return ans;
  }
};
