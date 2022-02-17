class A{
    public static void main(String args[]){
        String str = "Ashu tosh karmakar";
        String temp = "";
        String res = "";
        int k = 0;
        System.out.println(str.length());
        // for(int i=0;i < str.length();i++){
        //     System.out.println(str.charAt(i));
        // }

        for(int i=0;i < str.length();i++){
            if(str.charAt(i) == ' '){
                res = temp + " " + res;
                
                
                temp = "";
            }
            else{
                temp = temp+str.charAt(i);
            }
        }
        res = temp + " " +res;
        System.out.println(res);
        
    }
}