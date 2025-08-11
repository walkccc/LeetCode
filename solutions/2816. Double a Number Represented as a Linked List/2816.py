class Solution:
  def doubleIt(self, head: ListNode | None) -> ListNode | None:
    def getCarry(node: ListNode | None) -> ListNode | None:
      val = node.val * 2
      if node.next:
        val += getCarry(node.next)
      node.val = val % 10
      return val // 10

    if getCarry(head) == 1:
      return ListNode(1, head)
    return head
