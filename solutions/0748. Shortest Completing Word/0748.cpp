class Solution {
 public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    string ans(16, '.');
    vector<int> count(26);

    for (const char c : licensePlate)
      if (isalpha(c))
        ++count[tolower(c) - 'a'];

    for (const string& word : words)
      if (word.length() < ans.length() && isComplete(count, getCount(word)))
        ans = word;

    return ans;
  }

 private:
  // check if c1 is a subset of c2
  bool isComplete(const vector<int>& c1, const vector<int> c2) {
    for (int i = 0; i < 26; ++i)
      if (c1[i] > c2[i])
        return false;
    return true;
  }

  vector<int> getCount(const string& word) {
    vector<int> count(26);
    for (const char c : word)
      ++count[c - 'a'];
    return count;
  }
};
