class Solution {
  public String findContestMatch(int n) {
    List<String> matches = new ArrayList<>();

    for (int i = 1; i <= n; ++i)
      matches.add(String.valueOf(i));

    return generateMatches(matches);
  }

  private String generateMatches(List<String> matches) {
    if (matches.size() == 1)
      return matches.get(0);

    List<String> nextMatches = new ArrayList<>();

    for (int i = 0; i < matches.size() / 2; ++i)
      nextMatches.add("(" + matches.get(i) + "," + matches.get(matches.size() - 1 - i) + ")");

    return generateMatches(nextMatches);
  }
}
