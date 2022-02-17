class A extends Thread{
    public void run(){
        int x=0;
        while(x<100){
            System.out.println(getName()+": " +x++);
        }
    }
}
class thread1{
    public static void main(String args[]) throws Exception{
        int x=0;
        System.out.println("begin of main");
        A a = new A();
        A a2 = new A();
        // a.setPriority(Thread.MIN_PRIORITY);
        a2.setPriority(Thread.MAX_PRIORITY);
        a.start();
        a2.start();
        // a.join();
        System.out.println(a.isAlive() + " a1");
        System.out.println(a2.isAlive() + " a2");
        // while(x<200){
        //     System.out.println("\t"+x++);
        // }
        System.out.println("End of main");
    }
    
}
