class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    int candidate1 = 0;
    int candidate2 = 1;   // Any number different from candidate1
    int countSoFar1 = 0;  // # of candidate1 so far
    int countSoFar2 = 0;  // # of candidate2 so far

    for (const int num : nums)
      if (num == candidate1) {
        ++countSoFar1;
      } else if (num == candidate2) {
        ++countSoFar2;
      } else if (countSoFar1 == 0) {  // Assign new candidate
        candidate1 = num;
        ++countSoFar1;
      } else if (countSoFar2 == 0) {  // Assign new candidate
        candidate2 = num;
        ++countSoFar2;
      } else {  // Meet a new number, so pair out previous counts
        --countSoFar1;
        --countSoFar2;
      }

    const int count1 = count(nums.begin(), nums.end(), candidate1);
    const int count2 = count(nums.begin(), nums.end(), candidate2);

    if (count1 > nums.size() / 3)
      ans.push_back(candidate1);
    if (count2 > nums.size() / 3)
      ans.push_back(candidate2);
    return ans;
  }
};
