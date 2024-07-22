class Solution {
 public:
  int numTilePossibilities(string tiles) {
    vector<int> count(26);

    for (const char t : tiles)
      ++count[t - 'A'];

    return dfs(count);
  }

 private:
  int dfs(vector<int>& count) {
    int possibleSequences = 0;

    for (int& c : count) {
      if (c == 0)
        continue;
      // Put c in the current position. We only care about the number of
      // possible sequences of letters but don't care about the actual
      // combination.
      --c;
      possibleSequences += 1 + dfs(count);
      ++c;
    }

    return possibleSequences;
  }
};
