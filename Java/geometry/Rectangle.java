package geometry;

public class Rectangle implements shape {
    int len,breath;
    Rectangle(){
        len = 2;
        breath = 4;
    }
    public void area(){
        System.out.println("Area"+ " : " + len*breath);
    }
}
