class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = nums[nums[0]];
    int fast = nums[nums[nums[0]]];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    slow = nums[0];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};
