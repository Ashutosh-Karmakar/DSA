import java.util.ArrayList;
class Main{
    public static void main(String args[]){
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);

        System.out.println(arr);
        arr.set(0,5);
        System.out.println(arr);
        System.out.println(arr.size());
        arr.remove(0);
        System.out.println(arr.size());

    }
}