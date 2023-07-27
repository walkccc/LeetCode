class Allocator {
  public Allocator(int n) {
    memory = new int[n];
    mIDToIndices = new List[1001];
    for (int i = 1; i <= 1000; ++i)
      mIDToIndices[i] = new ArrayList<>();
  }

  public int allocate(int size, int mID) {
    int consecutiveFree = 0;
    for (int i = 0; i < memory.length; ++i) {
      consecutiveFree = memory[i] == 0 ? consecutiveFree + 1 : 0;
      if (consecutiveFree == size) {
        for (int j = i - consecutiveFree + 1; j <= i; ++j) {
          memory[j] = mID;
          mIDToIndices[mID].add(j);
        }
        return i - consecutiveFree + 1;
      }
    }
    return -1;
  }

  public int free(int mID) {
    List<Integer> indices = mIDToIndices[mID];
    final int freedUnits = indices.size();
    for (final int index : indices)
      memory[index] = 0;
    indices.clear();
    return freedUnits;
  }

  private int[] memory;
  private List<Integer>[] mIDToIndices;
}
