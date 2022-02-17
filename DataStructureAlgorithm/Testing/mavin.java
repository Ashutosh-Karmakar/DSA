class A{
    public static void main(String args[]){
        int a = 6478434;
        String s1 = Integer.toString(a);
        // int arr[] = new int[s1.length()];
        // for(int i=0;i<s1.length();i++){
        //     arr[i] = s1.charAt(i) - '0';
        // }
        // int max = 0;
        String temp;
        int temp2;
        int max = 0;
        for(int i=0;i<s1.length()-3;i++){
            temp = s1.substring(i,i+3);
            temp2 = Integer.parseInt(temp);
            if(max < temp2){
                max = temp2;
            }
        }
        System.out.println(max);
    }
}