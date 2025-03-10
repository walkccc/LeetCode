class Solution {
 public:
  vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters,
                                 vector<int>& coins) {
    const vector<pair<int, int>> monsterAndCoins =
        getSortedMonsterAndCoins(monsters, coins);
    vector<long long> ans;
    vector<long long> coinsPrefix{0};

    for (const auto& [_, coin] : monsterAndCoins)
      coinsPrefix.push_back(coinsPrefix.back() + coin);

    for (const int hero : heroes)
      ans.push_back(coinsPrefix[firstGreaterEqual(monsterAndCoins, hero)]);

    return ans;
  }

 private:
  vector<pair<int, int>> getSortedMonsterAndCoins(const vector<int>& monsters,
                                                  const vector<int>& coins) {
    vector<pair<int, int>> monsterAndCoins;
    for (int i = 0; i < monsters.size(); ++i)
      monsterAndCoins.emplace_back(monsters[i], coins[i]);
    ranges::sort(monsterAndCoins);
    return monsterAndCoins;
  }

  int firstGreaterEqual(const vector<pair<int, int>>& monsterAndCoins,
                        int hero) {
    int l = 0;
    int r = monsterAndCoins.size();
    while (l < r) {
      const int m = (l + r) / 2;
      if (monsterAndCoins[m].first > hero)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
