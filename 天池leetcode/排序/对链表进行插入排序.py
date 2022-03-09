# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        def insert_sort(head2, target):
            tmp_head = head2.next
            pre = head2
            while tmp_head and tmp_head.val <= target.val:
                pre = tmp_head
                tmp_head = tmp_head.next
            pre.next = target
            target.next = tmp_head

        new_head = ListNode(0)
        while head:
            t = head.next
            insert_sort(new_head, head)
            head = t
        return new_head.next
