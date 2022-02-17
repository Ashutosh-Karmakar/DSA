package LinkList;

class Node {
    int data;
    Node nxt;
    Node(int data){
        this.data = data;
        nxt = null;
    }
}
public class LinkedList{
    public Node head = null;
    public void insertFront(int data){
        Node node = new Node(data);
        node.nxt = head;
        head = node;
    }
    public void insert(int data){
        Node node = new Node(data);
        if(head == null){
            head = node;
        }
        else{
            Node n = head;
            while(n.nxt != null){
                n = n.nxt;
            }
            n.nxt = node;
        }
    }
    public void deleteEnd(){
        Node n = head;
        while(n.nxt.nxt!=null){
            n = n.nxt;
        }
        n.nxt = null;
    }
    public void deleteFront(){
        head = head.nxt;
    }
    public void print(Node p){
        Node n = p;
        System.out.print(n.data);
        n = n.nxt;
        while( n != null ){
            System.out.print("-->");
            System.out.print(n.data);
            n = n.nxt;
        }
    }
    public Node reverse(){
        Node n = head;
        Node prev = null;
        Node cur = n;
        Node next = n.nxt;
        while(cur != null){
            Node temp = cur;
            cur.nxt = prev;
            prev = temp;
            cur = next;
            if(next != null)
                next = next.nxt;
        }
        return prev;
    }
}
// class A{
//     public static void main(String[] args){
//         LinkedList ll = new LinkedList();
//         ll.insert(10);
//         ll.insert(20);
//         ll.insert(30);
//         ll.insert(40);
//         ll.insertFront(30);
//         ll.deleteFront();
//         ll.print(ll.head);
//         System.out.println("\nReversed:");
//         ll.print(ll.reverse());
//     }
// }