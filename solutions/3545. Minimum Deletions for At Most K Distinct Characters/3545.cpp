class Solution {
 public:
  int minDeletion(string s, int k) {
    unordered_map<char, int> count;

    for (const char c : s)
      ++count[c];

    if (count.size() <= k)
      return 0;

    vector<int> freqs;

    for (const auto& [_, freq] : count)
      freqs.push_back(freq);

    ranges::sort(freqs);
    return accumulate(freqs.begin(), freqs.begin() + freqs.size() - k, 0);
  }
};
