#include <stdio.h>
#include <string.h>
int main()
{
	//                         ---
	static const char s[] = "ABCDEFGHIJKL";
	//                       01234567
	const char* const �J�n�ʒu = &s[2];
	const char* const F�̈ʒu = strchr(�J�n�ʒu, 'F');

	const size_t ���� = F�̈ʒu - �J�n�ʒu;
	char t[sizeof s];
	memcpy(t, �J�n�ʒu, ����);
	t[����] = '\0';
	puts(t);
}
