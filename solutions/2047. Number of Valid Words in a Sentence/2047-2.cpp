class Solution {
 public:
  int countValidWords(string sentence) {
    const regex re("[a-z]*([a-z]-[a-z])?[a-z]*[!,.]?");
    int ans = 0;
    istringstream iss(sentence);

    for (string token; iss >> token;)
      if (regex_match(token, re))
        ++ans;

    return ans;
  }
};
