class Solution {
  public long maxWeight(int[] pizzas) {
    final int eat = pizzas.length / 4;
    final int odd = (eat - 1) / 2 + 1; // ceil(eat / 2)
    final int even = eat - odd;
    long ans = 0;
    int i = pizzas.length - 1; // pizzas' index

    Arrays.sort(pizzas);

    for (int j = 0; j < odd; ++j, i -= 1)
      ans += pizzas[i];

    for (int j = 0; j < even; ++j, i -= 2)
      ans += pizzas[i - 1];

    return ans;
  }
}
