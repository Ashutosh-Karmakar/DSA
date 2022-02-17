#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1;
int size = 10;
char *arr;

// void insert(char c){
//     arr[++top] = c; 
// }

// char pop(){
//     return arr[top--];
// }

// int main(){
//     char s[] = "{(([])[])[]}";
//     char n,y;
//     int i = 0;
//     while(s[i]!='\0'){
//         if(s[i] == '(' || s[i] == '{' || s[i] == '['){
//             insert(s[i]);
//             printf("if %c\n",s[i]);
//         }
//         if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
//             printf("else %c\n",s[i]);
//             n = arr[top];
//             printf("n %c\n",n);

//             switch(n){
//                 case '(':
//                     n = ')';
//                     break;
//                 case '{':
//                     n = '}';
//                     break;
//                 case '[':
//                     n = ']';
//                     break;
//             }

//             if(n != s[i]){
//                 y = pop();
//             }
//         }
//         i++;
//     }
//     if(top == -1){
//         printf("\nTRUE\n");
//     }
//     else{
//         printf("\nFALSE\n");
//     }
// }




// // Trial 2:


// void push(char c){
//     arr[++top] = c;
// }
// void pop(){
//     top--;
// }
// char* isBalanced(char* s) {
//     int i;
//     char n;
//     for(i=0;i<strlen(s);i++){
        
//         if(s[i] == '(' || s[i] == '{' || s[i] == '['){
//             push(s[i]);
//         }
//         if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
//             n = arr[top];
//             switch(n){
//                 case '(':
//                     n = ')';
//                     break;
//                 case '{':
//                     n = '}';
//                     break;
//                 case '[':
//                     n = ']';
//                     break;
//             }
//             if(s[i] == n){
//                 pop();
//             }
//             else{
//                 free(arr);
//                 return "NO";
//             }
//         }    
//     }
//     free(arr);
//     return "YES";

// }


// Trial: 3

void push(char c){
    arr[++top] = c;
}
void pop(){
    top--;
}
char* isBalanced(char* s) {
    arr = (char *)malloc(strlen(s) * sizeof(char));
    int i;
    char n;
    for(i=0;i<strlen(s);i++){
        
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            push(s[i]);
        }
        if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            n = arr[top];
            switch(n){
                case '(':
                    n = ')';
                    break;
                case '{':
                    n = '}';
                    break;
                case '[':
                    n = ']';
                    break;
            }
            if(s[i] == n){
                pop();
            }
            else{
                free(arr);
                return "NO";
            }
        }    
    }
    free(arr);
    return "YES";

}
int main(){
    printf("%s",isBalanced("[][]{}({({})}({})()(){})"));
}