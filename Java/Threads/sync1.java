class Que{
    static int cnt = 72;
    synchronized void booking(String na){
        System.out.println("String : " + na + " is going on.");
        int x = 0;
        while(x<100){
            x = x+2;
            x = x-1;
            System.out.println("Ticket on :"+na + " is " + cnt--);

        }
    }
};

class Person extends Thread{
    String na;
    Que ob;
    Person(String na,Que ob){
        this.na = na;
        this.ob = ob;
    }
    public void run(){
        ob.booking(na);
    }
}



class sync1 {
    public static void main(String args[]){
        Que q1 = new Que();
        Person p1 = new Person("ashu",q1);
        Person p2 = new Person("tosh",new Que());
        p1.start();
        p2.start();
    }
    

    
}
