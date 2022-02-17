class test1 {
    public static void main(String args[]){
        String s1 = "ashu";
        System.out.println("s1: "+s1);
        String s2 = "ashu";
        System.out.println( "s2: "+s2);
        System.out.println(s1==s2);
        System.out.println("s2: "+s2);
        System.out.println("charAt: " + s2.indexOf('s'));
        A a = new A();
        System.out.println(a.getClass().getName());
    }
    
}
class A{
    int x;
    A(){x=3;}
    public String toString(){
        return x+"";
    }

};
