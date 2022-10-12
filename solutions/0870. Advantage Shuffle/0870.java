class Solution {
  public int[] advantageCount(int[] A, int[] B) {
    TreeMap<Integer, Integer> map = new TreeMap<>();

    for (int a : A)
      map.put(a, map.getOrDefault(a, 0) + 1);

    for (int i = 0; i < B.length; i++) {
      Integer key = map.higherKey(B[i]);
      if (key == null)
        key = map.firstKey();
      map.put(key, map.get(key) - 1);
      if (map.get(key) == 0)
        map.remove(key);
      A[i] = key;
    }

    return A;
  }
}
