class Solution {
 public:
  vector<int> recoverArray(vector<int>& nums) {
    const int n = nums.size();
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    ranges::sort(nums);

    for (int i = 1; i < n; ++i) {
      const int x = nums[i] - nums[0];  // 2 * k
      if (x <= 0 || x % 2 == 1)
        continue;
      vector<int> arr = getArray(nums, x, count);
      if (!arr.empty())
        return arr;
    }

    throw;
  }

 private:
  vector<int> getArray(const vector<int>& nums, int x,
                       unordered_map<int, int> count) {
    vector<int> arr;
    for (const int num : nums) {
      if (const auto it = count.find(num);
          it == count.cend() || it->second == 0)
        continue;
      if (const auto it = count.find(num + x);
          it == count.cend() || it->second == 0)
        return {};
      --count[num];
      --count[num + x];
      arr.push_back(num + x / 2);
    }
    return arr;
  }
};
