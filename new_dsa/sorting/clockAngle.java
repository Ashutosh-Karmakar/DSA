import java.util.Scanner;

class A {
    static float function(int H,int M){
        int m = (M/5);
        float k = (float)m;
        k = (float) ((k*5)+2.5);
        if(M > k){
            m = m+1;
        }
        
        
        

        int diff = m-H;
        if(diff < 0){
            diff = diff*(-1);
        }
        float angle = diff*30;
        float extra;
        if(M%5 == 0){
            extra = (float)M/2;   
        }
        else{
            int e = (M-(m*5));
            
            if(e < 0) e=e*(-1);
            angle += e*6;
            extra = (float)M/2;
            // System.out.println(extra);
            
        }
        if(H > m){
            angle = angle + extra;
        }
        else{
            angle = angle - extra;
        }
        return angle;
    }
    public static void main(String args[]){
        int H;
        int M;
        Scanner sc = new Scanner(System.in);
        H = sc.nextInt();
        M = sc.nextInt();
        System.out.println(function(H,M));
        System.out.println(360.0-function(H,M));
    }
}
