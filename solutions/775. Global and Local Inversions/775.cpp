class Solution {
 public:
  bool isIdealPermutation(vector<int>& nums) {
    int maxi = -1;  // the number that is most likely > nums[i + 2]

    for (int i = 0; i + 2 < nums.size(); ++i) {
      maxi = max(maxi, nums[i]);
      if (maxi > nums[i + 2])
        return false;
    }

    return true;
  }
};
