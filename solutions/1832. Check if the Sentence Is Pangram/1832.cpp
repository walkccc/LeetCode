class Solution {
 public:
  bool checkIfPangram(string sentence) {
    return unordered_set(begin(sentence), end(sentence)).size() == 26;
  }
};
