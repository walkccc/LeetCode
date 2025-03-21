class Solution {
 public:
  long long maxWeight(vector<int>& pizzas) {
    const int eat = pizzas.size() / 4;
    const int odd = (eat - 1) / 2 + 1;  // ceil(eat / 2)
    const int even = eat - odd;
    long ans = 0;
    int i = 0;  // pizzas' index

    ranges::sort(pizzas, std::greater<>());

    for (int j = 0; j < odd; ++j, i += 1)
      ans += pizzas[i];

    for (int j = 0; j < even; ++j, i += 2)
      ans += pizzas[i + 1];

    return ans;
  }
};
