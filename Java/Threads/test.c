#include<stdio.h>
int main(){
    char *c = "ashu";
    printf("%s",c);
    for(int i=0;c[i]!='\0';i++){
        if(c[i] == 'a'){
            c[i] = 'A';
        }
    }
    printf("%s",c);
}