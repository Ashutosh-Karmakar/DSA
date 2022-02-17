class A{
    int test() throws Exception{
        Exception e = new Exception();
        throw e;
        return 0;

    }
};




class excep3 {
    public static void main(String args[]){
        try{
            new A().test();
        }
        catch(Exception e){
            System.out.println(e);
        }
        finally{
            System.out.println("in finally");
        }
    }
}
