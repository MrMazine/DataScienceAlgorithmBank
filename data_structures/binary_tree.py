class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key

class BinaryTree:
    def __init__(self, root_value):
        self.root = Node(root_value)

    def insert(self, value):
        self._insert_recursive(self.root, value)

    def _insert_recursive(self, current_node, value):
        if value < current_node.value:
            if current_node.left is None:
                current_node.left = Node(value)
            else:
                self._insert_recursive(current_node.left, value)
        else:
            if current_node.right is None:
                current_node.right = Node(value)
            else:
                self._insert_recursive(current_node.right, value)

    def inorder_traversal(self, node):
        elements = []
        if node:
            elements += self.inorder_traversal(node.left)
            elements.append(node.value)
            elements += self.inorder_traversal(node.right)
        return elements

# Example usage:
if __name__ == "__main__":
    bt = BinaryTree(10)
    bt.insert(6)
    bt.insert(15)
    bt.insert(3)
    print("Inorder traversal:", bt.inorder_traversal(bt.root))
