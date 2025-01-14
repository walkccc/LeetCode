class Solution:
  def numComponents(self, head: ListNode | None, nums: list[int]) -> int:
    ans = 0
    numsSet = set(nums)

    while head:
      if head.val in numsSet and (
              head.next == None or head.next.val not in numsSet):
        ans += 1
      head = head.next

    return ans
