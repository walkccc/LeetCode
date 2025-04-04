class NumberContainers {
  public void change(int index, int number) {
    if (indexToNumbers.containsKey(index)) {
      final int originalNumber = indexToNumbers.get(index);
      numberToIndices.get(originalNumber).remove(index);
      if (numberToIndices.get(originalNumber).isEmpty())
        numberToIndices.remove(originalNumber);
    }
    indexToNumbers.put(index, number);
    numberToIndices.putIfAbsent(number, new TreeSet<>());
    numberToIndices.get(number).add(index);
  }

  public int find(int number) {
    if (numberToIndices.containsKey(number))
      return numberToIndices.get(number).first();
    return -1;
  }

  private Map<Integer, TreeSet<Integer>> numberToIndices = new HashMap<>();
  private Map<Integer, Integer> indexToNumbers = new HashMap<>();
}
