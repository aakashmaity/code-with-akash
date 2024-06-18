class MyLinkedList {
    private Node head;
    private Node tail;
    private int length = 0;

    public MyLinkedList() {

    }
    private class Node {
        int val;
        Node prev;
        Node next;

        private Node(int val) {
            this.val = val;
        }
    }

    public int get(int index) {
        if (index >= length) {
            return -1;
        }
        Node curr = head;
        while (index > 0) {
            curr = curr.next;
            if (curr == null) {
                return -1;
            }
            index--;
        }
        return curr.val;
    }

    public void addAtHead(int val) {
        Node curr = new Node(val);
        if(length == 0){
            head = curr;
            tail = curr;
        } 
        else{
            curr.next = head;
            head.prev = curr;
            head = curr;
        }
        length++;
    }

    public void addAtTail(int val) {
        Node curr = new Node(val);
        if(length == 0){
            head = curr;
            tail = curr;
        } 
        else{
            tail.next = curr;
            curr.prev = tail;
            tail = curr;
        }
        length++;
    }

    public void addAtIndex(int index, int val) {
        if(index > length){
            return;
        }

        if(index == 0){
            addAtHead(val);
            return;
        }

        if(index == length){
            addAtTail(val);
            return;
        }

        Node newNode = new Node(val);
        Node curr = head;
        while(index > 0){
            curr = curr.next;
            index--;
        }
        newNode.prev = curr.prev;
        newNode.next = curr;
        curr.prev.next = newNode;
        curr.prev = newNode;
        length++;
    }

    public void deleteAtIndex(int index) {
        if (index >= length) return;

        if (index == 0) {
            head = head.next;
            length--;
            return;
        }

        if (index == length - 1) {
            tail = tail.prev;
            tail.next = null;
            length--;
            return;
        }

        Node curr = head;
        while (index-- > 0) {
            curr = curr.next;
            if (curr == null) return;
        }
        curr.prev.next = curr.next;
        curr.next.prev = curr.prev;
        length--;     
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */