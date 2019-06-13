#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

void ImageName(char _cImageName[], char _cNumber[]);

/*
	void PlayerStatsSave(tagPlayer* _tPlayer)
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/PlayerData.txt", "wb");

	if (err == 0)
	{
		// fwrite(&_tPlayer, sizeof(tagPlayer), 1, fp); 이 방식으론 ㄴㄴ
		fwrite(_tPlayer, sizeof(tagPlayer), 1, fp);
		fclose(fp);
	}
	else
		cout << "파일 저장 실패" << endl;
}

void PlayerStatsLoad(tagPlayer* _tPlayer, bool _CharLoadErrorChecking)
{
	FILE* fp = nullptr;

	tagPlayer tPlayer;

	errno_t err = fopen_s(&fp, "../Data/PlayerData.txt", "rb");

	if (err == 0)
	{
		fread(&tPlayer, sizeof(tagPlayer), 1, fp);

		memcpy(_tPlayer->cName, tPlayer.cName, sizeof(tPlayer.cName));
		_tPlayer->fAtk = tPlayer.fAtk;
		_tPlayer->fHp = tPlayer.fHp;
		_tPlayer->fMaxHp = tPlayer.fMaxHp;
		_tPlayer->iLv = tPlayer.iLv;
		_tPlayer->fExp = tPlayer.fExp;
		_tPlayer->bPlayerLife = tPlayer.bPlayerLife;

		//system("pause");
		fclose(fp);
	}
	else
	{
		cout << "파일 불러오기 실패 " << endl;
		_CharLoadErrorChecking = true;
	}
}
*/
char llTemp[1000000];
long long llSize = 0;

//void LoadImage(int* iImage)
//{
//	FILE* fp = nullptr;
//
//	errno_t err = fopen_s(&fp, "../Data/skillICon.jpg", "rb");
//
//	if (err == 0)
//	{
//		fread(llTemp, sizeof(llTemp), 1, fp);
//		fclose(fp);
//	}
//	else
//	{
//		cout << "파일 불러오기 실패 " << endl;
//	}
//
//}

void LoadImage()
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/skillICon.jpg", "rb");

	if (err == 0)
	{
		fread(llTemp, sizeof(llTemp), 1, fp);
		fclose(fp);
	}
	else
	{
		cout << "파일 불러오기 실패 " << endl;
	}

}


//void SaveImage(int* iImage)
//{
//	FILE* fp = nullptr;
//
//	errno_t err = fopen_s(&fp, "../Data/skillICon1.jpg", "wb");
//	if (err == 0)
//	{
//		fwrite(llTemp, sizeof(llTemp), 1, fp);
//		fclose(fp);
//	}
//	else
//		cout << "파일 저장 실패" << endl;
//
//}

void SaveImage()
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/skillICon1.jpg", "wb");
	if (err == 0)
	{
		fwrite(llTemp, sizeof(llTemp), 1, fp);
		fclose(fp);
	}
	else
		cout << "파일 저장 실패" << endl;

}
     

void ImageName(char _cImageName[], char _cNumber[])
{
	strcat(_cImageName, _cNumber);
}

void main()
{
	/*char cImageName[100] = "Image";
	char cNum[10] = {};
	int iNum = 0;
	itoa(iNum, cNum, 10);
	ImageName(cImageName, cNum);
	cout << cImageName << endl;*/

	LoadImage();
	SaveImage();
	

	return;
}

void main1()
{
	char szImageName[32] = "";
	char szCopyName[32] = "";
	char szRelative[32] = "../Data/";

	cout << "원본 이미지 이름 :";
	cin >> szImageName;

	strcat_s(szRelative, szImageName);

	FILE* fp_In = nullptr;
	FILE* fp_Out = nullptr;

	errno_t err = fopen_s(&fp_In, szRelative, "rb");

	if (err == 0)
	{
		cout << "복사 이미지 이름 : ";
		cin >> szCopyName;

		strcpy_s(szRelative, "../Data/");
		strcat_s(szRelative, szCopyName);

		err = fopen_s(&fp_Out, szRelative, "wb");

		if (err == 0)
		{
			fseek(fp_In, 0, SEEK_END);
			int iBufferCount = ftell(fp_In);

			// 우리가 구한 iBufferCount는 1바이트 단위이므로 char를 이용.
			char* ptr = new char[iBufferCount];

			fseek(fp_In, 0, SEEK_SET);
			// 원본 읽고
			fread(ptr, sizeof(char), iBufferCount, fp_In);
			// 그대로 출력
			fwrite(ptr, sizeof(char), iBufferCount, fp_Out);

			delete[] ptr;
			ptr = nullptr;
			fclose(fp_In);
			fclose(fp_Out);

			cout << "복사 성공" << endl;
		}
		else
		{

		}
	}
	else
	{

	}


}