class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        prefixSum = 0
        prefixSumToNode = {0: dummy}

        while head:
            prefixSum += head.val
            prefixSumToNode[prefixSum] = head
            head = head.next

        prefixSum = 0
        head = dummy

        while head:
            prefixSum += head.val
            head.next = prefixSumToNode[prefixSum].next
            head = head.next

        return dummy.next
