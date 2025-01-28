class Solution {
 public:
  string sortSentence(string s) {
    vector<string> words;
    istringstream iss(s);
    string word;

    while (iss >> word)
      words.push_back(word);

    ranges::sort(words, ranges::less(),
                 [](const string& word) { return word.back(); });

    string ans = trim(words[0]);

    for (int i = 1; i < words.size(); ++i)
      ans += " " + trim(words[i]);

    return ans;
  }

 private:
  string trim(const string& s) {
    return s.substr(0, s.length() - 1);
  }
};
