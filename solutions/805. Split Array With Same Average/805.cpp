class Solution {
 public:
  bool splitArraySameAverage(vector<int>& nums) {
    const int n = nums.size();
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (!isPossible(sum, n))
      return false;

    vector<unordered_set<int>> sums(n / 2 + 1);
    sums[0].insert(0);

    for (const int num : nums)
      for (int i = n / 2; i > 0; --i)
        for (const int val : sums[i - 1])
          sums[i].insert(num + val);

    for (int i = 1; i < n / 2 + 1; ++i)
      if (i * sum % n == 0 && sums[i].contains(i * sum / n))
        return true;

    return false;
  }

 private:
  bool isPossible(int sum, int n) {
    for (int i = 1; i < n / 2 + 1; ++i)
      if (i * sum % n == 0)
        return true;
    return false;
  }
};
