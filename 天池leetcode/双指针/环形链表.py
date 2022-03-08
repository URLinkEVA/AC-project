# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # 空链表或链表只有一个节点，无环
        if not head or head.next == None:
            return False

        # 初始化快慢指针
        fast = slow = head

        # 如果不存在环，肯定 fast 先指向 null
        # 细节：fast 每次走 2 步，所以要确定 fast 和 fast.next 不为空，不然会报执行出错。
        while fast and fast.next:

            # 快指针移动 2 步，慢指针移动 1 步
            fast = fast.next.next
            slow = slow.next

            # 快慢指针相遇，有环
            if fast == slow:
                return True

        return False
