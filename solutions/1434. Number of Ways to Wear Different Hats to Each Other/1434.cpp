class Solution {
 public:
  int numberWays(vector<vector<int>>& hats) {
    constexpr int nHats = 40;
    const int nPeople = hats.size();
    vector<vector<int>> hatToPeople(nHats + 1);
    vector<vector<int>> mem(nHats + 1, vector<int>(1 << nPeople, -1));

    for (int i = 0; i < nPeople; ++i)
      for (const int hat : hats[i])
        hatToPeople[hat].push_back(i);

    return numberWays(hats, 0, 1, hatToPeople, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of ways to assign hats 1, 2, ..., h to people, where
  // `assignment` is the bitmask of the current assignment.
  int numberWays(const vector<vector<int>>& hats, int assignment, int h,
                 const vector<vector<int>>& hatToPeople,
                 vector<vector<int>>& mem) {
    // All the people are assigned.
    if (assignment == (1 << hats.size()) - 1)
      return 1;
    if (h > 40)
      return 0;
    if (mem[h][assignment] != -1)
      return mem[h][assignment];

    // Don't wear the hat `h`.
    mem[h][assignment] = numberWays(hats, assignment, h + 1, hatToPeople, mem);

    for (const int p : hatToPeople[h]) {
      // The person `p` was assigned the hat `h` before.
      if (assignment >> p & 1)
        continue;
      // Assign the hat `h` to the person `p`.
      mem[h][assignment] +=
          numberWays(hats, assignment | 1 << p, h + 1, hatToPeople, mem);
      mem[h][assignment] %= kMod;
    }

    return mem[h][assignment];
  }
};
