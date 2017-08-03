#include <cstdio>
#include <cassert>
using namespace std;

int in_num_card[14];
int out_num_card[14];

char sol_buffer[9999];
char out_buffer[9999];

int main(int agrc, char **argv){
	FILE *in = fopen(argv[1],"r");
	FILE *sol = fopen(argv[2],"r");
	FILE *out = fopen(argv[3],"r");

	while (1)
	{
		int out_sum = 0;

		// Initialize
		for (int i = 0; i < 14; i++)
			in_num_card[i] = out_num_card[i] = 0;

		int in_N;
		fscanf (in, "%d", &in_N);

		if (in_N == 0) break;

		for (int i = 0; i < in_N; i++)
		{
			int b;
			fscanf (in, "%d", &b);
			in_num_card[b]++;
		}

		fgets (sol_buffer, 9999, sol);

		if (sol_buffer[0] == 'N' && sol_buffer[1] == 'o')
		{
			fgets (out_buffer, 9999, out);

			// if sol is 'No', out must be 'No'
			assert (out_buffer[0] == 'N' && out_buffer[1] == 'o' && (out_buffer[2] == 0 || out_buffer[2] == '\n'));
		}
		else
		{
			for (int i = 0; i < in_N; i++)
			{
				int b;
				assert (fscanf (out, "%d", &b) == 1);
				assert (b >= 1 && b <= 13);
				out_num_card[b]++;

				assert (out_sum % b == 0);
				out_sum += b;
			}

			for (int i = 1; i <= 13; i++)
				assert (in_num_card[i] == out_num_card[i]);

			// Remove remained line (+ '\n')
			fgets (out_buffer, 9999, out);

			// Remained buffer is consist of ' ' and '\n'
			for (int i = 0; out_buffer[i]; i++)
				assert (out_buffer[i] == ' ' || out_buffer[i] == '\n');
		}
	}

	// Remained output
	while (fgets (out_buffer, 9999, out))
	{
		for (int i = 0; out_buffer[i]; i++)
			assert (out_buffer[i] == ' ' || out_buffer[i] == '\n');
	}

	return 0;
}