/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: Proje
**				ÖÐRENCÝ ADI...............: Kadir Çelik
**				ÖÐRENCÝ NUMARASI.: B181210057
**				DERS GRUBU…………: 1C Grubu
****************************************************************************/

#include <Windows.h>
#include <iostream>
#include <time.h>
#include <ctime>

using namespace std;

//YON adlý veri tipi tanýmlanýyor
enum YON
{
	YON_SAG = 1,
};

//MermiHucre adlý yapý tanýmlanýyor
struct MermiHucre
{
	int xEkseni;
	int yEkseni;

	YON yon;
	char karakter;
};

//Deðiþkenler tanýmlanýyor
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


void gotoxy(int x, int y)//Koordinat deðiþtirme fonksiyonu
{
	//Koordinatlar tanýmlanýyor
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);//Windows ile iletiþime geçilmesini saðlar. Koordinatlarý deðiþtirmek için kullanýlýr
}

void kursoruGizle()//Sahnede oluþan hatayý engellemek için kullanýlan fonksiyon oluþturuluyor
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO		cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void sahneyiCiz()//Sahneyi çizen fonksiyon oluþturuluyor
{
	for (int y = 0; y < yukseklik; y++)//y yuksekliðe eþit oluncaya kadar y'yi arttýrýr
	{
		for (int x = 0; x < genislik; x++)//x genisliðe eþit oluncaya kadar x'i arttýrýr
		{
			cout << sahne[x][y];//sahne ekrana yazdýlýr
		}
		cout << endl;
	}
}

void sahneyiTemizle()//Sahneyi temizleyen fonksiyon oluþturuluyor
{
	for (int y = 0; y < yukseklik; y++)//y yuksekliðe eþit oluncaya kadar y'yi arttýrýr
	{
		for (int x = 0; x < genislik; x++)//x genisliðe eþit oluncaya kadar x'i arttýrýr
		{
			sahne[x][y] = ' ';//Sahneye boþ deðer karakter atar
		}
	}
}

void sinirlariOlustur()//Oyunun sýnýrlarýný oluþturan fonksiyon oluþturuluyor
{
	for (int sinirX = 0; sinirX < genislik; sinirX++)//sinirX'i genisliðe eþit oluncaya kadar arttýrýr
	{
		//Sýnýrlara ASCII kodu 219 olan þekil atanýyor
		sahne[sinirX][0] = 219;
		sahne[sinirX][yukseklik - 1] = 219;
	}
	for (int sinirY = 0; sinirY < yukseklik; sinirY++)//sinirY'i yukseklige eþit oluncaya kadar arttýrýr
	{
		//Sýnýrlara ASCII kodu 219 olan þekil atanýyor
		sahne[0][sinirY] = 219;
		sahne[genislik - 1][sinirY] = 219;
	}
}

void ucakOlustur()//Uçaðý oluþturan fonksiyon oluþturuluyor
{
	//Uçak çiziliyor. Uçaðýn çiziminde ASCII kodu 219 olan þekil kullanýlýyor
	sahne[ucakX - 2][ucakY - 2] = 219;
	sahne[ucakX - 1][ucakY - 1] = 219;
	sahne[ucakX][ucakY] = 219;
	sahne[ucakX - 1][ucakY + 1] = 219;
	sahne[ucakX - 2][ucakY + 2] = 219;
}

void mermiOlustur()//Mermiyi oluþturan fonksiyon oluþturuluyor
{
	//Deðiþkenler tanýmlanýyor
	int mermiX = mermi[a].xEkseni;
	int mermiY = mermi[a].yEkseni;
	//Mermiye ASCII kodu 220 olan þekil atanýyor
	sahne[mermiX][mermiY] = 220;
}

void mermiyiAtesle()//Mermiyi ateþleyen fonksiyon oluþturuluyor
{
	if (mermi[a].xEkseni < 80)//Eðer merminin xEkseni 80'den küçük olursa
	{
		switch (mermi[a].yon)//Merminin yönü kontrol ediliyor
		{
		case YON_SAG://YON_SAG verisi kontrol ediliyor
			mermi[a].xEkseni++;//Merminin xEksenini arttrýr
			break;
		}
	}
}

