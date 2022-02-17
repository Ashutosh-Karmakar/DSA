class A{
    static int search(int arr[],int f, int l,int k){
       if(l>=f){
            int mid = (f+l)/2;
            if(arr[mid] == k){
                return 1;
            }
            else if(arr[mid] > k){
                return search(arr,f,mid-1,k);
            }
            else{
                return search(arr,mid+1,l,k);
            }
        }
        return -1;
    }
    public static void main(String args[]){
        int arr1[] = {2,4,5,7,8,10,12};
        int arr2[] = {1,2,3,6,12};
        int n1 = arr1.length;
        int n2 = arr2.length;
        int same[] = new int[30];
        int k=0;
        for(int i=0;i<n2;i++){
            if(search(arr1,0,n1-1,arr2[i])==1){
                // System.out.print(arr2[i]+"\t");  
                same[k++] = arr2[i];
                 
            }
        }
        for(int i:same){
            System.out.print(i+"\t");    
        }
        

        // System.out.println(search(arr1,0,n1-1,4));
    }
    
}