#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct substring {
	const char* 単語の先頭;
	size_t 単語の長さ;
};
const char* 次の位置を得る(const struct substring* p)
{
	return p->単語の先頭 + p->単語の長さ;
}
char* 部分文字列を取得する(const struct substring* p)
{
	char* const t = malloc(p->単語の長さ + 1);
	if (t) {
		memcpy(t, p->単語の先頭, p->単語の長さ);
		t[p->単語の長さ] = '\0';
		return t;
	}
	else
		return NULL;
}
struct substring sub(const char* p)
{
	static const char delim[] = " ,.";
	//区切り文字だけで構成される部分の長さを得る
	const size_t 先行する区切り文字群の長さ = strspn(p, delim);

	const char* const 単語の先頭 = &p[先行する区切り文字群の長さ];
	struct substring 戻り値 =
	{ 単語の先頭
	, strcspn(単語の先頭, delim)//区切り文字ではない文字だけで構成される部分の長さを得る
	};
	return 戻り値;
}
int main()
{
	//“文字列の中から3文字以上の単語だけを抜き出して出力する”
	//“ここでいう単語はスペースやカンマやピリオドに挟まれたもの”
	static const char s[] = " ,.     Yes, we can.";
	for (const char* p = s;;) {
		const struct substring result = sub(p);
		if (result.単語の長さ >= 3/*3文字以上*/) {
			char* const t = 部分文字列を取得する(&result);
			puts(t);
			free(t);
		}
		if (result.単語の長さ == 0)
			break;
		else
			p = 次の位置を得る(&result);
	}
}

/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q10255774785
1150386060さん

2022/1/21 16:21

4回答

c言語について質問です。
文字列の中から3文字以上の単語だけを抜き出して出力するにはどのようにすればよいでしょうか。ここでいう単語はスペースやカンマやピリオドに挟まれたものをさします。
例えば"Yes, we can." という文字列であれば、Yesとcanを出力するプログラムです。
よろしくお願いします。

C言語関連 | プログラミング・31閲覧
*/
