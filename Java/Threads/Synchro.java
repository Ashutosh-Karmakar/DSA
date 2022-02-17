class Synchro {
    static int gcd(int a ,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    public static void main(String args[]){
        System.out.println(gcd(4,2));
        int i,j;
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                if(j<=i){
                    System.out.print(" ");
                }
                else{
                    System.out.print("*");
                    break;
                }
            }
            System.out.println();
        }

        String c = "i am ashutosh karmakar";
        char[] str = c.toCharArray();
        System.out.println(str.length);

        for(i=0;i<str.length;i++){
            if(str[i] == 'i' || str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u'){
                str[i] = Character.toUpperCase(str[i]);     
            }
        }
        System.out.println(str);

        String str2 = "hi This is ashu";
        String rev="";
        String word[] = str2.split(" ");
        for(String w:word){
            StringBuilder s = new StringBuilder(w);
            s.reverse();
            rev =rev+ s;
            rev = rev + " ";
        }
        System.out.println(rev);
        i = 0;
        System.out.println(i);
        String si = "sm";
        String sii = "rm";
        System.out.println(si.charAt(0) > sii.charAt(0));


    }
    
}
