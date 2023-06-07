class Solution {
 public:
  long long minimumHealth(vector<int>& damage, int armor) {
    const long long sum = accumulate(begin(damage), end(damage), 0LL);
    const int maxDamage = *max_element(begin(damage), end(damage));
    return 1 + sum - min(maxDamage, armor);
  }
};
