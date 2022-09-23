struct IndexedWord {
  string word;
  int index;
  IndexedWord(const string& word, int index) : word(word), index(index) {}
};

class Solution {
 public:
  vector<string> wordsAbbreviation(vector<string>& words) {
    const int n = words.size();
    vector<string> ans(n);
    unordered_map<string, vector<IndexedWord>> abbrevToIndexedWords;

    for (int i = 0; i < n; ++i) {
      const string abbrev = getAbbrev(words[i], 0);
      abbrevToIndexedWords[abbrev].emplace_back(words[i], i);
    }

    for (auto& [_, indexedWords] : abbrevToIndexedWords) {
      sort(begin(indexedWords), end(indexedWords),
           [](const auto& a, const auto& b) { return a.word < b.word; });
      vector<int> lcp(indexedWords.size());
      for (int i = 1; i < indexedWords.size(); ++i) {
        const int k =
            longestCommonPrefix(indexedWords[i - 1].word, indexedWords[i].word);
        lcp[i - 1] = max(lcp[i - 1], k);
        lcp[i] = k;
      }
      for (int i = 0; i < indexedWords.size(); ++i)
        ans[indexedWords[i].index] = getAbbrev(indexedWords[i].word, lcp[i]);
    }

    return ans;
  }

 private:
  string getAbbrev(const string& s, int prefixIndex) {
    const int n = s.length();
    const int num = n - (prefixIndex + 1) - 1;
    const int numLength = num < 10 ? 1 : num < 100 ? 2 : 3;
    const int abbrevLength = (prefixIndex + 1) + numLength + 1;
    if (abbrevLength >= n)
      return s;
    return s.substr(0, prefixIndex + 1) + to_string(num) + s.back();
  }

  int longestCommonPrefix(const string& s1, const string& s2) {
    int i = 0;
    while (i < s1.length() && i < s2.length() && s1[i] == s2[i])
      ++i;
    return i;
  }
};
