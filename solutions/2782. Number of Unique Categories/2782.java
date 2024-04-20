/**
 * Definition for a category handler.
 * class CategoryHandler {
 *   public CategoryHandler(int[] categories);
 *   public boolean haveSameCategory(int a, int b);
 * };
 */

class Solution {
  public int numberOfCategories(int n, CategoryHandler categoryHandler) {
    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (!haveSameCategoryPreviously(i, n, categoryHandler))
        ++ans;
    return ans;
  }

  private boolean haveSameCategoryPreviously(int i, int n, CategoryHandler categoryHandler) {
    for (int j = 0; j < i; ++j)
      if (categoryHandler.haveSameCategory(i, j))
        return true;
    return false;
  }
}
