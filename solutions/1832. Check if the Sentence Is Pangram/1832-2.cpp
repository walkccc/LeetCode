class Solution {
 public:
  bool checkIfPangram(string sentence) {
    int seen = 0;

    for (const char c : sentence)
      seen |= 1 << c - 'a';

    return seen == (1 << 26) - 1;
  }
};
