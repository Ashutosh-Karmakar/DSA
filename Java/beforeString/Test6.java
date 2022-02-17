class A {
    private int x,y;
    A(){
        x = 2;
        y = 3;
    }
    void show(){
        System.out.println(x+ " " +y);
    }
};

class B extends A{

};

class C{
    public static void main(String args[]){
        B b = new B();
        b.show();
        System.out.println(b.x +" "+ b.y);
    }
};

