
import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		double weight = Double.parseDouble(st.nextToken());
		st = new StringTokenizer(br.readLine());
		double height = Double.parseDouble(st.nextToken());
		
		double bmi = weight/(height*height);
		
		if(bmi >25) bw.write("Overweight");
		else if(bmi>18.5) bw.write("Normal weight");
		else bw.write("Underweight");
		
		bw.flush();
		bw.close();
	}

}
