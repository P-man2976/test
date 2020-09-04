#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	unsigned int Cr;

	SetMainWindowText("test");

	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ɕύX

	SetGraphMode(1280, 720, 32);//�𑜓x��ݒ�

	if (DxLib_Init() == -1)//DX���C�u���������������A�G���[���N������if����
	{
		return -1;//�G���[���N�����璼���ɏI��
	}

	SetWindowSizeChangeEnableFlag(TRUE);//�T�C�Y�ύX������

	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂɂ���

	SetWindowStyleMode(7);

	char Buf(256);

	ChangeFont("�R�[�|���[�g�E���S�l");//�����̃t�H���g��ύX

	SetFontSize(100);//�t�H���g�T�C�Y�̐ݒ�

	Cr = GetColor(255, 255, 255);//���F�̒l���擾

	DrawPixel(320, 240, GetColor(255, 255, 255));//�_��ł�

	DrawString(0, 0, "Esc�L�[�ŏI��", Cr);//�����̕`��

	DrawString(0, 100, "Enter�L�[�Ŏ��֐i��", Cr);

	ScreenFlip();//����ʂ̕`�挋�ʂ�\��ʂ֕\��

	while (1)
	{
		

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enter�L�[�̓��͏�Ԃ��m�F
		{
			ClearDrawScreen();//�`�悵�Ă������̂�����

			ScreenFlip();//�\��ʂ֕\��

			WaitKey();

			break;
		}
		else
		{

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)//Esc�L�[�̓��͏�Ԃ��m�F
			{
				DxLib_End();

				return 0;
			}
		}
		if (ProcessMessage() == -1)//Windows�̃��b�Z�[�W�������i����I�ɂ���K�v������j
		{
			break;
		}
	}



	

	DxLib_End();//DX���C�u�����I������

	return 0;//�E�B���h�E�����
}