#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	unsigned int Cr;

	SetMainWindowText("test");

	ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ɕύX

	//SetGraphMode(1920, 1080, 32);

	if (DxLib_Init() == -1)//DX���C�u��������������
	{
		return -1;//�G���[���N�����璼���ɏI��
	}

	SetWindowSizeChangeEnableFlag(TRUE);

	SetWindowStyleMode(7);

	ChangeFont("�R�[�|���[�g�E���S�l");//�����̃t�H���g��ύX

	Cr = GetColor(255, 255, 255);//���F�̒l���擾

	DrawPixel(320, 240, GetColor(255, 255, 255));//�_��ł�

	DrawString(320, 240, "DxLib�ւ悤�����I", Cr);

	WaitKey();

	DxLib_End();

	return 0;
}