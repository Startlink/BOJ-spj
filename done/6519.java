import java.util.*;
import java.io.*;

public class Checker {

	private static boolean[][] map;
	private static int startY, startX, endY, endX;

	public void test(Scanner inf, Scanner ouf, Scanner ans) {
		while (true) {
			int cx = inf.nextInt();
			int cy = inf.nextInt();
			if (cx == 0 && cy == 0)
				break;

			startX = cx * 2 - 1;
			startY = cy * 2 - 1;
			endX = inf.nextInt() * 2 - 1;
			endY = inf.nextInt() * 2 - 1;

			map = new boolean[13][13];
			for (int i = 0; i < 3; i++) {
				int sx = inf.nextInt() * 2;
				int sy = inf.nextInt() * 2;
				int ex = inf.nextInt() * 2;
				int ey = inf.nextInt() * 2;

				if (sy == ey) {
					for (int x = sx; x <= ex; x++)
						map[sy][x] = true;
				} else {
					for (int y = sy; y <= ey; y++)
						map[y][sx] = true;
				}
			}

			String answer = ans.nextLine();
			assert (ouf.hasNextLine());
			String userAnswer = ouf.nextLine();

			assert (answer.length() == userAnswer.length());
			checkUserAnswer(userAnswer);
		}

		assert (!ouf.hasNextLine());
	}

	private static void checkUserAnswer(String userAnswer) {
		char[] path = userAnswer.toCharArray();
		int y = startY;
		int x = startX;

		for (int i = 0; i < path.length; i++) {
			assert (path[i] == 'N' || path[i] == 'E' || path[i] == 'S' || path[i] == 'W');

			switch (path[i]) {
			case 'N':
				y--;
				assert (y < 13 && y >= 0 && !map[y][x]);
				y--;
				assert (y < 13 && y >= 0 && !map[y][x]);
				break;
			case 'E':
				x++;
				assert (x < 13 && x >= 0 && !map[y][x]);
				x++;
				assert (x < 13 && x >= 0 && !map[y][x]);
				break;
			case 'S':
				y++;
				assert (y < 13 && y >= 0 && !map[y][x]);
				y++;
				assert (y < 13 && y >= 0 && !map[y][x]);
				break;
			case 'W':
				x--;
				assert (x < 13 && x >= 0 && !map[y][x]);
				x--;
				assert (x < 13 && x >= 0 && !map[y][x]);
				break;
			}
		}

		assert (y == endY && x == endX);
	}

	public static void main(String[] args) throws FileNotFoundException {
		Checker c = new Checker();
		c.test(new Scanner(new File(args[0])), new Scanner(new File(args[2])), new Scanner(new File(args[1])));
	}
}