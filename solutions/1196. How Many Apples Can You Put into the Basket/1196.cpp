class Solution {
 public:
  int maxNumberOfApples(vector<int>& weight) {
    int sum = 0;

    ranges::sort(weight);

    for (int i = 0; i < weight.size(); ++i) {
      sum += weight[i];
      if (sum > 5000)
        return i;
    }

    return weight.size();
  }
};
