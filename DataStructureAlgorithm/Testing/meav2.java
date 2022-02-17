class A{
    public static void main(String args[]){
        String s1= "jabc";
        String s2 = "ncbajjj";
        int score = 0;
        int[] visited1 = new int[100];
        int[] visited2 = new int[100];
        if(s1.length() == 0 || s2.length()==0){
            score = 0;
        }
        s1 = s1.toLowerCase();
        s2 = s2.toLowerCase();
       
        char temp;
        for(int i=0;i<s1.length();i++){
            temp = s1.charAt(i);
            for(int j=0;j<s2.length();j++){
                if(temp == s2.charAt(j) && visited1[i]!=1 && visited2[j]!=1){
                    if(i==j){
                        score +=2;
                    }
                    else{
                        score++;
                    }
                    visited1[i] = 1;
                    visited2[j] = 1;
                }
            }
        }
        System.out.println(score);
    }
}