//
// Created by sworddestiny on 18-5-22.
//

#ifndef ALGORITHMS_BINATY_COLOR_GRAPH_H

bool dfs(int v, int n, int **G, int *colors, int c) {
	colors[v] = c;
	for (int i = 0; i < n; ++i) {
		if (G[v][i] == 1 || G[i][v] == 1) {
			if (colors[i] == c) {
				return false;
			} else if (colors[i] == 0) {
				if (!dfs(i, n, G, colors, -c)) {
					return false;
				}
			} else { ;
			}
		}
	}
	return true;
}

/**
 * 二分图判定
 * @param G 图
 * @param n 顶点数量
 * @param colors 最后的涂色情况
 * @return 是否二分图(可以仅用两种颜色染色的图)
 */
bool binary_color_graph(int **G, int n, int *colors) {
	for (int i = 0; i < n; ++i) {
		if (colors[i] == 0) {
			if (!dfs(i, n, G, colors, 1)) {
				return false;
			}
		}
	}

	return true;
}

#define ALGORITHMS_BINATY_COLOR_GRAPH_H

#endif //ALGORITHMS_BINATY_COLOR_GRAPH_H
