
import java.io.*;
import java.util.*;
public class Main {
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		String str = st.nextToken();
		for(int i =0;i<str.length();i++) {
			if(str.charAt(i)>='A'&&str.charAt(i)<='Z') {
				char ch1 = (char) (str.charAt(i)+32);
				System.out.print(ch1);
			}
			else { 
				char ch1 = (char) (str.charAt(i)-32);
				System.out.print(ch1);
		}
		}
		bw.flush();
		bw.close();
	}
	
}
