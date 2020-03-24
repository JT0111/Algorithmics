import java.util.ArrayList;

public class SuperBasicQuickUnion{
    private int[] id;

    public QuickUnion(int size){
        id = new int[size];
        for(int i=0; i<size; i++){
            id[i]=i;
        }
    }

    public int getRoot(int p){
        ArrayList<Ineger> visited = new ArrayList<Integer>();
        while(id[p] != p){
            visited.add(p);
            p=id[p];
        }

        for(int i=0; i<visited.size(); i++){
            id[visited.get(i)]=p;
        }
        return p;
    }

    public boolean isConnected(int p, int q){
        return getRoot(p)==getRoot(q);
    }

    public int find(int p){
        return getRoot(p);
    }

    public void union(int p, int q){
        id[getRoot(p)]=q;
    }

}
