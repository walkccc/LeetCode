class Solution {
 public:
  int maximumSwap(int num) {
    string s = to_string(num);
    vector<int> lastIndex(10, -1);  // {digit: last index}

    for (int i = 0; i < s.length(); ++i)
      lastIndex[s[i] - '0'] = i;

    for (int i = 0; i < s.length(); ++i)
      for (int d = 9; d > s[i] - '0'; --d)
        if (lastIndex[d] > i) {
          swap(s[i], s[lastIndex[d]]);
          return stoi(s);
        }

    return num;
  }
};
