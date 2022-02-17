class MyEcept extends Exception{
    String res;
    String cn;
    String mn;
    int nn;
    MyEcept(String r,String c,String m,int n){
        res = r;
        cn = c;
        mn = m;
        nn = n;
    }
    public String toString(){
        return "exception in: " + cn + " / " + mn + ", due to : " + res + " in line: " + nn;
    }
}
class excep1 {
    static void test(int p)throws MyEcept{
        if(p>1000){
            MyEcept ob = new MyEcept("more than 1000","excep1","test()",3);
            throw ob;
        }
        else{
            System.out.println("val: "+p);
        }
    }
    public static void main(String args[]){
        try{
            test(200);
            test(2000);
            

        }
        catch(Exception e){
            System.out.println(e);
        }
    }
} 
