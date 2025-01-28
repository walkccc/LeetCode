class Solution {
 public:
  vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum % 2 == 1)
      return {};

    vector<long long> ans;
    long needSum = finalSum;
    long even = 2;

    while (needSum - even >= even + 2) {
      ans.push_back(even);
      needSum -= even;
      even += 2;
    }

    ans.push_back(needSum);
    return ans;
  }
};
