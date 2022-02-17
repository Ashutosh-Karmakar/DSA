class Arith{
    int x,y;
    Arith(){
        x = 5;
        y = 8;
    }
    Arith(int p,int q){
        x = p;
        y = q;
    }
    void add(){
        System.out.println(x+y);
    }
    int diff(){
        return x - y;
    }
    class B{
        int r;
        B(int r){
            this.r = r;
        }
        void show(){
            System.out.println(x + " " + y);
        }
    };
};

class Test4 {
    static int x;
    public static void main(String args[]){
        x = 20;
        Arith a1 = new Arith();
        Arith a2 = new Arith(10,5);
        a1.add();
        System.out.println(a2.diff());
        Arith a3;
        a3 = a1;
        a3.add();

        Arith.B a = a2.new B(2);
        a.show();
    }
    
};
