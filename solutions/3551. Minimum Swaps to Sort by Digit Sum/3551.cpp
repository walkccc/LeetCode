class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> seen;
    unordered_map<int, int> numToIndex;
    vector<int> sortedNums = nums;

    ranges::sort(sortedNums, ranges::less{}, [this](int num) {
      return pair<int, int>{getDigitSum(num), num};
    });

    for (int i = 0; i < sortedNums.size(); ++i)
      numToIndex[sortedNums[i]] = i;

    for (int i = 0; i < nums.size(); ++i) {
      if (seen.contains(i) || numToIndex[nums[i]] == i)
        continue;
      int cycleSize = 0;
      int j = i;
      while (seen.insert(j).second) {
        j = numToIndex[nums[j]];
        ++cycleSize;
      }
      ans += max(cycleSize - 1, 0);
    }

    return ans;
  }

 private:
  int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }
};
