class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            last = self.head
            while last.next:
                last = last.next
            last.next = new_node

    def display(self):
        nodes = []
        current = self.head
        while current:
            nodes.append(current.data)
            current = current.next
        return nodes

    def delete(self, data):
        current = self.head
        if current is not None:
            if current.data == data:
                self.head = current.next
                current = None
                return

        prev = None
        while current is not None:
            if current.data == data:
                break
            prev = current
            current = current.next

        if current is None:
            return

        prev.next = current.next
        current = None

# Example usage:
if __name__ == "__main__":
    ll = LinkedList()
    ll.insert(1)
    ll.insert(2)
    ll.insert(3)
    print("Linked list:", ll.display())
    ll.delete(2)
    print("After deletion:", ll.display())
