class A{
    static void show(){
        System.out.println("Inside A");
    }
    private void hello(){
        System.out.println("hello in A");
    }
}
class B extends A{
    void show2(){
        System.out.println("Inside B");
        hello();
    }
    private void hello(){
        System.out.println("hello in B  ");
    }
}
class C extends B{
    static void show(){
        System.out.println("Inside C");
    }
}

class Test8 {
    public static void main(String args[]){
        // A a = new A();
        // B b = new B();
        // C c = new C();

        // a.show();
        // b.show();
        // c.show();

        // A a = new C();
        // a.show();
        B b = new B();
        b.show2 ();
    }
}
