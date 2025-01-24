class Solution:
  def nextLargerNodes(self, head: ListNode) -> list[int]:
    ans = []
    stack = []

    while head:
      while stack and head.val > ans[stack[-1]]:
        index = stack.pop()
        ans[index] = head.val
      stack.append(len(ans))
      ans.append(head.val)
      head = head.next

    for i in stack:
      ans[i] = 0

    return ans
