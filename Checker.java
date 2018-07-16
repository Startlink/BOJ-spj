import java.util.*;
import java.io.*;

public class Checker {
    public static void main(String[] args) throws FileNotFoundException {
        Checker c = new Checker();
        c.test(new Scanner(new File(args[0])), new Scanner(new File(args[2])), new Scanner(new File(args[1])));
    }
    public void test(Scanner inf, Scanner ouf, Scanner ans) {
    }
}
