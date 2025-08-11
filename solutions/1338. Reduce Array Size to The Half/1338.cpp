class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    const int n = arr.size();
    int sum = 0;
    unordered_map<int, int> count;
    vector<pair<int, int>> numAndFreqs;

    for (const int a : arr)
      ++count[a];

    for (const auto& [a, freq] : count)
      numAndFreqs.emplace_back(a, freq);

    ranges::sort(
        numAndFreqs, ranges::greater{},
        [](const pair<int, int>& numAndFreq) { return numAndFreq.second; });

    for (int i = 0; i < numAndFreqs.size(); ++i) {
      sum += numAndFreqs[i].second;
      if (sum >= n / 2)
        return i + 1;
    }

    throw;
  }
};
