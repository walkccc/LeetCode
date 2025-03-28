class Solution {
  public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
    return dfs(price, special, needs, 0);
  }

  private int dfs(List<Integer> price, List<List<Integer>> special, List<Integer> needs, int s) {
    int ans = 0;
    for (int i = 0; i < needs.size(); ++i)
      ans += needs.get(i) * price.get(i);

    for (int i = s; i < special.size(); ++i) {
      List<Integer> offer = special.get(i);
      if (isValid(offer, needs)) {
        // Use the special[i].
        for (int j = 0; j < needs.size(); ++j)
          needs.set(j, needs.get(j) - offer.get(j));
        ans = Math.min(ans, offer.get(offer.size() - 1) + dfs(price, special, needs, i));
        // Unuse the special[i] (backtracking).
        for (int j = 0; j < needs.size(); ++j)
          needs.set(j, needs.get(j) + offer.get(j));
      }
    }

    return ans;
  }

  // Returns true if this special offer is a valid one.
  private boolean isValid(List<Integer> offer, List<Integer> needs) {
    for (int i = 0; i < needs.size(); ++i)
      if (offer.get(i) > needs.get(i))
        return false;
    return true;
  }
}
