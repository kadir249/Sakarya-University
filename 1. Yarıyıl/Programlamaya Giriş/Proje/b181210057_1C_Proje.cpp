/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: Proje
**				��RENC� ADI...............: Kadir �elik
**				��RENC� NUMARASI.: B181210057
**				DERS GRUBU����: 1C Grubu
****************************************************************************/

#include <Windows.h>
#include <iostream>
#include <time.h>
#include <ctime>

using namespace std;

//YON adl� veri tipi tan�mlan�yor
enum YON
{
	YON_SAG = 1,
};

//MermiHucre adl� yap� tan�mlan�yor
struct MermiHucre
{
	int xEkseni;
	int yEkseni;

	YON yon;
	char karakter;
};

//De�i�kenler tan�mlan�yor
const int genislik = 80;
const int yukseklik = 20;
char sahne[genislik][yukseklik];
char tuslar[256];
int ucakY = 8;
int ucakX = 3;
int dusmanY = 5;
int dusmanX = 3;
MermiHucre mermi[1];
int dusman1X = 80;
int dusman2X = 90;
int dusman3X = 100;
int a = 0;


void gotoxy(int x, int y)//Koordinat de�i�tirme fonksiyonu
{
	//Koordinatlar tan�mlan�yor
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);//Windows ile ileti�ime ge�ilmesini sa�lar. Koordinatlar� de�i�tirmek i�in kullan�l�r
}

void kursoruGizle()//Sahnede olu�an hatay� engellemek i�in kullan�lan fonksiyon olu�turuluyor
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO		cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void sahneyiCiz()//Sahneyi �izen fonksiyon olu�turuluyor
{
	for (int y = 0; y < yukseklik; y++)//y yuksekli�e e�it oluncaya kadar y'yi artt�r�r
	{
		for (int x = 0; x < genislik; x++)//x genisli�e e�it oluncaya kadar x'i artt�r�r
		{
			cout << sahne[x][y];//sahne ekrana yazd�l�r
		}
		cout << endl;
	}
}

void sahneyiTemizle()//Sahneyi temizleyen fonksiyon olu�turuluyor
{
	for (int y = 0; y < yukseklik; y++)//y yuksekli�e e�it oluncaya kadar y'yi artt�r�r
	{
		for (int x = 0; x < genislik; x++)//x genisli�e e�it oluncaya kadar x'i artt�r�r
		{
			sahne[x][y] = ' ';//Sahneye bo� de�er karakter atar
		}
	}
}

void sinirlariOlustur()//Oyunun s�n�rlar�n� olu�turan fonksiyon olu�turuluyor
{
	for (int sinirX = 0; sinirX < genislik; sinirX++)//sinirX'i genisli�e e�it oluncaya kadar artt�r�r
	{
		//S�n�rlara ASCII kodu 219 olan �ekil atan�yor
		sahne[sinirX][0] = 219;
		sahne[sinirX][yukseklik - 1] = 219;
	}
	for (int sinirY = 0; sinirY < yukseklik; sinirY++)//sinirY'i yukseklige e�it oluncaya kadar artt�r�r
	{
		//S�n�rlara ASCII kodu 219 olan �ekil atan�yor
		sahne[0][sinirY] = 219;
		sahne[genislik - 1][sinirY] = 219;
	}
}

void ucakOlustur()//U�a�� olu�turan fonksiyon olu�turuluyor
{
	//U�ak �iziliyor. U�a��n �iziminde ASCII kodu 219 olan �ekil kullan�l�yor
	sahne[ucakX - 2][ucakY - 2] = 219;
	sahne[ucakX - 1][ucakY - 1] = 219;
	sahne[ucakX][ucakY] = 219;
	sahne[ucakX - 1][ucakY + 1] = 219;
	sahne[ucakX - 2][ucakY + 2] = 219;
}

void mermiOlustur()//Mermiyi olu�turan fonksiyon olu�turuluyor
{
	//De�i�kenler tan�mlan�yor
	int mermiX = mermi[a].xEkseni;
	int mermiY = mermi[a].yEkseni;
	//Mermiye ASCII kodu 220 olan �ekil atan�yor
	sahne[mermiX][mermiY] = 220;
}

void mermiyiAtesle()//Mermiyi ate�leyen fonksiyon olu�turuluyor
{
	if (mermi[a].xEkseni < 80)//E�er merminin xEkseni 80'den k���k olursa
	{
		switch (mermi[a].yon)//Merminin y�n� kontrol ediliyor
		{
		case YON_SAG://YON_SAG verisi kontrol ediliyor
			mermi[a].xEkseni++;//Merminin xEksenini arttr�r
			break;
		}
	}
}

