struct Enemy {
  int damage;
  int timeTakenDown;
};

class Solution {
 public:
  long long minDamage(int power, vector<int>& damage, vector<int>& health) {
    long ans = 0;
    long sumDamage = accumulate(damage.begin(), damage.end(), 0L);
    vector<Enemy> enemies;

    for (int i = 0; i < damage.size(); ++i)
      enemies.emplace_back(damage[i], (health[i] + power - 1) / power);

    // It's better to take down the enemy i first if the damage dealt of taking
    // down i first is less than the damage dealt of taking down j first. So,
    //    damage[i] * t[i] + (t[i] + t[j]) * damage[j] <
    //    damage[j] * t[j] + (t[i] + t[j]) * damage[i]
    // => damage[i] * t[i] + damage[j] * t[i] + damage[j] * t[j] <
    //    damage[j] * t[j] + damage[i] * t[j] + damage[i] * t[i]
    // => damage[j] * t[i] < damage[i] * t[j]
    // => damage[j] / t[j] < damage[i] / t[i]
    ranges::sort(enemies, ranges::greater{}, [](const Enemy& e) {
      return static_cast<double>(e.damage) / e.timeTakenDown;
    });

    for (const Enemy& enemy : enemies) {
      ans += sumDamage * enemy.timeTakenDown;
      sumDamage -= enemy.damage;
    }

    return ans;
  }
};
