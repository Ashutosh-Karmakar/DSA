import java.io.*;
import java.util.*;
class A{
    public static void main(String args[]){
        Stack<Character> stack = new Stack<Character>();
        String s = "{{{(({}))}}}]";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='{' || s.charAt(i)=='[' || s.charAt(i)=='(' ){
                stack.push(s.charAt(i));
            } 
            else{
                if(stack.size() == 0){stack.push(s.charAt(i));break;}
                switch(s.charAt(i)){
                    case '}':
                        if(stack.peek() == '{'){
                            stack.pop();
                        }
                        break;
                    case ']':
                        if(stack.peek() == '['){
                            stack.pop();
                        }
                        break;

                    case ')':
                        if(stack.peek() == '('){
                            stack.pop();
                        }
                        break;
                }
            }
        }
        if(stack.size() == 0){
            System.out.println("Balanced");
        }
        else{
            System.out.println("Unbalanced");
        }
    }
    
}