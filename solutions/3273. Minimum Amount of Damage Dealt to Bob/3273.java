class Enemy {
  public int damage;
  public int timeTakenDown;
  public Enemy(int damage, int timeTakenDown) {
    this.damage = damage;
    this.timeTakenDown = timeTakenDown;
  }
}

class Solution {
  public long minDamage(int power, int[] damage, int[] health) {
    long ans = 0;
    long sumDamage = Arrays.stream(damage).asLongStream().sum();
    Enemy[] enemies = new Enemy[damage.length];

    for (int i = 0; i < damage.length; ++i)
      enemies[i] = new Enemy(damage[i], (health[i] + power - 1) / power);

    // It's better to take down the enemy i first if the damage dealt of taking
    // down i first is less than the damage dealt of taking down j first. So,
    //    damage[i] * t[i] + (t[i] + t[j]) * damage[j] <
    //    damage[j] * t[j] + (t[i] + t[j]) * damage[i]
    // => damage[i] * t[i] + damage[j] * t[i] + damage[j] * t[j] <
    //    damage[j] * t[j] + damage[i] * t[j] + damage[i] * t[i]
    // => damage[j] * t[i] < damage[i] * t[j]
    // => damage[j] / t[j] < damage[i] / t[i]
    Arrays.sort(enemies,
                (a, b)
                    -> Double.compare((double) b.damage / b.timeTakenDown,
                                      (double) a.damage / a.timeTakenDown));

    for (final Enemy enemy : enemies) {
      ans += sumDamage * enemy.timeTakenDown;
      sumDamage -= enemy.damage;
    }

    return ans;
  }
}
