#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* sub(const char *s)
{
	//                       01234567
	const char* const 開始位置 = &s[2];
	const char* const Fの位置 = strchr(開始位置, 'F');

	const size_t 長さ = Fの位置 - 開始位置;

	//C言語の場合は (char*)malloc としなくて良い
	char* const t = malloc(長さ + 1);
	if (t) {
		//メモリ割り付け成功
		memcpy(t, 開始位置, 長さ);
		t[長さ] = '\0';
		return t;
	}
	else {
		//メモリ割り付け失敗
		return NULL;
	}
}
int main()
{
	static const char s[] = "ABCDEFGHIJKL";
	char* const t = sub(s);
	if (t) {
		puts(t);
		free(t);//メモリ領域の解放
	}
}
