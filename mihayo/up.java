import java.math.BigDecimal;  
import java.util.Scanner;  
  
public class Main {  
    static BigDecimal p = BigDecimal.ZERO;  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        p = sc.nextBigDecimal();  
        System.out.println(  
                recursion(BigDecimal.ONE, BigDecimal.ONE)  
                        .multiply(BigDecimal.valueOf(1.5))  
                        .setScale(7, BigDecimal.ROUND_HALF_UP)  
        );  
    }  
  
    public static BigDecimal recursion(BigDecimal time, BigDecimal np) {  
        if (time.equals(BigDecimal.valueOf(90))) return np.multiply(BigDecimal.valueOf(90));  
        BigDecimal newNp = np.multiply(BigDecimal.ONE.subtract(p));  
        return recursion(time.add(BigDecimal.ONE), newNp).add(time.multiply(p).multiply(np));  
    }  
}
