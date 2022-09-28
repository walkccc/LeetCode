class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, int> count;
    vector<int> starts;  // start index of subsequence
    vector<int> ends;    // end index of subsequence

    for (const int num : nums)
      ++count[num];

    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      const int num = nums[i];
      const int currCount = count[num];
      const int prevCount = count.count(num - 1) ? count[num - 1] : 0;
      const int nextCount = count.count(num + 1) ? count[num + 1] : 0;
      for (int j = 0; j < currCount - prevCount; ++j)
        starts.push_back(num);
      for (int j = 0; j < currCount - nextCount; ++j)
        ends.push_back(num);
    }

    for (int i = 0; i < starts.size(); ++i)
      if (ends[i] - starts[i] < 2)
        return false;

    return true;
  }
};
