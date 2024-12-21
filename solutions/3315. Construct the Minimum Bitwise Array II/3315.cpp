class Solution {
 public:
  // Same as 3314. Construct the Minimum Bitwise Array I
  vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ans;

    for (const int num : nums)
      ans.push_back(num == 2 ? -1 : num - getLeadingOneOfLastGroupOfOnes(num));

    return ans;
  }

 private:
  // Returns the leading one of the last group of 1s in the binary
  // representation of num. For example, if num = 0b10111, the leading one of
  // the last group of 1s is 0b100.
  int getLeadingOneOfLastGroupOfOnes(int num) {
    int leadingOne = 1;
    while ((num & leadingOne) > 0)
      leadingOne <<= 1;
    return leadingOne >> 1;
  }
};
