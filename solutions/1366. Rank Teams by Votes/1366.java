class Team {
  public char name;
  public int[] rank;
  public Team(char name, int teamSize) {
    this.name = name;
    this.rank = new int[teamSize];
  }
}

class Solution {
  public String rankTeams(String[] votes) {
    final int teamSize = votes[0].length();
    StringBuilder sb = new StringBuilder();
    Team[] teams = new Team[26];

    for (int i = 0; i < 26; ++i)
      teams[i] = new Team((char) ('A' + i), teamSize);

    for (final String vote : votes)
      for (int i = 0; i < teamSize; ++i)
        ++teams[vote.charAt(i) - 'A'].rank[i];

    Arrays.sort(teams, new Comparator<Team>() {
      @Override
      public int compare(Team a, Team b) {
        for (int i = 0; i < a.rank.length; ++i)
          if (a.rank[i] > b.rank[i])
            return -1;
          else if (a.rank[i] < b.rank[i])
            return 1;
        return a.name - b.name;
      }
    });

    for (int i = 0; i < teamSize; ++i)
      sb.append(teams[i].name);

    return sb.toString();
  }
}
