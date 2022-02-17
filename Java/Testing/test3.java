import java.util.*;

// import javax.swing.text.DefaultStyledDocument.ElementSpec;


class A{
    A(){}
   
    public static void main(String args[]){
        ArrayList<Integer> a = new ArrayList<>();
        a.add(15);
        a.add(12);
        a.add(12);
        a.add(15);
        a.add(10);
       
        a.add(10);
        a.add(10);
        a.add(15);
        a.add(15);
       
       
        // Collections.sort(a);
        // int count = 0;
        // for(int i=0;i<a.size();i++){      
        //     if(i==a.size()-1){
        //         if(a.get(i-1) == a.get(i)){
        //             count++;
        //         }
        //         if(count%2 != 0){
        //             System.out.println(a.get(i));
        //             return;
        //         }
        //     }      
        //     else{
        //         if(a.get(i) == a.get(i+1)){
        //         count++;
        //         }
            

        //         if(a.get(i) != a.get(i+1)){
        //             count++;
        //             if(count%2 != 0){
        //                 System.out.println(a.get(i));
        //                 return;
        //             }
        //             count = 0;
                    
                
        //         }
        //     }
         
            
        // }
        // System.out.println("No output");

        int xor=0;
        for(int i:a){
            xor = xor ^ i;
        }
        System.out.println(xor);
        
    }
}