interface A{
    int p = 20;
    void add();
}

class C implements A{
    int x,y;
    C(){x = 3;y=2;}
    public void add(){
        System.out.println(x+y+A.p);
    }
}


class D{
    public static void main(String args[]){
        C c1 = new C();
        c1.add();
    }
}