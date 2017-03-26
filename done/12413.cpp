#include <cstdio>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, vector<string> > graph;
map<string, vector<string> > reverseGraph;
map<string, int> childs;
map<string, bool> visited;
set<string> candidate;
vector<string> goal;

char line[128];
char sol_line[128];

void findFirst(string goal) {
	visited[goal] = true;

	if (graph.find(goal) == graph.end()) {
		candidate.insert(goal);
		return;
	}

	for (string tech : graph[goal])
		if (!visited[tech])
			findFirst(tech);
}

int main(int agrc, char **argv) {
	FILE *in = fopen(argv[1], "r");
	FILE *sol = fopen(argv[2], "r");
	FILE *out = fopen(argv[3], "r");
	
	fgets(line, sizeof(line), in);
	int testCase = atoi(line);
	for (int test = 1; test <= testCase; test++) {
		graph.clear();
		reverseGraph.clear();
		childs.clear();
		visited.clear();
		candidate.clear();
		goal.clear();

		fgets(sol_line, sizeof(sol_line), sol);
		fgets(line, sizeof(line), out);
		assert(strcmp(sol_line, line) == 0);
		
		strtok(sol_line, ":");
		int countAnswer = atoi(strtok(nullptr, " \n"));
		while (countAnswer--)
			fgets(sol_line, sizeof(sol_line), sol);

		fgets(line, sizeof(line), in);
		for (int i = atoi(line); i > 0; i--) {
			fgets(line, sizeof(line), in);
			string first = strtok(line, ":");
			string second = strtok(nullptr, " \n");

			if (graph.find(first) != graph.end())
				graph[first].push_back(second);
			else {
				graph.insert(pair<string, vector<string> > (first, vector<string>()));
				graph[first].push_back(second);
			}

			if (reverseGraph.find(second) != reverseGraph.end())
				reverseGraph[second].push_back(first);
			else {
				reverseGraph.insert(pair<string, vector<string> > (second, vector<string>()));
				reverseGraph[second].push_back(first);
			}

			childs[first]++;

			if (visited.find(first) == visited.end())
				visited.insert(pair<string, bool> (first, false));
			if (visited.find(second) == visited.end())
				visited.insert(pair<string, bool> (second, false));
		}

		fgets(line, sizeof(line), in);
		for (int i = atoi(line); i > 0; i--) {
			fgets(line, sizeof(line), in);
			string tech = strtok(line, " \n");
			goal.push_back(tech);
		}

		for (int i = 0; i < goal.size(); i++)
			findFirst(goal[i]);

		string answer;
		while (true) {
			if (candidate.size() == 0)
				break;

			assert(fgets(line, sizeof(line), out) != nullptr);
			answer = strtok(line, " \n");

			assert(candidate.find(answer) != candidate.end());

			candidate.erase(answer);
			if (reverseGraph.find(answer) != reverseGraph.end()) {
				for (string tech : reverseGraph[answer]) {
					childs[tech]--;
					if (childs[tech] <= 0 && visited[tech])
						candidate.insert(tech);
				}
			}
		}
	}

	fclose(in);
	fclose(sol);
	fclose(out);
	return 0;
}
