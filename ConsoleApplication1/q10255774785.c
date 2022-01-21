#include <stdio.h>
#include <string.h>
int main()
{
	//“文字列の中から3文字以上の単語だけを抜き出して出力する”
	static const char s[] = " ,.     Yes, we can.";
	//“ここでいう単語はスペースやカンマやピリオドに挟まれたもの”
	static const char delim[] = " ,.";

	const char* p = s;

	for (;;) {
		//区切り文字だけで構成される部分の長さを得る
		const size_t 先行する区切り文字群の長さ = strspn(p, delim);

		const char* const 単語の先頭 = &p[先行する区切り文字群の長さ];
		//区切り文字ではない文字だけで構成される部分の長さを得る
		const size_t 単語の長さ = strcspn(単語の先頭, delim);
		if (単語の長さ == 0)
			break;
		else {

			if (単語の長さ >= 3/*3文字以上*/) {
				fwrite(単語の先頭, 単語の長さ, 1, stdout);
				putchar('\n');
			}

			p = &単語の先頭[単語の長さ];
		}
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
