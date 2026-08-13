class Node:
    def __init__(self, val):
        self.val = val
        self.nxt = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    def add(self, x):
        node = Node(x)
        if tail is None:
            head = node
            tail = node
        else:
            tail.nxt = node
            tail = node
if __name__ == '__main__':
    