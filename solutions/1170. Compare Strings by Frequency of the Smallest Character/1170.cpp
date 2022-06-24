class Solution {
 public:
  vector<int> numSmallerByFrequency(vector<string>& queries,
                                    vector<string>& words) {
    vector<int> ans;
    vector<int> wordsFreq;

    for (const string& word : words)
      wordsFreq.push_back(f(word));
    sort(begin(wordsFreq), end(wordsFreq));

    for (const string& q : queries) {
      const int freq = f(q);
      ans.push_back(end(wordsFreq) -
                    upper_bound(begin(wordsFreq), end(wordsFreq), freq));
    }

    return ans;
  }

 private:
  int f(const string& word) {
    int count = 0;
    char currentChar = 'z' + 1;

    for (char c : word)
      if (c < currentChar) {
        currentChar = c;
        count = 1;
      } else if (c == currentChar)
        ++count;

    return count;
  }
};
