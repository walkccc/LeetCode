class Solution {
 public:
  int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> count;

    for (const string& word : words1)
      ++count[word];

    for (const string& word : words2)
      if (count.count(word) && count[word] < 2)
        --count[word];

    return count_if(begin(count), end(count),
                    [](const auto& c) { return c.second == 0; });
  }
};
