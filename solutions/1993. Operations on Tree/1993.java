class Node {
  public List<Integer> children = new ArrayList<>();
  public int lockedBy = -1;
}

class LockingTree {
  public LockingTree(int[] parent) {
    this.parent = parent;
    nodes = new Node[parent.length];
    for (int i = 0; i < parent.length; ++i)
      nodes[i] = new Node();
    for (int i = 1; i < parent.length; ++i)
      nodes[parent[i]].children.add(i);
  }

  public boolean lock(int num, int user) {
    if (nodes[num].lockedBy != -1)
      return false;
    nodes[num].lockedBy = user;
    return true;
  }

  public boolean unlock(int num, int user) {
    if (nodes[num].lockedBy != user)
      return false;
    nodes[num].lockedBy = -1;
    return true;
  }

  public boolean upgrade(int num, int user) {
    if (nodes[num].lockedBy != -1)
      return false;
    if (!anyLockedDescendant(num))
      return false;

    // Walk up the hierarchy to ensure that there are no locked ancestors.
    for (int i = num; i != -1; i = parent[i])
      if (nodes[i].lockedBy != -1)
        return false;

    unlockDescendants(num);
    nodes[num].lockedBy = user;
    return true;
  }

  public boolean anyLockedDescendant(int i) {
    return nodes[i].lockedBy != -1 ||
        nodes[i].children.stream().anyMatch(child -> anyLockedDescendant(child));
  }

  public void unlockDescendants(int i) {
    nodes[i].lockedBy = -1;
    for (final int child : nodes[i].children)
      unlockDescendants(child);
  }

  private int[] parent;
  private Node[] nodes;
}
