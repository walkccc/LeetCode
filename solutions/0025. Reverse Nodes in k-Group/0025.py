class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or k == 1:
            return head

        dummy = ListNode(0)
        dummy.next = head
        length = 0
        curr = head
        while curr:
            length += 1
            curr = curr.next

        prev = dummy
        curr = head

        for i in range(length // k):
            for j in range(k - 1):
                next = curr.next
                curr.next = next.next
                next.next = prev.next
                prev.next = next
            prev = curr
            curr = curr.next

        return dummy.next
