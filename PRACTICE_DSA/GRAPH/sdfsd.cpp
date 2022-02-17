int ans = 0;
int cnt = 0;
while(true){
    int i = 0;
    for(;i<n;i++){
        if(array[i] %2 != 0){
            break;
        }
        else if(array[i] == 0){
            cnt ++;
        }
    }
    if(cnt == n){
        return ans;
    }
    if(i == n){
        for(int k = 0;k<n;k++){
            array[k] = array[k]/2;
        }
        ans++;
    }
    for(int k=0;k<n;k++){
        if(array[k]%2 != 0){
            array[k]--;
            ans ++;
        }
        
    }
    return ans;
}