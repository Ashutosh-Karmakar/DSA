import java.util.*;
class nextLargestElement {
    public static void main(String args[]){
        Stack<Integer> stack = new Stack<Integer>();
        int[] arr = {5,4,7,3,2,1};
        int[] nge = new int[arr.length];
        for(int i=arr.length-1;i>=0;i--){
            while(stack.size() != 0 && stack.peek() < arr[i]){
                stack.pop();
            }
            if(stack.size() == 0){
                nge[i] = -1;
            }
            else{
                nge[i] = stack.peek();
            }
            stack.push(arr[i]);
        }
        System.out.println("The array is :");
        for(int i:arr){
            System.out.print(i+"\t");
        }
        System.out.println("\nThe nge is :");
        for(int i:nge){
            System.out.print(i+"\t");
        }

    }
    
}
