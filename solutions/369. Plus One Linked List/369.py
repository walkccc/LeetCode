class Solution:
  def plusOne(self, head: ListNode) -> ListNode:
    if not head:
      return ListNode(1)
    if self._addOne(head) == 1:
      return ListNode(1, head)
    return head

  def _addOne(self, node: ListNode) -> int:
    carry = self._addOne(node.next) if node.next else 1
    summ = node.val + carry
    node.val = summ % 10
    return summ // 10
