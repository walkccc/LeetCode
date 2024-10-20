class Solution {
 public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    if (sentence1.length() == sentence2.length())
      return sentence1 == sentence2;

    vector<string> words1 = split(sentence1);
    vector<string> words2 = split(sentence2);
    const int m = words1.size();
    const int n = words2.size();
    if (m > n)
      return areSentencesSimilar(sentence2, sentence1);

    int i = 0;  // words1's index
    while (i < m && words1[i] == words2[i])
      ++i;
    while (i < m && words1[i] == words2[i + n - m])
      ++i;

    return i == m;
  }

 private:
  vector<string> split(const string& sentence) {
    vector<string> words;
    istringstream iss(sentence);

    for (string s; iss >> s;)
      words.push_back(s);

    return words;
  }
};
