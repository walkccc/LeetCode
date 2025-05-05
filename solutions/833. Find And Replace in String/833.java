class Solution {
  public String findReplaceString(String s, int[] indices, String[] sources, String[] targets) {
    record Operation(int index, String source, String target) {}
    Operation[] operations = new Operation[indices.length];

    for (int i = 0; i < indices.length; ++i)
      operations[i] = new Operation(indices[i], sources[i], targets[i]);

    Arrays.sort(operations, Comparator.comparing(Operation::index, Comparator.reverseOrder())
                                .thenComparing(Operation::source, Comparator.reverseOrder())
                                .thenComparing(Operation::target, Comparator.reverseOrder()));

    for (Operation op : operations)
      if (s.substring(op.index, Math.min(op.index + op.source.length(), s.length()))
              .equals(op.source))
        s = s.substring(0, op.index) + op.target + s.substring(op.index + op.source.length());

    return s;
  }
}
