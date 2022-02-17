class A{
    static void merge(int arr[],int start,int end,int mid){
        int l = start;
        int j = mid+1;
        int[] a1 = new int[end-start+1];
        // int[] a2 = new int[end-mid];
        int k = 0;
        while(l<=mid && j<=end){
            if(arr[l] > arr[j]){
                a1[k++] = arr[j++];
            }
            else{
                a1[k++] = arr[l++];
            }
        }
        while(l<=mid){
            a1[k++] = arr[l++];
        }
        while(j<=end){
            a1[k++] = arr[j++];
        }
        k = 0;
        for(int i=start;i<=end;i++){
            arr[i] = a1[k++];
        }
    }
    static void mergeSort(int arr[],int start,int end){
        if(start < end){
            int mid = (start + end)/2;
            mergeSort(arr,start,mid);
            mergeSort(arr, mid+1,end);
            merge(arr,start,end,mid);
        }
    }
    public static void main(String args[]){
        int arr[] = {4,3,1,6,7,2,0};
        int n = arr.length;
        mergeSort(arr,0,n-1);

        for(int i:arr){
            System.out.print(i + " ");
        }

    }
}