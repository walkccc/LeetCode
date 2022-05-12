class Solution {
 public:
  bool circularArrayLoop(vector<int>& nums) {
    const int n = nums.size();
    if (n < 2)
      return false;

    auto advance = [&](int i) {
      const int val = (i + nums[i]) % n;
      return i + nums[i] >= 0 ? val : n + val;
    };

    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0)
        continue;
      int slow = i;
      int fast = advance(slow);
      while (nums[i] * nums[fast] > 0 && nums[i] * nums[advance(fast)] > 0) {
        if (slow == fast) {
          if (slow == advance(slow))
            break;
          return true;
        }
        slow = advance(slow);
        fast = advance(advance(fast));
      }

      slow = i;
      const int sign = nums[i];
      while (sign * nums[slow] > 0) {
        const int next = advance(slow);
        nums[slow] = 0;
        slow = next;
      }
    }

    return false;
  }
};
