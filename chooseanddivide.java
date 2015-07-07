import java.util.* ;
import java.io.* ;
import java.math.* ;


class Main
{
	BigDecimal fact[] = new BigDecimal[10001] ;
	public void solve()
	{
	  fact[0] = new BigDecimal(1) ;
	  fact[1] = new BigDecimal(1) ;
	  for(int i=2;i<10001;i++)
	  {
	  	fact[i] = fact[i-1].multiply(new BigDecimal(i)) ;
	  }
	}
    public void answ()
    {
    	Scanner in = new Scanner(System.in) ;
		while(in.hasNext())
		{
		  int p = in.nextInt() ;
		  int q = in.nextInt() ;
		  int r = in.nextInt() ;
		  int s = in.nextInt() ;
		  BigDecimal ans = BigDecimal.ONE ;
		  ans = ans.multiply(fact[p]);
          ans = ans.divide(fact[q], 1000, BigDecimal.ROUND_HALF_UP);
          ans = ans.multiply(fact[s]);
          ans = ans.divide(fact[p - q], 1000, BigDecimal.ROUND_HALF_UP);
          ans = ans.multiply(fact[r - s]);
          ans = ans.divide(fact[r], 1000, BigDecimal.ROUND_HALF_UP);
          System.out.println(ans.setScale(5, BigDecimal.ROUND_HALF_UP));
		}
    }
	public static void main(String args[])
	{
		Main problem = new Main() ;
		problem.solve() ;
		problem.answ() ;
	}
}