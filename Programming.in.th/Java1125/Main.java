import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;
import java.util.List;

class Main implements Runnable{
    private Scanner in = new Scanner(System.in);
    private PrintWriter out = new PrintWriter(System.out); 
    private int n;
    private Long x, y, ans = 0L;
    private List<Long> ax = new ArrayList<>();
    private List<Long> ay = new ArrayList<>();

    public static void main(String[] args){
        new Thread(new Main()).start();
    }

    private void read(){
        n = in.nextInt();
        for(int i=0; i<n; i++){
            x = in.nextLong();
            y = in.nextLong();
            ax.add(x);
            ay.add(y);
        }
        
    }
    private void solve(){
        Collections.sort(ax);
        Collections.sort(ay);
        for(int i=0;i<n/2;i++){
            ans += (n-1-i-i)*(ax.get(n-1-i)-ax.get(i));
            ans += (n-1-i-i)*(ay.get(n-1-i)-ay.get(i));
        }
    }
    private void write() {
        System.out.println(ans);
    }

    public void run(){
        read();
        solve();
        write();
        out.close();
    }
}