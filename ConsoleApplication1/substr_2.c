#include <stdio.h>
#include <string.h>
void sub(const char *s, char *t)
{
	//                       01234567
	const char* const �J�n�ʒu = &s[2];
	const char* const F�̈ʒu = strchr(�J�n�ʒu, 'F');

	const size_t ���� = F�̈ʒu - �J�n�ʒu;
	memcpy(t, �J�n�ʒu, ����);
	t[����] = '\0';
}
int main()
{
	static const char s[] = "ABCDEFGHIJKL";
	char t[sizeof s];
	sub(s, t);
	puts(t);
	//                         ---
}
