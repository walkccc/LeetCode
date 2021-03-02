struct T {
  string word;
  int freq;
};

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    const int n = words.size();

    vector<string> ans;
    unordered_map<string, int> count;
    // words w/ higher frequency and lower alphabetical order are in the bottom
    // of the heap, because we'll pop words w/ lower frequency and higher
    // alphabetical order if the heap's size > k
    auto compare = [](const T& a, const T& b) {
      return a.freq == b.freq ? a.word < b.word : a.freq > b.freq;
    };
    priority_queue<T, vector<T>, decltype(compare)> pq(compare);

    for (const string& word : words)
      ++count[word];

    for (const auto& [word, freq] : count) {
      pq.push({word, freq});
      if (pq.size() > k)
        pq.pop();
    }

    while (!pq.empty())
      ans.push_back(pq.top().word), pq.pop();

    reverse(begin(ans), end(ans));
    return ans;
  }
};
