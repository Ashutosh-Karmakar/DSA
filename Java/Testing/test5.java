class A{
    int x;
    A a = null;
    A(int y){
        x = y;
        a = null;
    }
}

class B{
    static A head;
    static void insert(int y){
        A newNode = new A(y);
        A temp = head;
        newNode.a = null;
        if(head == null){
            head = newNode;
            return;
        }
       
        while(temp.a != null){
            temp = temp.a;
        }
        temp.a = newNode;
        return;
    }
    public static void main(String args[]){
        
        insert(10);
        insert(20);
        insert(40);
        insert(40);
        
        
        while(head!=null){
            System.out.print(head.x + " ");
            head = head.a;
        }
    }
}