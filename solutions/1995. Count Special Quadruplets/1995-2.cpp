class Solution {
 public:
  int countQuadruplets(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    unordered_map<int, int> count;

    for (int c = n - 1; c > 1; --c) {  // Also represents `d`.
      for (int b = c - 1; b > 0; --b)
        for (int a = b - 1; a >= 0; --a)
          if (const auto it = count.find(nums[a] + nums[b] + nums[c]);
              it != count.cend())
            ans += it->second;
      ++count[nums[c]];  // c := d
    }

    return ans;
  }
};
