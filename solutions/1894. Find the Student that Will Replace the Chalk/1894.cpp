class Solution {
 public:
  int chalkReplacer(vector<int>& chalk, int k) {
    k %= accumulate(begin(chalk), end(chalk), 0L);
    if (k == 0)
      return 0;

    for (int i = 0; i < chalk.size(); ++i) {
      k -= chalk[i];
      if (k < 0)
        return i;
    }

    throw;
  }
};
