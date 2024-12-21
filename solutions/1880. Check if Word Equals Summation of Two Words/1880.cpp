class Solution {
 public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    const int first = getNumber(firstWord);
    const int second = getNumber(secondWord);
    const int target = getNumber(targetWord);
    return first + second == target;
  }

 private:
  int getNumber(const string& word) {
    int num = 0;
    for (const char c : word)
      num = num * 10 + (c - 'a');
    return num;
  }
};
