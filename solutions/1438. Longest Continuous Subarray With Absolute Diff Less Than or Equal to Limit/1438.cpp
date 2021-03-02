class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    int ans = 1;
    deque<int> minDeque;
    deque<int> maxDeque;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      while (!minDeque.empty() && minDeque.back() > nums[r])
        minDeque.pop_back();
      minDeque.push_back(nums[r]);
      while (!maxDeque.empty() && maxDeque.back() < nums[r])
        maxDeque.pop_back();
      maxDeque.push_back(nums[r]);
      while (maxDeque.front() - minDeque.front() > limit) {
        if (minDeque.front() == nums[l]) minDeque.pop_front();
        if (maxDeque.front() == nums[l]) maxDeque.pop_front();
        ++l;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
