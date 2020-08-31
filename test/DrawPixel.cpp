#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	unsigned int Cr;

	SetMainWindowText("test");

	ChangeWindowMode(TRUE);//ウィンドウモードに変更

	//SetGraphMode(1920, 1080, 32);

	if (DxLib_Init() == -1)//DXライブラリ初期化処理
	{
		return -1;//エラーが起きたら直ちに終了
	}

	SetWindowSizeChangeEnableFlag(TRUE);

	SetWindowStyleMode(7);

	ChangeFont("コーポレート・ロゴＭ");//文字のフォントを変更

	Cr = GetColor(255, 255, 255);//白色の値を取得

	DrawPixel(320, 240, GetColor(255, 255, 255));//点を打つ

	DrawString(320, 240, "DxLibへようこそ！", Cr);

	WaitKey();

	DxLib_End();

	return 0;
}