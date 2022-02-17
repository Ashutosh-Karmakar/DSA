class Test3 {
    static void test(int arr[]){
        arr[0] = 10;
    }
    public static void main(String args[]){
        int arr[] = {19,20,40};
        test(arr);
        for(int i:arr){
            System.out.print(i + "\t");
        }

    
        int a[][] = new int[3][5];
        for(int i=0;i<3;i++){
            for(int j=0;j<5;j++){
                a[i][j] = 3;
            }
        }

        System.out.println();
        for(int k[]:a){
            for(int z:k){
                System.out.print(z + "\t");
            }
            System.out.println();
        }

        
    }
    
};
