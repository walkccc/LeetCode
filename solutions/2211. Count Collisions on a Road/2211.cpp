class Solution {
 public:
  int countCollisions(string directions) {
    int l = 0;
    int r = directions.length() - 1;

    while (l < directions.length() && directions[l] == 'L')
      ++l;

    while (r >= 0 && directions[r] == 'R')
      --r;

    return count_if(directions.begin() + l, directions.begin() + r + 1,
                    [](char c) { return c != 'S'; });
  }
};
