class Solution {
 public:
  string reversePrefix(string word, char ch) {
    reverse(begin(word), begin(word) + word.find(ch) + 1);
    return word;
  }
};
