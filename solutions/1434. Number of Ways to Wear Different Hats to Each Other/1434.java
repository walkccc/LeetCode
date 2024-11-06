class Solution {
  public int numberWays(List<List<Integer>> hats) {
    final int nHats = 40;
    final int nPeople = hats.size();
    List<Integer>[] hatToPeople = new List[nHats + 1];
    Integer[][] mem = new Integer[nHats + 1][1 << nPeople];

    for (int i = 1; i <= nHats; ++i)
      hatToPeople[i] = new ArrayList<>();

    for (int i = 0; i < nPeople; ++i)
      for (final int hat : hats.get(i))
        hatToPeople[hat].add(i);

    return numberWays(hats, 0, 1, hatToPeople, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of ways to assign hats 1, 2, ..., h to people, where
  // `assignment` is the bitmask of the current assignment.
  private int numberWays(List<List<Integer>> hats, int assignment, int h,
                         List<Integer>[] hatToPeople, Integer[][] mem) {
    // All the people are assigned.
    if (assignment == (1 << hats.size()) - 1)
      return 1;
    if (h > 40)
      return 0;
    if (mem[h][assignment] != null)
      return mem[h][assignment];

    // Don't wear the hat `h`.
    int ans = numberWays(hats, assignment, h + 1, hatToPeople, mem);

    for (final int p : hatToPeople[h]) {
      // The person `p` was assigned the hat `h` before.
      if ((assignment >> p & 1) == 1)
        continue;
      // Assign the hat `h` to the person `p`.
      ans += numberWays(hats, assignment | 1 << p, h + 1, hatToPeople, mem);
      ans %= kMod;
    }

    return mem[h][assignment] = ans;
  }
}
