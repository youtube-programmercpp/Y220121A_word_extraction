#include <stdio.h>
#include <string.h>
int main()
{
	//�g������̒�����3�����ȏ�̒P�ꂾ���𔲂��o���ďo�͂���h
	static const char s[] = " ,.     Yes, we can.";
	//�g�����ł����P��̓X�y�[�X��J���}��s���I�h�ɋ��܂ꂽ���́h
	static const char delim[] = " ,.";

	const char* p = s;

	for (;;) {
		//��؂蕶�������ō\������镔���̒����𓾂�
		const size_t ��s�����؂蕶���Q�̒��� = strspn(p, delim);

		const char* const �P��̐擪 = &p[��s�����؂蕶���Q�̒���];
		//��؂蕶���ł͂Ȃ����������ō\������镔���̒����𓾂�
		const size_t �P��̒��� = strcspn(�P��̐擪, delim);
		if (�P��̒��� == 0)
			break;
		else {

			if (�P��̒��� >= 3/*3�����ȏ�*/) {
				fwrite(�P��̐擪, �P��̒���, 1, stdout);
				putchar('\n');
			}

			p = &�P��̐擪[�P��̒���];
		}
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
