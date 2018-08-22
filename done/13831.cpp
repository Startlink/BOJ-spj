#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);

	while (true) {
		string X = inf.readLine();
		if (X == "*") break;
		string Y = inf.readLine();
		string C = inf.readLine();

		string pans = ouf.readLine();
		string jans = ans.readLine();

		if (jans.length() != pans.length()) quit(_wa, "");
		if (jans == "Impossible") {
			if (pans == "Impossible") continue;
			quit(_wa, "");
		}
		if (pans == "Impossible") quit(_wa, "");
		if (pans.find(C) == string::npos) quit(_wa, "");

		unsigned i;

		i = 0;
		for (char c : X) if (c == pans[i]) {
			i++;
			if (i == pans.size()) break;
		}
		if (i != pans.size()) quit(_wa, "");

		i = 0;
		for (char c : Y) if (c == pans[i]) {
			i++;
			if (i == pans.size()) break;
		}
		if (i != pans.size()) quit(_wa, "");
	}

	quit(_ok, "");
}
