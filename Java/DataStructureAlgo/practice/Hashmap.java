import java.util.HashMap;

class Main{
    public static void main(String args[]){
        HashMap<Integer,String> m = new HashMap<Integer,String>();
        m.put(1,"Ashu");
        m.put(2,"Anshu");
        System.out.println(m);
        System.out.println(m.size());
        for(String i:m.values()){
            System.out.println(i);
        }        
    }
}
