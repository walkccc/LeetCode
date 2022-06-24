class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (const int num : nums)
      if (num <= first)
        first = num;
      else if (num <= second)  // first < num <= second
        second = num;
      else
        return true;  // first < second < num (third)

    return false;
  }
};
