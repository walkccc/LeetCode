class Solution {
 public:
  long long minimumHealth(vector<int>& damage, int armor) {
    const long sum = accumulate(damage.begin(), damage.end(), 0L);
    const int maxDamage = ranges::max(damage);
    return 1 + sum - min(maxDamage, armor);
  }
};
