class Solution:
    # 归并排序
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next: 
            return head
        left_end = self.find_mid(head)
        mid = left_end.next 
        left_end.next = None
        left, right = self.sortList(head), self.sortList(mid)
        return self.merged(left, right)
    # 快慢指针查找链表中点
    def find_mid(self, head):
        if head is None or head.next is None: return head
        slow,fast = head, head.next
        while fast is not None and fast.next is not None:
            slow=slow.next
            fast=fast.next.next
        return slow
    # 合并有序链表
    def merged(self, left, right):
        res = ListNode()
        h = res
        while left and right:
            if left.val < right.val: 
                h.next, left = left, left.next
            else: 
                h.next, right = right, right.next
            h = h.next
        h.next = left if left else right
        return res.next
