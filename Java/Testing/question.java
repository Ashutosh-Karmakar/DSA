class question {
    static void sort(int[] arr,int r){
        int temp;
        int i = arr.length-2;
        int key = arr[r];
        while(i>=0 && arr[i] > key){
            
            temp = arr[i];
            arr[i] = arr[r];
            arr[r] = temp;
            r = i;
        
        }
    }

    public static void main(String args[]){
        int[] arr1 = {1,3,7};
        int[] arr2 = {2,3,4,7};

        int n1 = arr1.length;
        int n2 = arr2.length;
        int j=n2-1,i=n1-1;
        int temp;
        while(j>=0){
            if(arr1[i] <= arr2[j]){
                j--;
                continue;
            }
            else{
                temp = arr2[j];
                arr2[j] = arr1[i];
                arr1[i] = temp;
                j--;
                sort(arr1,i);
                
            }
        }
        System.out.println("arr1: ");
        for(int a:arr1){
            System.out.print(a+"\t");
        }
        System.out.println("\narr1: ");
        for(int a:arr2){
            System.out.print(a+"\t");
        }
    }
    
}
