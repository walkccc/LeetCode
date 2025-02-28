class Solution {
 public:
  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    const int appleSum = accumulate(apple.begin(), apple.end(), 0);
    int capacitySum = 0;

    ranges::sort(capacity, greater<>());

    for (int i = 0; i < capacity.size(); ++i) {
      capacitySum += capacity[i];
      if (capacitySum >= appleSum)
        return i + 1;
    }

    return capacity.size();
  }
};
