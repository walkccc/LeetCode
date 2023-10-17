class Solution {
 public:
  int reachNumber(int target) {
    const int newTarget = abs(target);
    int ans = 0;
    int pos = 0;

    while (pos < newTarget)
      pos += ++ans;
    while ((pos - newTarget) & 1)
      pos += ++ans;

    return ans;
  }
};
