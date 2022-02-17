import java.util.*;
import javafx.util.Pair;

class A{
    public static void main(String args[]){
        TreeMap<Integer,Integer> map = new TreeMap<>();
        map.put(100,20);
        map.put(-1,10);
        map.put(-2,30);
        for(int x:map.values()){
            System.out.print(x + " ");
        }
        System.out.println();
        Pair <Integer,Integer> q = new Pair <>(2,3);
        // q.add(new Pair <Integer,Integer>(1,2));
        // System.out.println(q.remove());
    }
}