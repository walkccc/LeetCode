class Solution {
  public int matchPlayersAndTrainers(int[] players, int[] trainers) {
    int ans = 0;

    Arrays.sort(players);
    Arrays.sort(trainers);

    for (int i = 0; i < trainers.length; ++i)
      if (players[ans] <= trainers[i] && ++ans == players.length)
        return ans;

    return ans;
  }
}
