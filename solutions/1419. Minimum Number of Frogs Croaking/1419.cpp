class Solution {
 public:
  int minNumberOfFrogs(string croakOfFrogs) {
    const string kCroak = "croak";
    int ans = 0;
    int frogs = 0;
    vector<int> count(5);

    for (const char c : croakOfFrogs) {
      ++count[kCroak.find(c)];
      for (int i = 1; i < 5; ++i)
        if (count[i] > count[i - 1])
          return -1;
      if (c == 'c')
        ++frogs;
      else if (c == 'k')
        --frogs;
      ans = max(ans, frogs);
    }

    return frogs == 0 ? ans : -1;
  }
};
