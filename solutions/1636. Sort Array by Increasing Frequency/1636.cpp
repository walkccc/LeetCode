struct T {
  int num;
  int freq;
};

class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    vector<int> ans;
    auto compare = [](const T& a, const T& b) {
      return a.freq == b.freq ? a.num < b.num : a.freq > b.freq;
    };
    priority_queue<T, vector<T>, decltype(compare)> heap(compare);
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    for (const auto& [num, freq] : count)
      heap.emplace(num, freq);

    while (!heap.empty()) {
      const auto [num, freq] = heap.top();
      heap.pop();
      for (int i = 0; i < freq; ++i)
        ans.push_back(num);
    }

    return ans;
  }
};
