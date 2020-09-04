#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	unsigned int Cr;

	SetMainWindowText("test");

	ChangeWindowMode(TRUE);//ウィンドウモードに変更

	SetGraphMode(1280, 720, 32);//解像度を設定

	if (DxLib_Init() == -1)//DXライブラリ初期化処理、エラーが起きたらif内へ
	{
		return -1;//エラーが起きたら直ちに終了
	}

	SetWindowSizeChangeEnableFlag(TRUE);//サイズ変更を許可

	SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面にする

	SetWindowStyleMode(7);

	char Buf(256);

	ChangeFont("コーポレート・ロゴＭ");//文字のフォントを変更

	SetFontSize(100);//フォントサイズの設定

	Cr = GetColor(255, 255, 255);//白色の値を取得

	DrawPixel(320, 240, GetColor(255, 255, 255));//点を打つ

	DrawString(0, 0, "Escキーで終了", Cr);//文字の描画

	DrawString(0, 100, "Enterキーで次へ進む", Cr);

	ScreenFlip();//裏画面の描画結果を表画面へ表示

	while (1)
	{
		

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)//Enterキーの入力状態を確認
		{
			ClearDrawScreen();//描画していたものを消去

			ScreenFlip();//表画面へ表示

			WaitKey();

			break;
		}
		else
		{

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)//Escキーの入力状態を確認
			{
				DxLib_End();

				return 0;
			}
		}
		if (ProcessMessage() == -1)//Windowsのメッセージを処理（定期的にする必要がある）
		{
			break;
		}
	}



	

	DxLib_End();//DXライブラリ終了処理

	return 0;//ウィンドウを閉じる
}