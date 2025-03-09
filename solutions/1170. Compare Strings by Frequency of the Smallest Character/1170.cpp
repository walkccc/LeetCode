class Solution {
 public:
  vector<int> numSmallerByFrequency(vector<string>& queries,
                                    vector<string>& words) {
    vector<int> ans;
    vector<int> wordsFreq;

    for (const string& word : words)
      wordsFreq.push_back(f(word));
    ranges::sort(wordsFreq);

    for (const string& query : queries) {
      const int freq = f(query);
      ans.push_back(wordsFreq.end() - ranges::upper_bound(wordsFreq, freq));
    }

    return ans;
  }

 private:
  int f(const string& word) {
    int count = 0;
    char currentChar = 'z' + 1;

    for (const char c : word)
      if (c < currentChar) {
        currentChar = c;
        count = 1;
      } else if (c == currentChar) {
        ++count;
      }

    return count;
  }
};
