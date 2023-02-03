class Solution:
  def numComponents(self, head: ListNode, G: List[int]) -> int:
    ans = 0
    G = set(G)

    while head:
      if head.val in G and (head.next == None or head.next.val not in G):
        ans += 1
      head = head.next

    return ans
