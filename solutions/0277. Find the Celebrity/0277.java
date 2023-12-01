public class Solution extends Relation {
  public int findCelebrity(int n) {
    int candidate = 0;

    // Everyone knows the celebrity.
    for (int i = 1; i < n; ++i)
      if (knows(candidate, i))
        candidate = i;

    // The candidate knows nobody and everyone knows the celebrity.
    for (int i = 0; i < n; ++i) {
      if (i < candidate && knows(candidate, i) || !knows(i, candidate))
        return -1;
      if (i > candidate && !knows(i, candidate))
        return -1;
    }

    return candidate;
  }
}
