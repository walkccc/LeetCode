class Solution {
 public:
  long long countOperationsToEmptyArray(vector<int>& nums) {
    const int n = nums.size();
    long long ans = n;
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < n; ++i)
      numToIndex[nums[i]] = i;

    ranges::sort(nums);

    for (int i = 1; i < n; ++i)
      // On the i-th step we've already removed the i - 1 smallest numbers and
      // can ignore them. If an element nums[i] has smaller index in origin
      // array than nums[i - 1], we should rotate the whole left array n - i
      // times to set nums[i] element on the first position.
      if (numToIndex[nums[i]] < numToIndex[nums[i - 1]])
        ans += n - i;

    return ans;
  }
};
