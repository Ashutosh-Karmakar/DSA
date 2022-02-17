class A{
    public static void main(String args[]){
        int[] arr = {15,10,3};
        int N = arr.length;
        int masks = 1<<N;
        for(int i=0;i<masks;i++){
            for(int j=0;j<N;j++){
                if((i&(1<<j)) != 0){
                    System.out.print(arr[j] + " ");
                }
            }
            System.out.println();
        }

    }
}