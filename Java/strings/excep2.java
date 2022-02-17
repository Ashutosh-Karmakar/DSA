import java.lang.invoke.TypeDescriptor;

import javax.print.event.PrintJobListener;

class excep2 {
    static int arr[] = {2,5};
    static void test(int p){
        try{
            if(p != 0)
                arr[4] = 2;
            int j = 2/p;
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("ex1");
        }
        catch(Exception e){
            System.out.println("ex2");

        }
        finally{
            System.out.println("In Finally block");
        }
    }
    public static void main(String args[]){
        test(1);
    }
}
