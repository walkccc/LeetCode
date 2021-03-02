class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    string ans;
    int maxCount = 0;
    unordered_map<string, int> count;
    unordered_set<string> bannedSet{begin(banned), end(banned)};

    // make paragraph to lowercase and empty punctuations
    for (char& c : paragraph)
      c = isalpha(c) ? tolower(c) : ' ';

    istringstream iss(paragraph);

    for (string word; iss >> word;)
      if (!bannedSet.count(word))
        ++count[word];

    for (const auto& [word, freq] : count)
      if (freq > maxCount) {
        maxCount = freq;
        ans = word;
      }

    return ans;
  }
};
