class A{
    int[][] adjmatrix;
    A(int vertex){
        adjmatrix = new int[vertex][vertex];
    }
    void addEdge(int from,int to){
        adjmatrix[from][to] = 1;
    }
    void show(){
        for(int i[]:adjmatrix){
            for(int j:i){
                System.out.print(j + "\t");
            }
            System.out.println();
        }
    }
    
}

class B{
    public static void main(String args[]){
        A a = new A(5);
        a.addEdge(0, 1);
        a.addEdge(1, 2);
        a.addEdge(2, 3);
        a.addEdge(3, 4);

        System.out.println("The matrix is :");
        a.show();

    }
}