void dusmanlariOlustur()//D��manlar� olu�turan fonksiyon olu�turuluyor
{
	if (dusman1X > 0)//E�er dusman1X s�f�rdan b�y�kse
	{
		//�lk d��man olu�turuluyor. �lk d��man�n �eklini �izmek i�in ASCII kodu 178 olan �ekil kullan�l�yor
		sahne[dusman1X - 1][dusmanY - 4] = 178;
		sahne[dusman1X][dusmanY - 4] = 178;
		sahne[dusman1X + 1][dusmanY - 4] = 178;
		sahne[dusman1X - 1][dusmanY - 3] = 178;
		sahne[dusman1X + 1][dusmanY - 3] = 178;
		sahne[dusman1X - 1][dusmanY - 2] = 178;
		sahne[dusman1X][dusmanY - 2] = 178;
		sahne[dusman1X + 1][dusmanY - 2] = 178;
	}
	dusman1X -= 1;//dusman1X'i bir eksiltir

	if (dusman2X > 0)//E�er dusman2X s�f�rdan b�y�kse
	{
		//�kinci d��man olu�turuluyor. �kinci d��man�n �eklini �izmek i�in ASCII kodu 178 olan �ekil kullan�l�yor
		sahne[dusman2X - 1][dusmanY + 11] = 178;
		sahne[dusman2X][dusmanY + 11] = 178;
		sahne[dusman2X + 1][dusmanY + 11] = 178;
		sahne[dusman2X - 1][dusmanY + 12] = 178;
		sahne[dusman2X + 1][dusmanY + 12] = 178;
		sahne[dusman2X - 1][dusmanY + 13] = 178;
		sahne[dusman2X][dusmanY + 13] = 178;
		sahne[dusman2X + 1][dusmanY + 13] = 178;
	}
	dusman2X -= 1;//dusman2X'i bir eksiltir

	if (dusman3X > 0)//E�er dusman2X s�f�rdan b�y�kse
	{
		//���nc� d��man olu�turuluyor. ���nc� d��man�n �eklini �izmek i�in ASCII kodu 178 olan �ekil kullan�l�yor
		sahne[dusman3X - 1][dusmanY + 2] = 178;
		sahne[dusman3X][dusmanY + 2] = 178;
		sahne[dusman3X + 1][dusmanY + 2] = 178;
		sahne[dusman3X - 1][dusmanY + 3] = 178;
		sahne[dusman3X + 1][dusmanY + 3] = 178;
		sahne[dusman3X - 1][dusmanY + 4] = 178;
		sahne[dusman3X][dusmanY + 4] = 178;
		sahne[dusman3X + 1][dusmanY + 4] = 178;
	}
	dusman3X -= 1;//dusman3X'i bir eksiltir
}

void klavyeOku(char tuslar[])//Klavyeden bas�lan tu�u tespit eden fonksiyon olu�turuluyor
{
	for (int x = 0; x < 256; x++)//x 0'dan 256'ya kadar artt�r�r
	{
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
	}
}

void klavyeKontrol()//Klavyede hangi tu�a bas�l�p bas�lmad���n� kontrol eden fonksiyon olu�turuluyor
{
	klavyeOku(tuslar);//klavyeOku fonksiyonu �a�r�l�yor

	if (tuslar['W'] != 0)//E�er W s�f�rdan farkl�ysa
	{
		if (ucakY > 3)//E�er ucakY 3'ten k���kse
		{
			ucakY -= 1;//ucakY bir eksiltilir
		}
	}

	if (tuslar['S'] != 0)//E�er S s�f�rdan farkl�ysa
	{
		if (ucakY < 16)//E�er ucakY 16'dan k���kse
		{
			ucakY += 1;//ucakY bir artt�r�l�r
		}
	}

	if (tuslar[32] != 0)//E�er bo�luk ss�f�rdan farkl�ysa
	{
		//Mermi u�a��n ucundan ate�lenir
		mermi[a].xEkseni = ucakX + 1;
		mermi[a].yEkseni = ucakY;
		mermi[a].yon = YON_SAG;
	}
}

