class Solution {
 public:
  int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                            int num_wanted, int use_limit) {
    const int n = values.size();
    int ans = 0;
    vector<pair<int, int>> items(n);
    unordered_map<int, int> labelsUsed;

    for (int i = 0; i < n; ++i)
      items[i] = make_pair(values[i], labels[i]);

    sort(begin(items), end(items),
         [](const auto& a, const auto& b) { return a.first > b.first; });

    for (auto&& [value, label] : items) {
      if (labelsUsed[label] < use_limit) {
        ans += value;
        ++labelsUsed[label];
        if (--num_wanted == 0)
          break;
      }
    }

    return ans;
  }
};
