class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        curr = dummy
        carry = 0

        while carry or l1 or l2:
            carry += (l1.val if l1 else 0) + (l2.val if l2 else 0)
            curr.next = ListNode(carry % 10)
            curr = curr.next
            carry //= 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy.next
