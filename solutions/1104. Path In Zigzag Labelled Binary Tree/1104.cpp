class Solution {
 public:
  vector<int> pathInZigZagTree(int label) {
    deque<int> ans;
    int level;

    for (int l = 0; l < 21; ++l)
      if (pow(2, l) > label) {
        level = l - 1;
        break;
      }

    if (level % 2 == 1)
      label = boundarySum(level) - label;

    for (int l = level; l >= 0; --l) {
      ans.push_front(l % 2 == 0 ? label : boundarySum(l) - label);
      label /= 2;
    }

    return {ans.begin(), ans.end()};
  }

 private:
  int boundarySum(int level) {
    return pow(2, level) + pow(2, level + 1) - 1;
  }
};
