class Solution {
 public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    const int n = tops.size();
    vector<int> countTops(7);
    vector<int> countBottoms(7);
    vector<int> countBoth(7);

    for (int i = 0; i < n; ++i) {
      ++countTops[tops[i]];
      ++countBottoms[bottoms[i]];
      if (tops[i] == bottoms[i])
        ++countBoth[tops[i]];
    }

    for (int i = 1; i <= 6; ++i)
      if (countTops[i] + countBottoms[i] - countBoth[i] == n)
        return n - max(countTops[i], countBottoms[i]);

    return -1;
  }
};
