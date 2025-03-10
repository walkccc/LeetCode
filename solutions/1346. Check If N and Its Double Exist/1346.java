class Solution {
  public boolean checkIfExist(int[] arr) {
    Set<Integer> seen = new HashSet<>();

    for (final int a : arr) {
      if (seen.contains(a * 2) || a % 2 == 0 && seen.contains(a / 2))
        return true;
      seen.add(a);
    }

    return false;
  }
}
