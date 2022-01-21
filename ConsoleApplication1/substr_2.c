#include <stdio.h>
#include <string.h>
void sub(const char *s, char *t)
{
	//                       01234567
	const char* const 開始位置 = &s[2];
	const char* const Fの位置 = strchr(開始位置, 'F');

	const size_t 長さ = Fの位置 - 開始位置;
	memcpy(t, 開始位置, 長さ);
	t[長さ] = '\0';
}
int main()
{
	static const char s[] = "ABCDEFGHIJKL";
	char t[sizeof s];
	sub(s, t);
	puts(t);
	//                         ---
}
