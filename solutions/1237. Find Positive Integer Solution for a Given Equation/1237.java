class Solution {
  public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
    List<List<Integer>> ans = new LinkedList<>();
    int x = 1;
    int y = 1000;

    while (x <= 1000 && y >= 1) {
      int f = customfunction.f(x, y);
      if (f < z)
        ++x;
      else if (f > z)
        --y;
      else
        ans.add(Arrays.asList(x++, y--));
    }

    return ans;
  }
}
