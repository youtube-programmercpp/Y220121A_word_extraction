#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct substring {
	const char* �P��̐擪;
	size_t �P��̒���;
};
const char* ���̈ʒu�𓾂�(const struct substring* p)
{
	return p->�P��̐擪 + p->�P��̒���;
}
char* ������������擾����(const struct substring* p)
{
	char* const t = malloc(p->�P��̒��� + 1);
	if (t) {
		memcpy(t, p->�P��̐擪, p->�P��̒���);
		t[p->�P��̒���] = '\0';
		return t;
	}
	else
		return NULL;
}
struct substring sub(const char* p)
{
	static const char delim[] = " ,.";
	//��؂蕶�������ō\������镔���̒����𓾂�
	const size_t ��s�����؂蕶���Q�̒��� = strspn(p, delim);

	const char* const �P��̐擪 = &p[��s�����؂蕶���Q�̒���];
	struct substring �߂�l =
	{ �P��̐擪
	, strcspn(�P��̐擪, delim)//��؂蕶���ł͂Ȃ����������ō\������镔���̒����𓾂�
	};
	return �߂�l;
}
int main()
{
	//�g������̒�����3�����ȏ�̒P�ꂾ���𔲂��o���ďo�͂���h
	//�g�����ł����P��̓X�y�[�X��J���}��s���I�h�ɋ��܂ꂽ���́h
	static const char s[] = " ,.     Yes, we can.";
	for (const char* p = s;;) {
		const struct substring result = sub(p);
		if (result.�P��̒��� >= 3/*3�����ȏ�*/) {
			char* const t = ������������擾����(&result);
			puts(t);
			free(t);
		}
		if (result.�P��̒��� == 0)
			break;
		else
			p = ���̈ʒu�𓾂�(&result);
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
