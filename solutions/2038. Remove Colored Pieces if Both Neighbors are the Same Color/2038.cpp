class Solution {
 public:
  bool winnerOfGame(string colors) {
    int countAAA = 0;
    int countBBB = 0;

    for (int i = 1; i + 1 < colors.length(); ++i)
      if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
        if (colors[i] == 'A')
          ++countAAA;
        else
          ++countBBB;

    return countAAA > countBBB;
  }
};
