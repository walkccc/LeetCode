class TwoSum {
  public void add(int number) {
    count.merge(number, 1, Integer::sum);
  }

  public boolean find(int value) {
    for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
      final int key = entry.getKey();
      final int remain = value - key;
      if (key == remain && entry.getValue() > 1)
        return true;
      if (key != remain && count.containsKey(remain))
        return true;
    }

    return false;
  }

  private HashMap<Integer, Integer> count = new HashMap<>();
}
