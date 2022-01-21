#include <stdio.h>
#include <string.h>
int main()
{
	//                         ---
	static const char s[] = "ABCDEFGHIJKL";
	//                       01234567
	const char* const 開始位置 = &s[2];
	const char* const Fの位置 = strchr(開始位置, 'F');

	const size_t 長さ = Fの位置 - 開始位置;
	char t[sizeof s];
	memcpy(t, 開始位置, 長さ);
	t[長さ] = '\0';
	puts(t);
}
