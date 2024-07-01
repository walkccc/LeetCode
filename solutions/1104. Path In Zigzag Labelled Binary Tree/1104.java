class Solution {
  public List<Integer> pathInZigZagTree(int label) {
    LinkedList<Integer> ans = new LinkedList<>();
    int level = 0;

    for (int l = 0; l < 21; ++l)
      if (Math.pow(2, l) > label) {
        level = l - 1;
        break;
      }

    if (level % 2 == 1)
      label = boundarySum(level) - label;

    for (int l = level; l >= 0; --l) {
      ans.addFirst(l % 2 == 1 ? boundarySum(l) - label : label);
      label /= 2;
    }

    return new ArrayList<>(ans);
  }

  private int boundarySum(int level) {
    return (int) Math.pow(2, level) + (int) Math.pow(2, level + 1) - 1;
  }
}
