class Solution {
 public:
  long long maxScore(vector<int>& prices) {
    //    prices[indices[j]] - prices[indices[j - 1]]
    // == indices[j] - indices[j - 1]
    //    prices[indices[j]] - indices[j]
    // == prices[indices[j - 1]] - indices[j - 1]
    //
    // So, elements in the same subsequence must have the same prices[i] - i.
    unordered_map<int, long> groupIdToSum;

    for (int i = 0; i < prices.size(); ++i)
      groupIdToSum[prices[i] - i] += prices[i];

    return ranges::max_element(groupIdToSum,
                               [](const std::pair<int, long>& p1,
                                  const std::pair<int, long>& p2) {
      return p1.second < p2.second;
    })->second;
  }
};
