/*
 *   0   1   2   3   4   5   6   7   8   9
 *  10  11  12  13  14  15  16  17  18  19
 *  20  21  22  23  24  25  26  27  28  29
 * ...
 *  90  91  92  93  94  95  96  97  98  99
 * 100 101 102 103 104 105 106 107 108 109
 * 110 111 112 113 114 115 116 117 118 119
 * ...
 * 190 191 192 193 194 195 196 197 198 199
 * 200 201 202 203 204 205 206 207 208 209
 *
 */

#include <stdio.h>

int main(void) {
	int cnt = 2;
	printf("    ");
	for (int i = 1; i < 143; i++) {
		
		printf("%3d ", i);
		if (cnt % 10 == 0){
			puts("");
			cnt = 0;
		}
		cnt++;
	}
	return 0;
}