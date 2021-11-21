class Solution {
 public:
  int countValidWords(string sentence) {
    int ans = 0;
    istringstream iss(sentence);
    const regex re("[a-z]*([a-z]-[a-z])?[a-z]*[!,.]?");

    for (string token; iss >> token;)
      if (regex_match(token, re))
        ++ans;

    return ans;
  }
};
