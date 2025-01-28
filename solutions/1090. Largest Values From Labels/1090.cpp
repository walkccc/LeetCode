class Solution {
 public:
  int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                            int numWanted, int useLimit) {
    const int n = values.size();
    int ans = 0;
    vector<pair<int, int>> items;
    unordered_map<int, int> labelsUsed;

    for (int i = 0; i < n; ++i)
      items.emplace_back(values[i], labels[i]);

    ranges::sort(items, ranges::greater{},
                 [](const pair<int, int>& item) { return item.first; });

    for (const auto& [value, label] : items)
      if (labelsUsed[label] < useLimit) {
        ans += value;
        ++labelsUsed[label];
        if (--numWanted == 0)
          break;
      }

    return ans;
  }
};
