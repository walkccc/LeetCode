class Solution:
  def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(0, head)
    numsSet = set(nums)

    curr = dummy
    while curr.next:
      if curr.next.val in numsSet:
        curr.next = curr.next.next
      else:
        curr = curr.next

    return dummy.next
