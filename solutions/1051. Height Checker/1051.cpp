class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    int ans = 0;
    int currentHeight = 1;
    vector<int> count(101);

    for (int height : heights)
      ++count[height];

    for (int height : heights) {
      while (count[currentHeight] == 0)
        ++currentHeight;
      if (height != currentHeight)
        ++ans;
      --count[currentHeight];
    }

    return ans;
  }
};
