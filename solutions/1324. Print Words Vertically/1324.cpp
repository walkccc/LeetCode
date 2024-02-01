class Solution {
 public:
  vector<string> printVertically(string s) {
    vector<string> ans;
    vector<string> words = split(s);
    size_t maxLength = 0;

    for (const string& word : words)
      maxLength = max(maxLength, word.length());

    for (size_t i = 0; i < maxLength; ++i) {
      string row;
      for (const string& word : words)
        row += i < word.length() ? word[i] : ' ';
      while (row.back() == ' ')
        row.pop_back();
      ans.push_back(row);
    }

    return ans;
  }

 private:
  vector<string> split(const string& s) {
    vector<string> words;
    istringstream iss(s);
    for (string token; iss >> token;)
      words.push_back(token);
    return words;
  }
};
