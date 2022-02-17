import java.util.*;
class A{
    public static void main(String args[]){
        Queue<Integer> q = new LinkedList<>();
        q.add(2);
        q.add(3);
        q.add(4);
        // System.out.println(q.poll());
        // System.out.println(q.poll());
        System.out.println(q.peek());
    }
}