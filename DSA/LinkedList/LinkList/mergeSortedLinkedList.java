

import LinkList.*;

public class mergeSortedLinkedList {
    void merge(LinkList.LinkedList l1,LinkList.LinkedList l2){
        if(l1.data < l2.data){
            LinkList.LinkedList temp = l1;
            l1 = l2;
            l2 = temp;
        }
        LinkList.LinkedList res = l1;
        LinkList.LinkedList temp = l1;
        while(l1!=null && l2!=null){
            if(l1.data > l2.data){
                temp = l1;
                l1 = l1.nxt;
            }
            if(l1.data < l2.data){
                temp.nxt = l2;
                LinkList.Node temp = l1;
                l1 = l2;
                l2 = temp;
            }
        }
        LinkList.LinkedList result = new LinkList.LinkedList();
        result.print(res);

    }
    public static void main(String args[]){
        LinkList.LinkedList l1 = new LinkList.LinkedList();
        System.out.println("1st LinkedList");
        l1.insert(10);
        l1.insert(20);
        l1.insert(30);
        l1.insert(35);
        l1.insert(50);
        l1.print(l1.head);

        LinkList.LinkedList l2 = new LinkList.LinkedList();
        System.out.println("\n2nd LinkedList");
        l2.insert(9);
        l2.insert(15);
        l2.insert(40);
        l2.insert(55);
        l2.insert(60);
        l2.print(l2.head);
    }
}
