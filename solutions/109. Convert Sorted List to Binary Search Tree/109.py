class Solution:
  def sortedListToBST(self, head: ListNode) -> TreeNode:
    def findMid(head: ListNode) -> ListNode:
      prev = None
      slow = head
      fast = head

      while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next
      prev.next = None

      return slow

    if not head:
      return None
    if not head.next:
      return TreeNode(head.val)

    mid = findMid(head)
    root = TreeNode(mid.val)
    root.left = self.sortedListToBST(head)
    root.right = self.sortedListToBST(mid.next)

    return root
