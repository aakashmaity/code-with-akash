# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        return self.level_order_traversal(root)
        

    def level_order_traversal(self, node: Optional[TreeNode]) -> int:
        if not node:
            return 0
        
        result = []
        q = []

        q.append(node)

        while (len(q)):
            top = q[0]
            q.pop(0)
            result.append(top.val)
            
            if top.left:
                q.append(top.left)
            if top.right:
                q.append(top.right)

            
        return len(result)