#include<iostream>
#include<string>
using namespace std;

int rabin(string txt,string ptn){
    int d = 256;
    int p = 0; // hash for pattern;
    int t = 0; // hash for text;
    int h = 1;
    int q = 101;
    int N = txt.length();
    int M = ptn.length();

    int cnt = 0;
    for(int i=0;i<M-1;i++){
        h = (h * d) % q;
    }
    for(int i=0;i<M;i++){
        p = (p*d + ptn[i])%q;
        t = (t*d + txt[i])%q;
    }
    for(int i=0;i<N;i++){
        // cout << i << txt[i] << endl;
        cout << p << " " << t << " " << txt[i] << endl;
        if(p == t){
            int j = 0;
            while(j < M){
                if(txt[i+j] != ptn[j]){
                    break;
                }
                j++;
            }
            if(j == M){
                cnt ++;
            }
        }
        if(i < N-M){
            //   shifter  old       remove         new character
            t = ( ( d   *  (t   -   txt[i]*h   ) )+ txt[i+M])%q;

            if(t < 0){
                t = t+q;
            }

        }
    }
    return cnt;
}

int main(){
    string txt = "hello";
    string ptn = "ll";

    cout << "The pattern occurs : " << rabin(txt,ptn) << " times." << endl;
}