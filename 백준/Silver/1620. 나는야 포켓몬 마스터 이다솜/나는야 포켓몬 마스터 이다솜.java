import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        HashMap<String,Integer> strIntm = new HashMap<>();
        HashMap<Integer,String> intStrm = new HashMap<>();
        for(int i=1;i<=N;i++){
            String name = br.readLine();
            strIntm.put(name,i);
            intStrm.put(i,name);
        }
        while(M>0){
            String input = br.readLine();
            if(input.charAt(0)>='A' && input.charAt(0)<='Z'){
                System.out.println(strIntm.get(input));
            }
            else{
                int num = Integer.parseInt(input);
                System.out.println(intStrm.get(num));
            }
            M--;
        }



    }

}