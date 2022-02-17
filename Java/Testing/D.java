import java.util.*;
class D{
    public static void main(String args[]){
        int n = 37;
        ArrayList<Integer> a = new ArrayList<>();
        for(int i=0;i<n+1;i++){
            a.add(0);
        }
        a.set(1,1);
        for(int i=2;i<n+1;i++){
            if(a.get(i) == 0){
                a.set(i,i);
            }
            for(int j=i*2;j<n+1;j+=i){
                if(a.get(j) == 0)
                    a.set(j,i);
            }
        }
        // for(int i:a){
        //     System.out.print(i + " ");
        // }
        System.out.println("The prime Factors of " + n + " is:");
        while(n!=1){
            System.out.print(a.get(n) + " ");
            n /= a.get(n);
        }
        System.out.print(n);
        System.out.println();
        
    }
}