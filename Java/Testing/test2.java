import java.util.*;
class A{
    static void sum(int arr[]){
        arr[1] = 4;

    }
}
class test2 {
    public static void main(String args[]){
        int arr[] = new int[3];
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        String s1 = "ashu tosh";
        StringBuilder s2 = new StringBuilder(s1);
        s2.split('\t');
        System.out.println(s2);
        for(int i:arr){
            System.out.print(i + "\t");
        }
        A.sum(arr);
        System.out.println("\nAfter change");
        for(int i:arr){
            System.out.print(i + "\t");
        }
        // ArrayList<Integer> a = new ArrayList<>();
        // a.add(6);
        // a.add(5);
        // a.add(4);
        // a.add(3);
        // a.add(2);
        // a.add(1);
        // for(int i:a){
        //     System.out.print(i + "\t");
        // }
        // System.out.println("\n get:"+a.get(2));
        // a.set(0,10);
        // a.remove(5);
        // for(int i:a){
        //     System.out.print(i + "\t");
        // }
        // System.out.println("\n size:"+a.size());
        // Collections.sort(a);
        // for(int i:a){
        //     System.out.print(i + "\t");
        // }
    }
    
}
