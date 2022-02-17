class A {
    A(){System.out.println("A DEFAULT constructor");}
    A(int u){
        System.out.println("A constructor");
    }
    void show(){
        System.out.println("From A");
    }
};
class B extends A{
    B(int x){
        System.out.println("B Constructor");
    }
    void show(){
        System.out.println("From B");
    }
};
class C{
    public static void main(String args[]){
        // A a = new A();
        B b = new B(2);
        // a.show();
        b.show();
    }
};
