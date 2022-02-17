class A implements Runnable{
    public void run(){
        int x = 0;
        Thread t = Thread.currentThread();
        while(x<300){
            System.out.println(t.getName()+": "+x++);
        }
    }
}
class runablethred {
    public static void main(String args[]){
        System.out.println("Start......");
        A a = new A();
        Thread t1 = new Thread(a,"tosh");
        t1.start();
        Runnable r1 = new A();
        Thread t2 = new Thread(r1,
        "ashu");
        t2.start();
        System.out.println("End.......");
    }
    
}
