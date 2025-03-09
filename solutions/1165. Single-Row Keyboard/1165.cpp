class Solution {
 public:
  int calculateTime(string keyboard, string word) {
    int ans = 0;
    int prevIndex = 0;
    vector<int> letterToIndex(26);

    for (int i = 0; i < keyboard.length(); ++i)
      letterToIndex[keyboard[i] - 'a'] = i;

    for (const char c : word) {
      const int currIndex = letterToIndex[c - 'a'];
      ans += abs(currIndex - prevIndex);
      prevIndex = currIndex;
    }

    return ans;
  }
};
