#include <iostream>
#include <vector>
#include "Bellman_Ford.h"

int main() {
	std::vector<int> pairs = { 2,4,10,1,2,20 };
	const int size = 5;
	AdjacencyMatrix<size> M(pairs);

	int v = 0;
	for (int i = 0;i < size;++i) {
		for (int j = 0;j < size;++j) {
			if (v = M.get_value(i,j) ) {
				std::cout << i << " " << j << " " << v << "\n";
			}
		}
	}

	long long int A[5];
	bellman_ford_shortest_path(M, 0, A);
	return 0;
}