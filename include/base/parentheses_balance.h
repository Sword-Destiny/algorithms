//
// Created by sworddestiny on 18-5-16.
//

#ifndef ALGORITHMS_PARENTHESES_BALANCE_H

/**
 * 判断s中的[和]是否成对出现
 * @param s 字符串
 * @param len 字符串长度
 * @return answer
 */
bool parentheses_balance(const char *s, int len) {
	int left_count = 0;
	for (int i = 0; i < len; ++i) {
		switch (s[i]) {
			case '[':
				left_count++;
				break;
			case ']':
				left_count--;
				break;
			default:
				break;
		}
		if (left_count < 0) {
			return false;
		}
	}
	return left_count == 0;
}

#define ALGORITHMS_PARENTHESES_BALANCE_H

#endif //ALGORITHMS_PARENTHESES_BALANCE_H
