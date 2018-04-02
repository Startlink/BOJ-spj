#include "testlib.h"
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

void judge(int caseNumber)
{
    int n = inf.readInt();

    vector<int> parties(n);
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        parties[i] = inf.readInt();
        total += parties[i];
    }

    auto output = ouf.readLine();
    auto caseStr = "Case #" + to_string(caseNumber) + ": ";

    if (output.substr(0, caseStr.size()) != caseStr)
    {
        quitf(_wa, "not start with case string");
        return;
    }

    int prevSpace = caseStr.size() - 1;

    for (int i = caseStr.size(); i < output.size(); i++)
    {
        if (output[i] == ' ')
        {
            if (i - prevSpace > 1)
            {
                int maximum = *max_element(parties.begin(), parties.end());

                if (maximum * 2 > total)
                {
                    quitf(_wa, "wrong answer");
                    return;
                }
            }

            prevSpace = i;
        }
        else if (output[i] >= 'A' && output[i] < 'A' + n)
        {
            if (i - prevSpace > 2)
            {
                quitf(_wa, "wrong answer");
                return;
            }

            parties[output[i] - 'A']--;
            total--;

            if (parties[output[i] - 'A'] < 0 || total < 0)
            {
                quitf(_wa, "wrong answer");
                return;
            }
        }
        else
        {
            quitf(_wa, "invalid character");
            return;
        }
    }

    if (total != 0)
    {
        quitf(_wa, "wrong answer");
        return;
    }
}

int main(int argc, char* argv[])
{
    swap(argv[2], argv[3]);
    registerTestlibCmd(argc, argv);

    int T = inf.readInt();

    for (int i = 0; i < T; i++)
        judge(i + 1);

    quitf(_ok, "correct");

    return 0;
}