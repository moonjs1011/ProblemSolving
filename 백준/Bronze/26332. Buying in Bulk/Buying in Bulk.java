import java.util.*;
import java.io.*;
public class Main {
	public static int calSum(int c,int p) {
		if(c==1)
			return p;
		else {
			return p + (p-2) * (c-1);
		}
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		while(T-- >0) {
			st = new StringTokenizer(br.readLine());
			int c = Integer.parseInt(st.nextToken());
			int p = Integer.parseInt(st.nextToken());
			bw.write(c+" "+p);
			bw.newLine();
			int price = calSum(c,p);
			bw.write(price+"");
			bw.newLine();
	}
		bw.flush();
		bw.close();
	}

}
