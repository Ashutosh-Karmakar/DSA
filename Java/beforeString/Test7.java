abstract class A{
    int x,y;
    A(){x=20; y=30;}
    abstract void show();
    
    void add(){
        System.out.println(x + y);
    }
};
// interface C{
//     int z = 20;
//     void show();
// }

// class D implements C{
//     public void show(){
//         System.out.println(z);
//     }
// }

class B extends A{
    void show(){
        System.out.println(x + " " + y);
    }
};

class Test7 {
    public static void main(String args[]){  
        B b = new B();
        A a = new B();
        a.show();
        // D d = new D();
        b.show();
        b.add();      
        // d.show();
    }
  
    
}
