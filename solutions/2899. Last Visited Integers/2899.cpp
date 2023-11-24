class Solution {
 public:
  vector<int> lastVisitedIntegers(vector<string>& words) {
    vector<int> ans;
    vector<int> nums;
    int k = 0;

    for (const string& word : words)
      if (word == "prev") {
        ++k;
        ans.push_back(k > nums.size() ? -1 : nums[nums.size() - k]);
      } else {
        k = 0;
        nums.push_back(stoi(word));
      }

    return ans;
  }
};
