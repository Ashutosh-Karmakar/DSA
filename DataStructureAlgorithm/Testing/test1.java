public static void sortbykey(HashMap<Integer,Integer> map)
{
    // TreeMap to store values of HashMap
    TreeMap<Integer, Integer> sorted = new TreeMap<>();

    // Copy all data from hashMap into TreeMap
    sorted.putAll(map);

    // Display the TreeMap which is naturally sorted
    for (Map.Entry<Integer, Integer> entry : sorted.entrySet())
        System.out.print(entry.getValue()+" ");       
}
public static void topView(Node root) {
    Queue<A> q = new LinkedList<>();
    HashMap<Integer,Integer> map = new HashMap<>();
    Node temp;
    int cnt;
    q.add(new A(0,root));
    A a = null;
    while(q.size()!=0){
        a = q.remove();
        cnt = a.x;
        temp = a.y;
        if(map.get(cnt) == null){
            map.put(cnt,temp.data);   
        }
        if(temp.left != null){
            q.add(new A(cnt-1,temp.left));
        }
        if(temp.right != null){
            q.add(new A(cnt+1,temp.right));
        }
    }
    sortbykey(map);
    
    
}
