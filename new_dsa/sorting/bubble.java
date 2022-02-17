class A{
    public static void main(String args[]){
        int arr[] = {4,2,4,9,10,1,0};
        int n = arr.length;
        System.out.println(n);

        for(int i:arr){
            System.out.print(i + " ");
        }
        System.out.println();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        
        for(int i:arr){
            System.out.print(i + " ");
        }
    }
}