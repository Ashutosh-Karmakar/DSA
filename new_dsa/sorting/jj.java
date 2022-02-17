class sec{
    public static void main(String args[]){
        int arr[] = {29,29,1,3,11,2,5,5};
        int max1 = Integer.MIN_VALUE;
        int max2 = Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++){
            if(arr[i] > max1){
                max2 = max1;
                max1 = arr[i];
            }
            else if(arr[i] > max2 ){
                max2 =arr[i];
            }
        }
        System.out.println(max1 + " " + max2);
    }
}