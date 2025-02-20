class Solution {
  public int[] toArray(Node head) {
    List<Integer> ans = new ArrayList<>();
    Node curr = head;

    while (curr != null) {
      ans.add(curr.val);
      curr = curr.next;
    }

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
}
