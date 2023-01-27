import java.io.PrintWriter;
import java.util.Scanner;

class Main implements Runnable{
    private Scanner in = new Scanner(System.in);
    private PrintWriter out = new PrintWriter(System.out); 
    private int n, a, mx = Integer.MIN_VALUE, mn = Integer.MAX_VALUE;
    public static void main(String[] args){
        new Thread(new Main()).start();
    }
    private void read(){
        n = in.nextInt();
        
    }
    private void solve(){
        for(int i=0;i<n;i++){
            a = in.nextInt();
            mx = Math.max(mx, a);
            mn = Math.min(mn, a);
        }

    }
    private void write() {
        out.println(mn);
        out.println(mx);
    }
    public void run(){
        read();
        solve();
        write();
        out.close();
    }
}