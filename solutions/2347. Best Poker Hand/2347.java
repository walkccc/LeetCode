class Solution {
  public String bestHand(int[] ranks, char[] suits) {
    if (new String(suits).chars().allMatch(s -> s == suits[0]))
      return "Flush";

    final int kMax = 13;
    int[] count = new int[kMax + 1];

    for (final int rank : ranks)
      ++count[rank];

    final int mx = Arrays.stream(count).max().getAsInt();
    if (mx > 2)
      return "Three of a Kind";
    if (mx == 2)
      return "Pair";
    return "High Card";
  }
}
