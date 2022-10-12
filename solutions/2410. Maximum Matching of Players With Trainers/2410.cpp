class Solution {
 public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    int ans = 0;

    sort(begin(players), end(players));
    sort(begin(trainers), end(trainers));

    for (int i = 0; i < trainers.size(); ++i)
      if (players[ans] <= trainers[i] && ++ans == players.size())
        return ans;

    return ans;
  }
};
