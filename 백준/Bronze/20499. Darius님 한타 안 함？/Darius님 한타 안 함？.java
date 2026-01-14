
import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		String str = st.nextToken();
		String [] arr =str.split("/");
		int K = Integer.parseInt(arr[0]);
		int D = Integer.parseInt(arr[1]);
		int A = Integer.parseInt(arr[2]);
		if(K+A<D || D==0) {
			bw.write("hasu");
		}
		else bw.write("gosu");
		
		bw.flush();
		bw.close();
			
			
		
	}

}
