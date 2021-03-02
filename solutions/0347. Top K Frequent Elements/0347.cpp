struct T {
  int num;
  int freq;
};

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    const int n = nums.size();

    vector<int> ans;
    unordered_map<int, int> count;
    auto compare = [](const T& a, const T& b) { return a.freq > b.freq; };
    priority_queue<T, vector<T>, decltype(compare)> pq(compare);

    for (const int num : nums)
      ++count[num];

    for (const auto& [num, freq] : count) {
      pq.push({num, freq});
      if (pq.size() > k)
        pq.pop();
    }

    while (!pq.empty())
      ans.push_back(pq.top().num), pq.pop();

    return ans;
  }
};
