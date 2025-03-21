class RandomizedCollection {
  public boolean insert(int val) {
    valToIndices.putIfAbsent(val, new ArrayList<>());
    valToIndices.get(val).add(items.size());
    items.add(new Item(val, valToIndices.get(val).size() - 1));
    return valToIndices.get(val).size() == 1;
  }

  public boolean remove(int val) {
    if (!valToIndices.containsKey(val))
      return false;

    final int index = lastIndex(valToIndices.get(val));
    valToIndices.get(last(items).val).set(last(items).indexInMap, index);
    final int indicesSize = valToIndices.get(val).size();
    valToIndices.get(val).remove(indicesSize - 1);
    if (valToIndices.get(val).isEmpty())
      valToIndices.remove(val);
    items.set(index, last(items));
    items.remove(items.size() - 1);
    return true;
  }

  public int getRandom() {
    final int index = rand.nextInt(items.size());
    return items.get(index).val;
  }

  private record Item(int val, int indexInMap) {}

  private Map<Integer, List<Integer>> valToIndices = new HashMap<>();
  private List<Item> items = new ArrayList<>();
  private Random rand = new Random();

  private int lastIndex(List<Integer> indices) {
    return indices.get(indices.size() - 1);
  }

  private Item last(List<Item> items) {
    return items.get(items.size() - 1);
  }
}
