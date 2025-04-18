class Solution {
  public int[] toArray(Node node) {
    List<Integer> ans = new ArrayList<>();
    Node curr = node;

    while (curr.prev != null)
      curr = curr.prev;

    while (curr != null) {
      ans.add(curr.val);
      curr = curr.next;
    }

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
}