void dusmanlariSil()//D��manlar� silmeyi sa�layan fonksiyon olu�turuluyor
{
	//De�i�ken tan�mlan�yor
	int i = 0;

	if (mermi[i].xEkseni == dusman1X - 1 && mermi[i].yEkseni == dusmanY - 2)//E�er merminin xEkseni dusman1X'ten 1 eksikse ve merminin yEkseni dusmanY'den 2 eksikse
	{
		//D��man 1 ve mermi bo� bir yere at�l�r
		sahne[dusman1X - 1][dusmanY - 4] = sahne[85][30];
		sahne[dusman1X - 1][dusmanY - 4] = sahne[85][30];
		sahne[dusman1X - 1][dusmanY - 4] = sahne[85][30];
		sahne[dusman1X - 1][dusmanY - 3] = sahne[85][30];
		sahne[dusman1X - 1][dusmanY - 3] = sahne[85][30];
		sahne[dusman1X - 1][dusmanY - 2] = sahne[85][30];
		sahne[dusman1X - 1][dusmanY - 2] = sahne[85][30];
		sahne[dusman1X - 1][dusmanY - 2] = sahne[85][30];
		mermi[i].xEkseni = 81;
		mermi[i].yEkseni = 25;
	}

	if (mermi[i].xEkseni == dusman2X - 1 && mermi[i].yEkseni == dusmanY + 11)//E�er merminin xEkseni dusman2X'ten 1 eksikse ve merminin yEkseni dusmanY'den 11 fazlaysa
	{
		//D��man 2 ve mermi bo� bir yere at�l�r
		sahne[dusman2X - 1][dusmanY + 11] = sahne[85][30];
		sahne[dusman2X][dusmanY + 11] = sahne[85][30];
		sahne[dusman2X + 1][dusmanY - 4] = sahne[85][30];
		sahne[dusman2X - 1][dusmanY - 3] = sahne[85][30];
		sahne[dusman2X + 1][dusmanY - 3] = sahne[85][30];
		sahne[dusman2X - 1][dusmanY - 2] = sahne[85][30];
		sahne[dusman2X][dusmanY - 2] = sahne[85][30];
		sahne[dusman2X + 1][dusmanY - 2] = sahne[85][30];
		mermi[i].xEkseni = 81;
		mermi[i].yEkseni = 25;
	}

	//E�er merminin xEkseni dusman1X'ten 1 eksikse ve merminin yEkseni dusmanY'den iki fazlaysa veya merminin yEkseni dusmanY'den 3 fazlaysa veya merminin yEkseni dusmanY'den 4 fazlaysa 
	if (mermi[i].xEkseni == dusman3X - 1 && (mermi[i].yEkseni == dusmanY + 2 || mermi[i].yEkseni == dusmanY + 3 || mermi[i].yEkseni == dusmanY + 4))
	{
		//D��man 3 ve mermi bo� bir yere at�l�r
		sahne[dusman3X - 1][dusmanY + 2] = sahne[85][30];
		sahne[dusman3X][dusmanY + 2] = sahne[85][30];
		sahne[dusman3X + 1][dusmanY + 2] = sahne[85][30];
		sahne[dusman3X - 1][dusmanY + 3] = sahne[85][30];
		sahne[dusman3X + 1][dusmanY + 3] = sahne[85][30];
		sahne[dusman3X - 1][dusmanY + 4] = sahne[85][30];
		sahne[dusman3X][dusmanY + 4] = sahne[85][30];
		sahne[dusman3X + 1][dusmanY + 4] = sahne[85][30];
		mermi[i].xEkseni = 81;
		mermi[i].yEkseni = 25;
	}

}

int main()
{
	//Fonksiyon �a�r�l�yor
	kursoruGizle();

	while (true)//D�ng� true d�nerse
	{
		//Fonksiyonlar �a�r�l�yor
		sahneyiTemizle();

		ucakOlustur();

		dusmanlariOlustur();

		sinirlariOlustur();

		klavyeKontrol();

		mermiyiAtesle();

		mermiOlustur();

		dusmanlariSil();

		gotoxy(0, 0);

		sahneyiCiz();

		Sleep(5);

		if (dusman1X <= 0)//E�er d�sman1X 0'a k���k e�itse
		{
			dusman1X += genislik;//dusman1X genisli�e kadar artar
		}
		if (dusman2X <= 0)//E�er d�sman2X 0'a k���k e�itse
		{
			dusman2X += genislik;//dusman1X genisli�e kadar artar
		}
		if (dusman3X <= 0)//E�er d�sman3X 0'a k���k e�itse
		{
			dusman3X += genislik;//dusman1X genisli�e kadar artar
		}

		klavyeOku(tuslar);
	}

	cin.get();//Konsol ekran�n�n kapanmas�n� engeller
}