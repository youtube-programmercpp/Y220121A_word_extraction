#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* sub(const char *s)
{
	//                       01234567
	const char* const �J�n�ʒu = &s[2];
	const char* const F�̈ʒu = strchr(�J�n�ʒu, 'F');

	const size_t ���� = F�̈ʒu - �J�n�ʒu;

	//C����̏ꍇ�� (char*)malloc �Ƃ��Ȃ��ėǂ�
	char* const t = malloc(���� + 1);
	if (t) {
		//����������t������
		memcpy(t, �J�n�ʒu, ����);
		t[����] = '\0';
		return t;
	}
	else {
		//����������t�����s
		return NULL;
	}
}
int main()
{
	static const char s[] = "ABCDEFGHIJKL";
	char* const t = sub(s);
	if (t) {
		puts(t);
		free(t);//�������̈�̉��
	}
}
