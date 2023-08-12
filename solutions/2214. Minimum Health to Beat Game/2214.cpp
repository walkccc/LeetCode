class Solution {
 public:
  long long minimumHealth(vector<int>& damage, int armor) {
    const long long sum = accumulate(damage.begin(), damage.end(), 0LL);
    const int maxDamage = *max_element(damage.begin(), damage.end());
    return 1 + sum - min(maxDamage, armor);
  }
};
