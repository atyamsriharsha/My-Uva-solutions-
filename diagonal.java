import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main 
{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer("");
        int i=1;
        while (true) {
            long x = Long.parseLong(br.readLine());
            if(x==0)
                break;
            sb.append("Case ").append(i).append(": ");
            sb.append((int)Math.ceil((3+Math.sqrt(9+8*x))/2.0)).append("\n");
            i++;
        }
        System.out.print(sb);
    }
}