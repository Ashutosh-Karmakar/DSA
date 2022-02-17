import java.util.LinkedList;

class Main{
    public static void main(String args[]){
        LinkedList<Integer> ll = new LinkedList<Integer>();
        ll.add(10);
        ll.add(20);
        ll.add(30);
        ll.addFirst(40);
        ll.addLast(50);
        ll.removeFirst();
        ll.removeLast();
        System.out.println(ll.getFirst());
        System.out.println(ll.getLast());
        System.out.println(ll);
        System.out.println(ll.size());
    }
}
