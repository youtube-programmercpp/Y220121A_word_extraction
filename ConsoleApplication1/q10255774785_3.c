#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* sub(const char** pp)
{
	const char* p = *pp;

	static const char delim[] = " ,.";
	//��؂蕶�������ō\������镔���̒����𓾂�
	const size_t ��s�����؂蕶���Q�̒��� = strspn(p, delim);

	const char* const �P��̐擪 = &p[��s�����؂蕶���Q�̒���];
	//��؂蕶���ł͂Ȃ����������ō\������镔���̒����𓾂�
	const size_t �P��̒��� = strcspn(�P��̐擪, delim);

	char* const t = malloc(�P��̒��� + 1);
	if (t) {
		memcpy(t, �P��̐擪, �P��̒���);
		t[�P��̒���] = '\0';

		*pp = &�P��̐擪[�P��̒���];//���̈ʒu���|�C���^�o�R�ŕԂ�

		return t;
	}
	else
		return NULL;
}
int main()
{
	//�g������̒�����3�����ȏ�̒P�ꂾ���𔲂��o���ďo�͂���h
	//�g�����ł����P��̓X�y�[�X��J���}��s���I�h�ɋ��܂ꂽ���́h
	static const char s[] = " ,.     Yes, we can.";

	const char* p = s;
	for (;;) {
		char* const t = sub(&p);
		if (t) {
			const size_t �P��̒��� = strlen(t);
			if (�P��̒��� >= 3/*3�����ȏ�*/)
				puts(t);
			free(t);
			if (�P��̒��� == 0)
				break;
		}
		else
			break;
	}
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q10255774785
1150386060����

2022/1/21 16:21

4��

c����ɂ��Ď���ł��B
������̒�����3�����ȏ�̒P�ꂾ���𔲂��o���ďo�͂���ɂ͂ǂ̂悤�ɂ���΂悢�ł��傤���B�����ł����P��̓X�y�[�X��J���}��s���I�h�ɋ��܂ꂽ���̂������܂��B
�Ⴆ��"Yes, we can." �Ƃ���������ł���΁AYes��can���o�͂���v���O�����ł��B
��낵�����肢���܂��B

C����֘A | �v���O���~���O�E31�{��
*/
