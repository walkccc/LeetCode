class Solution {
 public:
  int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    int ans = 0;
    int i = 0;
    int j = plants.size() - 1;
    int canA = capacityA;
    int canB = capacityB;

    while (i < j) {
      ans += (canA < plants[i]) + (canB < plants[j]);
      if (canA < plants[i])
        canA = capacityA;
      if (canB < plants[j])
        canB = capacityB;
      canA -= plants[i++];
      canB -= plants[j--];
    }

    return ans + (i == j && max(canA, canB) < plants[i]);
  }
};
