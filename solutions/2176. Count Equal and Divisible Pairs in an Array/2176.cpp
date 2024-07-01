class Solution {
 public:
  int countPairs(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, vector<int>> numToIndices;

    for (int i = 0; i < nums.size(); ++i)
      numToIndices[nums[i]].push_back(i);

    for (const auto& [_, indices] : numToIndices) {
      unordered_map<int, int> gcds;
      for (const int i : indices) {
        const int gcd_i = gcd(i, k);
        for (const auto& [gcd_j, count] : gcds)
          if (gcd_i * gcd_j % k == 0)
            ans += count;
        ++gcds[gcd_i];
      }
    }

    return ans;
  }
};
