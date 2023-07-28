class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length())
      return false;

    unordered_map<char, int> count1;
    unordered_map<char, int> count2;
    string s1;           // Unique chars in word1
    string s2;           // Unique chars in word2
    vector<int> freqs1;  // Freqs of unique chars in word1
    vector<int> freqs2;  // Freqs of unique chars in word2

    for (const char c : word1)
      ++count1[c];

    for (const char c : word2)
      ++count2[c];

    for (const auto& [c, freq] : count1) {
      s1 += c;
      freqs1.push_back(freq);
    }

    for (const auto& [c, freq] : count2) {
      s2 += c;
      freqs2.push_back(freq);
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1 != s2)
      return false;

    sort(freqs1.begin(), freqs1.end());
    sort(freqs2.begin(), freqs2.end());
    return freqs1 == freqs2;
  }
};
