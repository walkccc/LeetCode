class Solution {
 public:
  bool checkArray(vector<int>& nums, int k) {
    if (k == 1)
      return true;

    int needDecrease = 0;
    // Store nums[i - k + 1..i] with decreasing nums[i - k + 1].
    deque<int> dq;

    for (int i = 0; i < nums.size(); ++i) {
      if (i >= k) {
        needDecrease -= dq.front();
        dq.pop_front();
      }
      if (nums[i] < needDecrease)
        return false;
      const int decreasedNum = nums[i] - needDecrease;
      dq.push_back(decreasedNum);
      needDecrease += decreasedNum;
    }

    return dq.back() == 0;
  }
};
