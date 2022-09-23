class Solution {
 public:
  vector<int> recoverArray(vector<int>& nums) {
    const int n = nums.size();
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    sort(begin(nums), end(nums));

    for (int i = 1; i < n; ++i) {
      const int x = nums[i] - nums[0];  // 2 * k
      if (x <= 0 || x & 1)
        continue;
      vector<int> A = getArray(nums, x, count);
      if (!A.empty())
        return A;
    }

    throw;
  }

 private:
  vector<int> getArray(const vector<int>& nums, int x,
                       unordered_map<int, int> count) {
    vector<int> A;
    for (const int num : nums) {
      if (!count.count(num) || count[num] == 0)
        continue;
      if (!count.count(num + x) || count[num + x] == 0)
        return {};
      --count[num];
      --count[num + x];
      A.push_back(num + x / 2);
    }
    return A;
  }
};
