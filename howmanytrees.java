import java.util.* ;
import java.io.* ;
import java.math.* ;

class Main
{
	BigDecimal fact[] = new BigDecimal[2001] ;
	BigDecimal result[] = new BigDecimal[1001] ;
	public void precalc_function()
	{
		fact[0] = new BigDecimal(1) ;
		fact[1] = new BigDecimal(1) ;
		for(int i=2;i<2001;i++)
		{
			fact[i] = fact[i-1].multiply(new BigDecimal(i)) ;
		}
	}
	public void precal()
	{
		precalc_function() ;
		result[1] = new BigDecimal(1) ;
		for(int i=2;i<1001;i++)
		{
			result[i] = result[i-1].multiply(new BigDecimal((2*(i-1)+2)*(2*(i-1)+1))).divide(new BigDecimal(((i-1)+1)*((i-1)+2))) ;
		}
	}
	public void solve()
	{
		precal() ;
		//Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in))) ;
		Scanner in = new Scanner(System.in) ;
		while(in.hasNextInt())
		{
			int n = in.nextInt() ;
			System.out.println(result[n]) ;
		}
	}
	public static void main(String args[])
	{
		Main problem = new Main() ;
		problem.solve() ;
		//solve() ;

	}

}