class mergesort {
    static int count = 0;
    void merge(int arr[] , int start , int mid , int end){
        // int n1 = mid;
        // System.out.println(start + " "+ mid + " " + end + "jello");
        int i = start;
        int j = mid+1;
        int[] temp = new int[arr.length];
        int k = start;
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                temp[k] = arr[i];
                i++;
            }
            else{
                temp[k] = arr[j];
                j++;
                count += mid - i + 1;

            }
            k++;
        }
        while(i <= mid){
            temp[k] = arr[i];
            i++;
            k++;
        }
        
        while(j<=end){
            temp[k] = arr[j];
            j++;
            k++;
        }
        for(int l = start;l<=end;l++){
            arr[l] = temp[l];
        }


    }
    void mergeSort(int arr[] , int start , int end){
        // if(start >= end)
        //     System.exit(0);
        if(start<end){
            int mid = (start+end)/2;
            mergeSort(arr,start,mid);
            mergeSort(arr,mid+1,end);
            merge(arr,start,mid,end);
        }
    }
    public static void main(String args[]){
        int arr[] = {7,2,9,10,12,1};
        int N = arr.length;
        // System.out.println(N);
        new mergesort().mergeSort(arr,0,N-1);
        System.out.println("\n");
        for(int i:arr){
            System.out.print(i + "\t");
        }
        System.out.println("\n");
        System.out.println("number of inversions: " + count);
    }
    
}