void dusmanlariOlustur()//Düþmanlarý oluþturan fonksiyon oluþturuluyor
{
	if (dusman1X > 0)//Eðer dusman1X sýfýrdan büyükse
	{
		//Ýlk düþman oluþturuluyor. Ýlk düþmanýn þeklini çizmek için ASCII kodu 178 olan þekil kullanýlýyor
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

	if (dusman2X > 0)//Eðer dusman2X sýfýrdan büyükse
	{
		//Ýkinci düþman oluþturuluyor. Ýkinci düþmanýn þeklini çizmek için ASCII kodu 178 olan þekil kullanýlýyor
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

	if (dusman3X > 0)//Eðer dusman2X sýfýrdan büyükse
	{
		//Üçüncü düþman oluþturuluyor. Üçüncü düþmanýn þeklini çizmek için ASCII kodu 178 olan þekil kullanýlýyor
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

void klavyeOku(char tuslar[])//Klavyeden basýlan tuþu tespit eden fonksiyon oluþturuluyor
{
	for (int x = 0; x < 256; x++)//x 0'dan 256'ya kadar arttýrýr
	{
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
	}
}

void klavyeKontrol()//Klavyede hangi tuþa basýlýp basýlmadýðýný kontrol eden fonksiyon oluþturuluyor
{
	klavyeOku(tuslar);//klavyeOku fonksiyonu çaðrýlýyor

	if (tuslar['W'] != 0)//Eðer W sýfýrdan farklýysa
	{
		if (ucakY > 3)//Eðer ucakY 3'ten küçükse
		{
			ucakY -= 1;//ucakY bir eksiltilir
		}
	}

	if (tuslar['S'] != 0)//Eðer S sýfýrdan farklýysa
	{
		if (ucakY < 16)//Eðer ucakY 16'dan küçükse
		{
			ucakY += 1;//ucakY bir arttýrýlýr
		}
	}

	if (tuslar[32] != 0)//Eðer boþluk ssýfýrdan farklýysa
	{
		//Mermi uçaðýn ucundan ateþlenir
		mermi[a].xEkseni = ucakX + 1;
		mermi[a].yEkseni = ucakY;
		mermi[a].yon = YON_SAG;
	}
}

void dusmanlariSil()//Düþmanlarý silmeyi saðlayan fonksiyon oluþturuluyor
{
	//Deðiþken tanýmlanýyor
	int i = 0;

	if (mermi[i].xEkseni == dusman1X - 1 && mermi[i].yEkseni == dusmanY - 2)//Eðer merminin xEkseni dusman1X'ten 1 eksikse ve merminin yEkseni dusmanY'den 2 eksikse
	{
		//Düþman 1 ve mermi boþ bir yere atýlýr
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

	if (mermi[i].xEkseni == dusman2X - 1 && mermi[i].yEkseni == dusmanY + 11)//Eðer merminin xEkseni dusman2X'ten 1 eksikse ve merminin yEkseni dusmanY'den 11 fazlaysa
	{
		//Düþman 2 ve mermi boþ bir yere atýlýr
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

	//Eðer merminin xEkseni dusman1X'ten 1 eksikse ve merminin yEkseni dusmanY'den iki fazlaysa veya merminin yEkseni dusmanY'den 3 fazlaysa veya merminin yEkseni dusmanY'den 4 fazlaysa 
	if (mermi[i].xEkseni == dusman3X - 1 && (mermi[i].yEkseni == dusmanY + 2 || mermi[i].yEkseni == dusmanY + 3 || mermi[i].yEkseni == dusmanY + 4))
	{
		//Düþman 3 ve mermi boþ bir yere atýlýr
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
	//Fonksiyon çaðrýlýyor
	kursoruGizle();

	while (true)//Döngü true dönerse
	{
		//Fonksiyonlar çaðrýlýyor
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

		if (dusman1X <= 0)//Eðer düsman1X 0'a küçük eþitse
		{
			dusman1X += genislik;//dusman1X genisliðe kadar artar
		}
		if (dusman2X <= 0)//Eðer düsman2X 0'a küçük eþitse
		{
			dusman2X += genislik;//dusman1X genisliðe kadar artar
		}
		if (dusman3X <= 0)//Eðer düsman3X 0'a küçük eþitse
		{
			dusman3X += genislik;//dusman1X genisliðe kadar artar
		}

		klavyeOku(tuslar);
	}

	cin.get();//Konsol ekranýnýn kapanmasýný engeller
}