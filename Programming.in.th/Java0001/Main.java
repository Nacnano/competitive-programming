import java.io.PrintWriter;
import java.util.Scanner;

class Main implements Runnable{
    private Scanner in = new Scanner(System.in);
    private PrintWriter out = new PrintWriter(System.out); 
    private int a, b, c, sum;
	private String grade;
    public static void main(String[] args){
        new Thread(new Main()).start();
    }
    private void read(){
        a = in.nextInt();
        b = in.nextInt();
		c = in.nextInt();
    }
    private void solve(){
        sum = a+b+c;
		if(sum>=80) grade= "A";
		else if(sum>=75) grade="B+";
		else if(sum>=70) grade="B";
		else if(sum>=65) grade="C+";
		else if(sum>=60) grade="C";
		else if(sum>=55) grade="D+";
		else if(sum>=50) grade="D";
		else grade="F";

    }
    private void write() {
        out.println(grade);
    }
    public void run(){
        read();
        solve();
        write();
        out.close();
    }
}