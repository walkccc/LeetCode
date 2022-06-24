class Solution {
 public:
  string reorganizeString(string s) {
    unordered_map<char, int> count;
    int maxFreq = 0;

    for (const char c : s)
      maxFreq = max(maxFreq, ++count[c]);

    if (maxFreq > (s.length() + 1) / 2)
      return "";

    string ans;
    priority_queue<pair<int, char>> maxHeap;  // (freq, c)
    int prevFreq = 0;
    char prevChar = '@';

    for (const auto& [c, freq] : count)
      maxHeap.emplace(freq, c);

    while (!maxHeap.empty()) {
      // get the most freq letter
      const auto [freq, c] = maxHeap.top();
      maxHeap.pop();
      ans += c;
      // add the previous letter back so that
      // any two adjacent characters are not the same
      if (prevFreq > 0)
        maxHeap.emplace(prevFreq, prevChar);
      prevFreq = freq - 1;
      prevChar = c;
    }

    return ans;
  }
};
