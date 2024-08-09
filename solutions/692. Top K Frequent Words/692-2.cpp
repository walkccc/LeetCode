struct T {
  string word;
  int freq;
  T(string word, int freq) : word(word), freq(freq) {}
};

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    vector<string> ans;
    unordered_map<string, int> count;
    // Words with higher frequency and lower alphabetical order are in the
    // bottom of the heap because we'll pop words with lower frequency and
    // higher alphabetical order if the heap's size > k.
    auto compare = [](const T& a, const T& b) {
      return a.freq == b.freq ? a.word < b.word : a.freq > b.freq;
    };
    priority_queue<T, vector<T>, decltype(compare)> heap(compare);

    for (const string& word : words)
      ++count[word];

    for (const auto& [word, freq] : count) {
      heap.emplace(word, freq);
      if (heap.size() > k)
        heap.pop();
    }

    while (!heap.empty())
      ans.push_back(heap.top().word), heap.pop();

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
