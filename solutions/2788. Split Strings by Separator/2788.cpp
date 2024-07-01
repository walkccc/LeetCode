class Solution {
 public:
  vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> ans;

    for (const string& word : words) {
      istringstream iss(word);
      for (string word; getline(iss, word, separator);)
        if (!word.empty())
          ans.push_back(word);
    }

    return ans;
  }
};
