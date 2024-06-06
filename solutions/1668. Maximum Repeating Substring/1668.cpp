class Solution {
 public:
  int maxRepeating(string sequence, string word) {
    int ans = 1;
    string repeating = word;
    while (sequence.find(repeating) != string::npos) {
      ++ans;
      repeating += word;
    }
    return ans - 1;
  }
};
