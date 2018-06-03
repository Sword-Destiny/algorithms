//
// Created by sworddestiny on 17-12-23.
//

#ifndef ALGORITHMS_EXPEDITION_H
#define ALGORITHMS_EXPEDITION_H

#include <queue>

using std::priority_queue;

//加油站
typedef struct stop {
	int location;//位置
	int gas;//可加的油量
} expedition_stop;

//为priority_queue重载小于运算
bool operator<(const expedition_stop &e1, const expedition_stop &e2) {
	return e1.gas < e2.gas;
}

/**
 * 计算汽车需要加油的时间
 * @param stops: 加油站,空间加1
 * @param np1: 加油站数量+1
 * @param L: 总路程
 * @param init_tank: 初始油量
 * @return 中途需要加油的次数
 */
int expedition(expedition_stop *stops, int np1, int L, int init_tank) {
	int answer_times = 0;
	int current_position = 0;
	int current_tank = init_tank;
	stops[np1 - 1].location = L;
	stops[np1 - 1].gas = 0;
	priority_queue<expedition_stop> queue;
	for (int i = 0; i < np1; i++) {
		int distance = stops[i].location - current_position;
		while (current_tank - distance < 0) {
			if (queue.empty()) {
				return -1;
			}
			current_tank += queue.top().gas;
			queue.pop();
			answer_times++;
		}
		current_position = stops[i].location;
		current_tank -= distance;
		queue.push(stops[i]);
	}
	return answer_times;
}


#endif //ALGORITHMS_EXPEDITION_H
