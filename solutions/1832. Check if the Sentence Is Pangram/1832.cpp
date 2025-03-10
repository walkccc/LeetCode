class Solution {
 public:
  bool checkIfPangram(string sentence) {
    return unordered_set(sentence.begin(), sentence.end()).size() == 26;
  }
};
