class Solution {
 public:
  int maximumSwap(int num) {
    string s = to_string(num);
    vector<int> digitToIndex(10);

    for (int i = 0; i < s.length(); ++i)
      digitToIndex[s[i] - '0'] = i;

    for (int i = 0; i < s.length(); ++i)
      for (char d = '9'; d > s[i]; --d)
        if (digitToIndex[d - '0'] > i) {
          swap(s[i], s[digitToIndex[d - '0']]);
          return stoi(s);
        }

    return num;
  }
};