class Solution {
 public:
  string reorderSpaces(string text) {
    const int spaces = count(begin(text), end(text), ' ');
    string ans;
    vector<string> words;

    istringstream iss(text);
    string word;

    while (iss >> word)
      words.push_back(word);

    if (words.size() == 1)
      return word + string(spaces, ' ');

    const int gapSize = spaces / (words.size() - 1);
    const int remains = spaces % (words.size() - 1);

    for (int i = 0; i < words.size() - 1; ++i)
      ans += words[i] + string(gapSize, ' ');
    ans += words.back() + string(remains, ' ');

    return ans;
  }
};
