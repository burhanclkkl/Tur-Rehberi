
#include<iostream>  // GİRDİ - ÇIKTI KÜTÜPHANE
#include<fstream>   // DOSYALARA GİRİŞ ÇIKIŞ İŞLEMLERİ İÇİN KULLANILAN KÜTÜPHANE                                                                                               
#include<string> 
#include<locale.h>
#include<clocale>  // TÜRKÇE KARAKTERLER 
#include"windows.h" // ARKAPLAN VE YAZI RENGİ

using namespace std;





// FİYAT BELİRLEME -----------------------------------------

class birinciislem {
public:

	int carpmaislemi(int cocukfyat, int cocuksayisi) // ÇARPMA İŞLEMİ İÇİN KULLANILAN CLASS YAPISI

	{
		return cocukfyat * cocuksayisi;
	}
};

class ikinciislem {
public:

	int toplamaislemi(int yetiskin, int cocuk) // TOPLAMA İŞLEMİ İÇİN KULLANILAN CLASS YAPISI
	{
		return yetiskin + cocuk;
	}
};

class ucuncuislem {
public:

	int carpmaislemi1(int yetiskinfiyat, int yetiskinkisisayisi) // ÇARPMA İŞLEMİ İÇİN KULLANILAN CLASS YAPISI

	{
		return yetiskinfiyat * yetiskinkisisayisi;
	}
};

class ucrethesaplama : public birinciislem, ikinciislem, ucuncuislem {
public:

	int islemsonucu(int yetiskinfiyat, int yetiskinkisisayisi, int cocukfyat, int cocuksayisi)
	{
		return toplamaislemi(carpmaislemi1(yetiskinfiyat, yetiskinkisisayisi), carpmaislemi(cocukfyat, cocuksayisi));
	}
};

// FİYAT BELİRLEME -----------------------------------------








// DOSYA İŞLEMLERİ İÇİN KULLANILAN CLASS YAPILARI -----------------------------------------

class DosyaIslemleri
{
private:
	// PERSONEL HAKKIINDA DEĞİŞKENLER
	string adi; // PERSONEL İSMİ İÇİN  KULLANILAN DEĞİŞKEN
	string soyadi;  // PERSONEL SOYİSMİ İÇİN  KULLANILAN DEĞİŞKEN
	string yas;  // PERSONEL YAŞI İÇİN KULLANILAN DEĞİŞKEN
	string tc_no; // PERSONEL TC NO' SU İÇİN KULLANILAN DEĞİŞKEN
	string tel_no; // PERSONEL TELEFON NO' SU İÇİN KULLANILAN DEĞİŞKEN
	// Dosyaya yazma işlemini sağlayan metod.
	void dosyazma()
	{
		// ofstream tipinde bir nesne ile dosya yaratılır.
		// ios::app parametresiyle dosyaya yazma işleminin eklemeli olması sağlanır.
		ofstream  dosya("proje.txt", ios::app);
		//  "<<" operatoru IO kütüphanesini yazanlar tarafından aşırı yüklenmiştir. 
		// Böylece  "<<" operatörü yazma işlemini sağlamaktadır.

		dosya << "Personelin Adı : " << adi << endl;
		dosya << "Personelin Soyadı : " << soyadi << endl;
		dosya << "Personelin Yaşı : " << yas << endl;
		dosya << "Personelin Kimlik Numarası : " << tc_no << endl;
		dosya << "Personelin Telefon Numarası : " << tel_no << endl;

		dosya.close();  // Dosya kullanıldıktan sonra kapatılır.
	}

	// Dosyadan okuma işlemini sağlayan metod.
	void dosyaokuma()
	{
		string line;
		// "ornek.txt" isimli dosya okunmak üzere açılır.
		ifstream reader("proje.txt");
		// Dosyayının açılıp açılmadığı kontrol edilir.
		if (reader.is_open())
		{
			int sayac = 0;
			// Döngü ile dosya içindeki kayıtlar okunur.
			while (reader.good())
			{
				// "getline" metodu ile birlikte dosyadan bir satır okunur.
				getline(reader, line);
				cout << line << endl;
				sayac++;
				// Eğer 5 satır okunmuşsa bir kayıt bitirilmiş demektir.
				// Her 5 satırda bir kayıt okunur.
				if (sayac == 5)
				{
					sayac = 0;
					cout << " -------------- \n\n" << endl;
				}
			}
		}
	}
public:
	void personelekle()
	{
		setlocale(LC_ALL, "Turkish");

		cout << " Personelin ; \n" << endl;

		cout << " Adı Gİriniz : " << endl;
		cin >> adi;
		cout << " Soyadını Giriniz : " << endl;
		cin >> soyadi;
		cout << " Yaşını Giriniz : " << endl;
		cin >> yas;
		cout << " Kimlik Numarası Giriniz : " << endl;
		cin >> tc_no;
		cout << " Telefon Numarası Giriniz : " << endl;
		cin >> tel_no;
		dosyazma();
	}

	void personellistele()
	{
		dosyaokuma();
	}
};






// ekrana menüyü hazırlayan sınıf yapısıdır.
class Ekran
{
private:
	int tercih;
	// Ekran sınıfı Dosya işlemlerinide kapsadığı için bir nesne yaratılır.
	DosyaIslemleri dosyalamaislemi;
public:
	Ekran()
	{
		tercih = 0;
	}
	// Ekrana menü yansıtılır.
	void menu()
	{
		while (tercih != 3)
		{
			setlocale(LC_ALL, "Turkish");

			cout << " Personel ekle: \n" << endl;


			cout << " 1 - Personel ekleme " << endl;
			cout << " 2 - Personel Listeleme " << endl;
			cout << " 3 - Çıkış \n" << endl;
			cout << " SEÇİMİNİZ : ";
			cin >> tercih;
			cout << "" << endl;
			if (tercih == 1)
			{
				dosyalamaislemi.personelekle();
			}
			else if (tercih == 2)
			{
				dosyalamaislemi.personellistele();
			}
			else if (tercih == 3)
			{
				break;
			}
		}
	}
};


// DOSYA İŞLEMLERİ İÇİN KULLANILAN CLASS YAPILARI -----------------------------------------











int main()
{

	setlocale(LC_ALL, "Turkish");  // TÜRKÇE KARAKTER GRİMEK İÇİN KULLANILIR.


	cout << "    ________________________________________ " << endl;
	cout << "   |                                        |" << endl;
	cout << "   |     +  CLKKL-TUR' A H0ŞGELDİNİZ   +    |" << endl;
	cout << "   |________________________________________| \n\n\n" << endl;





	int musteriyadayoneticisecimi; // MÜŞTERİ YA DA YÖNETİCİ GİRİŞİ İÇİN KULLANILAN DEĞER.

	cout << " Yönetici Girişi İçin Şifreyi Giriniz : ( Şifre --> '123' ) " << endl;
	cout << " Müşteri  Girişi İçin                 : Herhangi Bir Tuşa basınız \n " << endl;
	cin >> musteriyadayoneticisecimi;
	cout << "\n" << endl;

	if (musteriyadayoneticisecimi == 123)
	{
		// Ekran tipinde bir nesne yaratılır ve program çalışmaya başlar.

		Ekran ekran;
		ekran.menu();
		system("PAUSE");
		return 0;
	}

	int sec; // TUR SEÇİMİ 


anamenu:    // ANA MENÜYE DÖNMEK İÇİN ÇAĞIRILAN GO TO.



	cout << "" << endl;
	cout << "" << endl;
	cout << "                TURLARIMIZ                        " << endl;
	cout << "" << endl;
	cout << "   ________________________________________" << endl;
	cout << "" << endl;


	cout << "  1. Afrika Turları                                  " << endl;
	cout << "  2. Amerika Turları                                 " << endl;
	cout << "  3. Orta Avrupa ve Almanya Turları                  " << endl;
	cout << "  4. Birleşik Arap Emirlikleri Turları               " << endl;
	cout << "  5. Güney Afrika Turları                            " << endl;


	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	cout << "SEÇİMİNİZ : ";
	cin >> sec;

	cout << "" << endl;
	cout << "" << endl;






	if (sec < 1 || sec>6)
	{
		cout << "HATALI SEÇİM YAPTINIZ ! (Tekrar denemek için lütfen 2' ye basınız )  : ";
		cin >> sec;

		if (sec == 2)
		{
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			goto anamenu;
		}
	}

	// ---- SEÇİM -1 ----

	if (sec == 1)  // seçim 1
	{

	tursec:   // TUR SEÇİMİ MENÜSÜNE DÖNMEK İÇİN ÇAĞIRILAN GO TO.

		cout << "   Afrika Turları" << endl;
		cout << "____________________________________________________________________________" << endl;

		cout << "" << endl;

		cout << "  1. Büyülü Sahra Çölü Turu          * (  4.915 TL )   -> 7 Gece -  8 Gün  " << endl;
		cout << "  2. Kenya - Tanzanya Turu           * ( 16.696 TL )   -> 6 Gece -  7 Gün " << endl;
		cout << "  3. Muhteşem Güney Afrika Turu      * (  8.350 TL )   -> 7 Gece - 10 Gün " << endl;


		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;


		cout << " (Ana Menüye dönmek isterseniz 9 ' a basınız.)  \n \n  SEÇİMİNİZ : ";
		cin >> sec;




		if (sec == 9)
		{
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			goto anamenu;


		}

		// ---- SEÇİM -1-1 ----

		if (sec == 1) // seçim 1 / 1 
		{

		sefer11:  // SEFER MENÜSÜNE DÖNMEK İÇİN ÇAĞIRILAN GO TO.
		yanlis:   // YANLIŞ DEĞER GİRİLDİĞİNDE SEFER MENÜSÜNE DÖNMEK İÇİN ÇAĞIRILAN GO TO.

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "   Büyülü Sahra Çölü Turu  " << endl;


			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			if (sec == 2)
			{
				goto anamenu;
			}


			if (sec == 3)
			{
				goto tursec;
			}


			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis;
			}



			if (sec == 9)
			{

				cout << "  Sefer Detayları : " << endl;   // SEFER DETAYLARININ GÖRÜNTÜLENMESİ.
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;
				cout << "  1.Gün -->  İstanbul - Kazablanka - Marakeş                                           " << endl;
				cout << "  2.Gün -->  Marakeş                                                                   " << endl;
				cout << "  3.Gün -->  Marakeş - Ourzazate                                                       " << endl;
				cout << "  4.Gün -->  Ourzazate - Todra - Erfoud                                                " << endl;
				cout << "  5.Gün -->  Erfoud - Ifrane - Fez                                                     " << endl;
				cout << "  6.Gün -->  Fez(Meknez)                                                               " << endl;
				cout << "  7.Gün -->  Fez - Rabat - Kazablanka                                                  " << endl;
				cout << "  8.Gün -->  Kazablanka - İstanbul                                                     " << endl;

				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________" << endl;

				cout << "" << endl;

				cout << "  - Royal Air Maroc Havayolları ile İstanbul - Kazablanka ve Kazablanka - İstanbul hattında  ekonomi sınıf uçuş " << endl;
				cout << "  - Havalimanı vergileri " << endl;
				cout << "  - Fas'ta toplam 7 gece belirtilen kategorideki otelde konaklama " << endl;
				cout << "  - Otellerde alınacak 7 kahvaltı ve 6 akşam yemeği " << endl;
				cout << "  - Alan / Otel / Alan transferleri " << endl;
				cout << "  - Zorunlu Seyahat Sigortası(Mesleki sorumluluk sigortasıdır.) " << endl;
				cout << "  - Panoramik Marakeş, Ouarzazate, Erfoud, Kazablanka, Fez, Rabat turları " << endl;
				cout << "  - Profesyonel Türkçe rehberlik " << endl;

				goto sefer11; // sefer 1 e 1

			}



			if (sec == 1)
			{

				float yetiskinfiyat = 4920, yetiskinkisisayisi, cocukfyat = 2915, cocuksayisi; // TUR ÜCRETİ İÇİN GİRİLEN DEĞERLER
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;
				cout << "  Yetişkin Fiyatı           : 4.920 TL  " << endl;
				cout << "  Çocuk Fiyatı (2- 11 Yaş ) : 2.915 TL  " << endl;
				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk :  " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;

				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;
				goto tursec;

			}



		}

		// ---- SEÇİM -1-2 ----

		if (sec == 2)  // seçim 1 / 2
		{
		sefer12:
		yanlis1:

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "     Kenya - Tanzanya Turu      " << endl;


			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;



			if (sec == 2)
			{
				goto anamenu;
			}

			if (sec == 3)
			{
				goto tursec;
			}

			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis;
			}


			if (sec == 9)
			{

				cout << "  Sefer Detayları : " << endl;
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;

				cout << "  1.Gün -->  İstanbul - Naırobı	" << endl;
				cout << "  2.Gün -->  Naırobı - Masaı Mara" << endl;
				cout << "  3.Gün -->  Masaı Mara" << endl;
				cout << "  4.Gün -->  Masaı Mara - Naırobı" << endl;
				cout << "  5.Gün -->  Naırobı - Zanzibar" << endl;
				cout << "  6.Gün -->  Zanzibar" << endl;
				cout << "  7.Gün -->  Zanzibar - İstanbul" << endl;


				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________" << endl;

				cout << "" << endl;

				cout << "  - Türk Hava Yolları ile İstanbul – Nairobi / Zanzibar– İstanbul arası ekonomi sınıf uçak bileti" << endl;
				cout << "  - Yerel Havayolları ile Nairobi – Zanzibar arası ekonomi sınıf uçak bileti" << endl;
				cout << "  - Havalimanı vergileri" << endl;
				cout << "  - Masai Mara’da 2 gece özel lodgelerda tam pansiyon konaklama" << endl;
				cout << "  - Nairobi’de 1 gece 4 yıldızlı otelde yarım pansiyon konaklama" << endl;
				cout << "  - Zanzibar’da 2 gece deniz kenarında 4 * otelde yarım pansiyon konaklama" << endl;
				cout << "  - Dünyaca ünlü Carnivore restaurantında öğle yemeği" << endl;
				cout << "  - Programda belirtilen tüm öğle yemekleri" << endl;
				cout << "  - Programda belirtilen tüm akşam yemekleri" << endl;
				cout << "  - Özel safari araçları ile programda belirtilen tüm safariler" << endl;
				cout << "  - Nairobi panoramik şehir turu" << endl;
				cout << "  - Ulusal Parklara giriş ücretleri" << endl;
				cout << "  - Türkçe rehberlik hizmetleri" << endl;
				cout << "  - Zorunlu Sigorta" << endl;


				goto sefer12; //sefer 1 e 2

			}


			if (sec == 1)
			{

				float yetiskinfiyat = 16650, yetiskinkisisayisi, cocukfyat = 8325, cocuksayisi;
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;
				cout << "  Yetişkin Fiyatı           : 16.650 TL  " << endl;
				cout << "  Çocuk Fiyatı (2- 11 Yaş ) :  8.325 TL  " << endl;
				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk : " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;

				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;
				goto tursec;


			}





		}

		// ---- SEÇİM -1-3 ----

		if (sec == 3) // seçim 1 / 3
		{
		sefer13:
		yanlis11:


			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "  3. Muhteşem Güney Afrika Turu    " << endl;


			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			if (sec == 2)
			{
				goto anamenu;
			}

			if (sec == 3)
			{
				goto tursec;
			}


			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis11;
			}


			if (sec == 9)
			{


				cout << "  Sefer Detayları : " << endl;
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;



				cout << "   1.Gün --> İstanbul Sabiha Gökçen - Doha " << endl;
				cout << "   2.Gün --> Doha-Cape Town" << endl;
				cout << "   3.Gün --> Cape Town" << endl;
				cout << "   4.Gün --> Cape Town" << endl;
				cout << "   5.Gün --> Cape Town" << endl;
				cout << "   6.Gün --> Cape Town - Johannesburg / Sun Cıty" << endl;
				cout << "   7.Gün --> Sun Cıty" << endl;
				cout << "   8.Gün --> Sun Cıty - Johannesburg" << endl;
				cout << "   9.Gün --> Johannesburg - Doha" << endl;
				cout << "  10.Gün --> Doha - İstanbul Sabiha Gökçen" << endl;



				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________" << endl;

				cout << "" << endl;


				cout << "  - Katar Havayolları ile İstanbul Sabiha Gökçen - Doha - Cape Town / Johannesburg - Doha - İstanbul Sabiha Gökçen arası ekonomi sınıf uçak bileti" << endl;
				cout << "  - Yerel Havayolları ile Cape Town - Johannesburg arası ekonomi sınıf iç hat uçak bileti" << endl;
				cout << "  - 4 gece Cape Town Radisson Blu Hotel & Residence'da oda kahvaltı konaklama" << endl;
				cout << "  - 2 gece Sun City Protea Hotel by Marriott Rustenburg Hunters Rest'de Yarım Pansiyon Konaklama" << endl;
				cout << "  - 1 gece Johannesburg Park Inn Sandton Hotel de oda kahvaltı konaklama" << endl;
				cout << "  - Cape Town Panoramik Şehir Turu" << endl;
				cout << "  - Johannesburg Panoramik Şehir Turu" << endl;
				cout << "  - Sun City Panoramik Tur" << endl;
				cout << "  - Programda belirtilen tüm transferler" << endl;
				cout << "  - Profesyonel Türkçe Tur Liderliği hizmeti" << endl;
				cout << "  - Havalimanı vergileri" << endl;
				cout << "  - Şehir vergileri" << endl;
				cout << "  - Zorunlu mesleki sigorta" << endl;



				goto sefer13; // sefer 1 e 3

			}


			if (sec == 1)
			{


				float yetiskinfiyat = 8350, yetiskinkisisayisi, cocukfyat = 4325, cocuksayisi;
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;
				cout << "  Yetişkin Fiyatı           :  8.350 TL  " << endl;
				cout << "  Çocuk Fiyatı (2- 11 Yaş ) :  4.325 TL  " << endl;
				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk :  " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;

				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;
				goto tursec;





			}
		}

	}

	// ---- SEÇİM -2 ----

	if (sec == 2) // seçim 2
	{




		cout << "   Amerika Turları   " << endl;
		cout << "____________________________________________________________________________" << endl;

		cout << "" << endl;

		cout << "  1. Miami - Orlando Turu                                              * (  7.500 TL )   ->  6 Gece -  7 Gün  " << endl;
		cout << "  2. New York - Las Vegas - San Francisco - Los Angeles Turu           * ( 25.190 TL )   -> 10 Gece - 11 Gün " << endl;
		cout << "  3. New York - Orlando - Miami                                        * ( 18.350 TL )   ->  8 Gece -  9 Gün " << endl;


		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;


		cout << " (Ana Menüye dönmek isterseniz 9 ' a basınız.)  \n \n  SEÇİMİNİZ : ";
		cin >> sec;




		if (sec == 9)
		{
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			goto anamenu;


		}

		// ---- SEÇİM -2-1 ----

		if (sec == 1) // seçim 2 / 1 
		{

		sefer21:
		yanlis2:

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "   Miami - Orlando Turu       " << endl;


			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			if (sec == 2)
			{
				goto anamenu;
			}


			if (sec == 3)
			{
				goto tursec;
			}


			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis2;
			}

			if (sec == 9)
			{

				cout << "  Sefer Detayları : " << endl;
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;


				cout << "        1.Gün  -->  İstanbul - Miami" << endl;
				cout << "  	2.Gün  -->  Miami" << endl;
				cout << "  	3.Gün  -->  Miami" << endl;
				cout << "  	4.Gün  -->  Miami - Orlando" << endl;
				cout << "  	5.Gün  -->  Orlando" << endl;
				cout << "  	6.Gün  -->  Orlando" << endl;
				cout << "  	7.Gün  -->  Orlando - Miami - İstanbul" << endl;




				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________   " << endl;

				cout << "" << endl;


				cout << "  - Türk Hava Yolu ile İstanbul – New York / Miami - İstanbul arası ekonomi sınıf uçak bileti " << endl;
				cout << "  - Amerikan İç Hatları ile New York - Orlando arası ekonomi sınıf uçak bileti " << endl;
				cout << "  - Havalimanı vergileri ve uçuş sigortaları " << endl;
				cout << "  - New York’ta 4 * Courtyard New York Manhattan / Herald Squaren veya benzeri otelde 2 gece oda bazında konaklama " << endl;
				cout << "  - Orlando'da 3* Holiday Inn Orlando SW Celebration veya benzeri otelde 3 gece oda bazında konaklama " << endl;
				cout << "  - Miami'de 3* Holiday Inn Miami West veya benzeri otelde 2 gece oda kahvaltı bazında konaklama " << endl;
				cout << "  - Havalimanı - Otel - Havalimanı transferleri " << endl;
				cout << "  - Resort Fee & Ayakbastı Parası " << endl;
				cout << "  - Tecrübeli rehberlik hizmeti " << endl;
				cout << "  - Zorunlu seyahat sigortası dahildir. " << endl;







				goto sefer21; // sefer 2 ye 1

			}


			if (sec == 1)
			{

				float yetiskinfiyat = 7500, yetiskinkisisayisi, cocukfyat = 3900, cocuksayisi;
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;

				cout << "  Yetişkin Fiyatı           : 7.500 TL  " << endl;
				cout << "  Çocuk Fiyatı (2- 11 Yaş ) : 3.900 TL  " << endl;
				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk :  " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;

				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;
				goto tursec;




			}



		}

		// ---- SEÇİM -2-2 ----

		if (sec == 2) // seçim 2 / 2
		{

		sefer22:
		yanlis3:

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "   New York - Las Vegas - San Francisco - Los Angeles Turu      " << endl;


			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			if (sec == 2)
			{
				goto anamenu;
			}


			if (sec == 3)
			{
				goto tursec;
			}

			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis3;
			}

			if (sec == 9)
			{

				cout << "  Sefer Detayları : " << endl;
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;


				cout << "  	 1.Gün  -->  İstanbul – San Francısco  " << endl;
				cout << "  	 2.Gün  -->  San Francısco  " << endl;
				cout << "  	 3.Gün  -->  San Francısco - Las Vegas  " << endl;
				cout << "  	 4.Gün  -->  Las Vegas  " << endl;
				cout << "  	 5.Gün  -->  Vegas - Los Angeles  " << endl;
				cout << "  	 6.Gün  -->  Los Angeles  " << endl;
				cout << "  	 7.Gün  -->  Los Angeles  " << endl;
				cout << "  	 8.Gün  -->  Los Angeles - New York  " << endl;
				cout << "    9.Gün  -->  New York  " << endl;
				cout << "   10.Gün  -->  New York  " << endl;
				cout << "  	11.Gün  -->  New York - İstanbul  " << endl;




				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________      " << endl;

				cout << "" << endl;



				cout << "  - Türk Hava Yolları ile İstanbul – San Francisco / New York - İstanbul arası ekonomi sınıf uçak bileti  " << endl;
				cout << "  - Los Angeles - New York arası ekonomi sınıf uçak bileti  " << endl;
				cout << "  - Havalimanı vergileri ve uçuş sigortaları  " << endl;
				cout << "  - San Francisco’da 3 * otelde 2 gece oda bazında konaklama  " << endl;
				cout << "  - Las Vegas’da 3 * otelde 2 gece oda bazında konaklama  " << endl;
				cout << "  - Los Angeles’da 3 * otelde 3 gece oda bazında konaklama  " << endl;
				cout << "  - New York’ta 3 * otelde 2 gece oda bazında konaklama  " << endl;
				cout << "  - New York Şehir turu ve ilk gün kahvaltısı  " << endl;
				cout << "  - Resort Fee ve şehir ayak bastı ücretleri  " << endl;
				cout << "  - Tüm transferler ve belirtilen şehir turları  " << endl;
				cout << "  - Tecrübeli Türkçe rehberlik hizmeti.  " << endl;


				goto sefer22; // sefer 2 ye 2

			}


			if (sec == 1)
			{


				float yetiskinfiyat = 25190, yetiskinkisisayisi, cocukfyat = 13900, cocuksayisi;
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;
				cout << "  Yetişkin Fiyatı           : 25.190 TL " << endl;
				cout << "  Çocuk Fiyatı (2- 11 Yaş ) : 13.900 TL  " << endl;
				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk :  " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;

				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;
				goto tursec;



			}




		}

		//  ---- SEÇİM -2-3 ----

		if (sec == 3) // seçim 2 / 3
		{

		sefer23:
		yanlis4:

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "   New York - Orlando - Miami     " << endl;


			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			if (sec == 2)
			{
				goto anamenu;
			}


			if (sec == 3)
			{
				goto tursec;
			}

			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis4;
			}

			if (sec == 9)
			{

				cout << "  Sefer Detayları : " << endl;
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;

				cout << "  	1.Gün  -->  İstanbul - Miami" << endl;
				cout << "  	2.Gün  -->  Miami" << endl;
				cout << "  	3.Gün  -->  Miami" << endl;
				cout << "  	4.Gün  -->  Miami - Orlando" << endl;
				cout << "  	5.Gün  -->  Orlando" << endl;
				cout << "  	6.Gün  -->  Orlando" << endl;
				cout << "  	7.Gün  -->  Orlando - Miami - İstanbul" << endl;




				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________" << endl;

				cout << "" << endl;

				cout << "  - Türk Hava Yolları ile İstanbul - Miami - İstanbul arası ekonomi sınıf uçak bileti" << endl;
				cout << "  - Miami'de Hampton Inn Miami Airport West vb otelde 3 gece oda kahvaltı bazında konaklama" << endl;
				cout << "  - Orlando'da Holiday Inn Orlando SW Celebration vb otelde 3 gece oda bazında konaklama" << endl;
				cout << "  - Resort Fee ve Ayak Bastı paraları" << endl;
				cout << "  - Tüm Transferler" << endl;
				cout << "  - Tur Liderliği Hizmeti" << endl;



				goto sefer23; // sefer 2 ye 3

			}


			if (sec == 1)
			{

				float yetiskinfiyat = 18350, yetiskinkisisayisi, cocukfyat = 9900, cocuksayisi;
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;

				cout << "  Yetişkin Fiyatı           :  18.350 TL TL " << endl;
				cout << "  Çocuk Fiyatı (2- 11 Yaş ) :   9.900 TL  " << endl;
				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk : " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;

				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;
				goto tursec;




			}

		}

	}
	// ---- SEÇİM -3 ----

	if (sec == 3)  // seçim 3
	{

	tursec3:

		cout << "  Orta Avrupa ve Almanya Turları" << endl;
		cout << "____________________________________________________________________________" << endl;

		cout << "" << endl;

		cout << "  1. Alman Harikaları                * ( 2.501 TL )   -> 4 Gece -  5 Gün  " << endl;
		cout << "  2. Polonya-Ukrayna Turu            * ( 4.378 TL )   -> 7 Gece -  8 Gün " << endl;



		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;


		cout << " (Ana Menüye dönmek isterseniz 9 ' a basınız.)  \n \n  SEÇİMİNİZ : ";
		cin >> sec;




		if (sec == 9)
		{
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			goto anamenu;


		}


		// ---- SEÇİM -3-1 ----

		if (sec == 1) // seçim 3 / 1
		{

		sefer31:
		yanlis5:

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "  Polonya-Ukrayna Turu       " << endl;


			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			if (sec == 2)
			{
				goto anamenu;
			}


			if (sec == 3)
			{
				goto tursec3;
			}


			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis5;
			}


			if (sec == 9)
			{

				cout << "  Sefer Detayları : " << endl;
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;

				cout << "  	1.Gün  -->  İstanbul - Hamburg(Lübeck)" << endl;
				cout << "  	2.Gün  -->  Hamburg - Bremen - Münster " << endl;
				cout << "  	3.Gün  -->  Münster(Giethoorn - Ootmarsum) " << endl;
				cout << "  	4.Gün  -->  Münster - Düsseldorf " << endl;
				cout << "  	5.Gün  -->  Düsseldorf - İstanbul " << endl;






				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________   " << endl;

				cout << "" << endl;



				cout << "  - Türk Hava Yolları tarifeli seferi ile İstanbul/Hamburg ve Dusseldorf/İstanbul hattında ekenomi sınıf uçak bileti " << endl;
				cout << "  - Havalimanı ve güvenlik vergileri" << endl;
				cout << "  - Havalimanı - Otel - Havalimanı transferler " << endl;
				cout << "  - Belirtilen otellerde veya benzerlerinde Hamburg'da 1 gece, Münster'de 2 gece ve Dusseldorf'ta 1 gece olmak üzere toplam 4 gece oda kahvaltı konaklama " << endl;
				cout << "  - Panoramik Hamburg, Bremen, Münster ve Düsseldorf şehir turları " << endl;
				cout << "  - Zorunlu Seyahat Sigortası* Mesleki Sorumluluk Sigortasıdır" << endl;
				cout << "  - Türkçe Rehberlik Hizmetleri " << endl;
				cout << "  - Tüm tur boyunca  PRONTOTOUR profesyonel Türkçe tur liderliği hizmeti" << endl;
				cout << "  - KDV Dahildir." << endl;




				goto sefer31; // sefer 3 e 1

			}


			if (sec == 1)
			{
				float yetiskinfiyat = 4378, yetiskinkisisayisi, cocukfyat = 2450, cocuksayisi;
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;
				cout << "  Yetişkin Fiyatı           : 4.378 TL  " << endl;
				cout << "  Çocuk Fiyatı (2- 11 Yaş ) : 2.450 TL  " << endl;
				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk :  " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;
				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;
				goto tursec3;





			}

		}

		// ---- SEÇİM -3-2 ----

		if (sec == 2) // seçim 3 / 2
		{

		sefer32:
		yanlis6:

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "  Polonya-Ukrayna Turu       " << endl;


			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			if (sec == 2)
			{
				goto anamenu;
			}

			if (sec == 3)
			{
				goto tursec3;
			}

			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis6;
			}

			if (sec == 9)
			{

				cout << "  Sefer Detayları : " << endl;
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;

				cout << "  	1.Gün  -->  Sabiha Gökçen - Lviv " << endl;
				cout << "  	2.Gün  -->  Lviv - Krakow " << endl;
				cout << "  	3.Gün  -->  Krakow " << endl;
				cout << "  	4.Gün  -->  Krakow - Wroclaw " << endl;
				cout << "  	5.Gün  -->  Wroclaw " << endl;
				cout << "  	6.Gün  -->  Wroclaw - Lodz - Varşova " << endl;
				cout << "  	7.Gün  -->  Varşova - Lublin - Lviv " << endl;
				cout << "  	8.Gün  -->  Lviv - İstanbul " << endl;






				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________   " << endl;

				cout << "" << endl;



				cout << "  - Pegasus Havayolları ile Sabiha Gökçen / Lviv / Sabiha Gökçen hattında ekonomi sınıf uçuş " << endl;
				cout << "  - Havalimanı vergileri " << endl;
				cout << "  - Belirtilen oteller ya da benzerlerinde Lviv 1, Krakow 2, Wroclaw 2, Varşova 1, Lviv 1 gece oda - kahvaltı konaklama " << endl;
				cout << "  - Havalimanı / otel / havalimanı transferleri " << endl;
				cout << "  - Lviv, Krakow, Wroclaw, Lodz, Varşova, Lublin Şehir Turları " << endl;
				cout << "  - Zorunlu Seyahat Sigortası " << endl;
				cout << "  - ürkçe Rehberlik Hizmetleri " << endl;




				goto sefer32; // sefer 3 e 2

			}


			if (sec == 1)
			{

				float yetiskinfiyat = 4378, yetiskinkisisayisi, cocukfyat = 2450, cocuksayisi;
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;
				cout << "  Yetişkin Fiyatı           : 4.378 TL  " << endl;
				cout << "  Çocuk Fiyatı (2- 11 Yaş ) : 2.450 TL  " << endl;
				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk : " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;

				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;
				goto tursec3;



			}
		}
	}
	// ---- SEÇİM -4 ----

	if (sec == 4)  // seçim 4
	{

	tursec4:


		cout << "  Orta Avrupa ve Almanya Turları" << endl;
		cout << "____________________________________________________________________________" << endl;

		cout << "" << endl;

		cout << "  1. Dubai Fly Dubai Turu            * ( 6.558 TL )   -> 3 Gece -  4 Gün  " << endl;



		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;


		cout << " (Ana Menüye dönmek isterseniz 9 ' a basınız.)  \n \n  SEÇİMİNİZ : ";
		cin >> sec;



		if (sec == 9)
		{
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			goto anamenu;


		}


		// ---- SEÇİM -4-1 ----

		if (sec == 1) // seçim 4 / 1
		{

		sefer41:
		yanlis7:

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "  Dubai Fly Dubai Turu       " << endl;




			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			if (sec == 2)
			{
				goto anamenu;
			}


			if (sec == 3)
			{
				goto tursec4;
			}

			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis7;
			}

			if (sec == 9)
			{

				cout << "  Sefer Detayları : " << endl;
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;

				cout << "  	1.Gün  -->  Sabiha Gökçen - Dubai  " << endl;
				cout << "  	2.Gün  -->	Dubai  " << endl;
				cout << "  	3.Gün  -->  Dubai " << endl;
				cout << "  	4.Gün  -->  Dubai - Sabiha Gökçen" << endl;

				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________   " << endl;

				cout << "" << endl;

				cout << "  - Flydubai Hava Yolları tarifeli seferleri ile Sabiha Gökçen HL(SAW) – Dubai(DXB) – Sabiha Gökçen HL(SAW) uçak bileti, " << endl;
				cout << "  - Havalimanı vergileri ve hizmetleri bedeli, " << endl;
				cout << "  - Havalimanı karşılama hizmeti ve havalimanı – otel – havalimanı transferleri " << endl;
				cout << "  - Belirtilen otelde toplam 3 gece oda kahvaltı konaklamalar, " << endl;
				cout << "  - Türkçe yerel rehberlik hizmeti(10 kişinin altında katılım olan turlarda ingilizce lokal rehberlik hizmeti sunulacaktır) " << endl;
				cout << "  - Öğle Yemekli Eski ve Yeni Dubai Turu(*içecekler hariç) " << endl;
				cout << "  - Öğle Yemekli Dubai Mall& Fountain Show Turu(*içecekler hariç) " << endl;
				cout << "  - Akşam Yemekli Çöl Safari Turu(soft içecekler dahil) " << endl;

				goto sefer41; // sefer 4 e 1

			}


			if (sec == 1)
			{





				float yetiskinfiyat = 6558, yetiskinkisisayisi, cocukfyat = 3450, cocuksayisi;
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;
				cout << "  Yetişkin Fiyatı           : 6.558 TL  " << endl;
				cout << "  Çocuk Fiyatı (2- 11 Yaş ) : 3.450 TL  " << endl;

				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk :  " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;

				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;
				goto tursec4;



			}
		}
	}

	// ---- SEÇİM -5 ----

	if (sec == 5)  // seçim5
	{

	tursec5:


		cout << "  Güney Afrika Turları " << endl;
		cout << "____________________________________________________________________________" << endl;

		cout << "" << endl;

		cout << "  1. Afrika Büyüsü; Güney Afrika - Victoria Şelaleleri - Botswana Turu   * ( 30.689 TL )   -> 9 Gece - 10 Gün  " << endl;
		cout << "  2. Süper Promo Güney Afrika                                            * (  8.789 TL )   -> 7 Gece -  9 Gün  " << endl;



		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;


		cout << " (Ana Menüye dönmek isterseniz 9 ' a basınız.)  \n \n  SEÇİMİNİZ : ";
		cin >> sec;



		if (sec == 9)
		{
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			goto anamenu;


		}


		// ---- SEÇİM -5-1 ----

		if (sec == 1) // seçim 5 / 1
		{

		sefer51:
		yanlis8:

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "  Afrika Büyüsü; Güney Afrika - Victoria Şelaleleri - Botswana Turu      " << endl;


			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			if (sec == 2)
			{
				goto anamenu;
			}


			if (sec == 3)
			{
				goto tursec5;
			}

			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis8;
			}

			if (sec == 9)
			{

				cout << "  Sefer Detayları : " << endl;
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;


				cout << "  	1.Gün -- >  İstanbul – Cape Town " << endl;
				cout << "  	2.Gün -- >  Cape Town ( Duike Adası –Chapman’s Peak – Boulders Penguen Plajı ) - Ümit Burnu " << endl;
				cout << "  	3.Gün -- >  Cape Town ( Masa Dağı – Franschhoek Kasabaları ) " << endl;
				cout << "  	4.Gün -- >  Cape Town – Aslan Parkı - Pilanesberg Milli Pakı " << endl;
				cout << "  	5.Gün -- >  Pilanesberg – Sun City – Pilanesberg ( Sabah Ve Akşam Safarisi ) " << endl;
				cout << "  	6.Gün -- >  Pilanesberg – Lesedi Kültür Köyü – Johannesburg " << endl;
				cout << "  	7.Gün -- >  Johannesburg – Victoria Şelaleleri " << endl;
				cout << "  	8.Gün -- >  Victoria Şelaleleri " << endl;
				cout << "  	9.Gün -- >  Victoria Şelaleleri – Botswana " << endl;
				cout << "  10.Gün -- >  Botswana – Johannesbourg – İstanbul " << endl;

				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________   " << endl;

				cout << "" << endl;

				cout << "  - Türk  Havayolları ile İstanbul / Cape Town, Johannesburgnesburg / İstanbul gidiş dönüş ekonomi sınıfı uçak bileti " << endl;
				cout << "  - Yerel Havayolları ile Cape Town / Victoria Falls uçak bileti " << endl;
				cout << "  - Yerel Hava Yolları ile Victoria Falls / Johannesburgnesbourg uçak bileti " << endl;
				cout << "  - Cape Town’da 4 yıldızlı otelde 3 gece oda kahvaltı konaklama " << endl;
				cout << "  - Cape Town’da lokal restoranda 1 Akşam yemeği " << endl;
				cout << "  - Tam gün Ümit Burnu turu(öğle yemeği dahil) " << endl;
				cout << "  - Tam gün Masa Dağı ve Şarap Bağları Turu(öğle yemeği dahil) " << endl;
				cout << "  - Victoria Falls’ta 4 * Otelde 2 gece oda kahvaltı konaklama " << endl;
				cout << "  - Victoria Falls’ta otelde öğle yemeği " << endl;
				cout << "  - Victoria Falls Şelaler Turu(öğle yemeği dahil) " << endl;
				cout << "  - Zambezi Nehri’nde tekne turu(limitsiz içki dahil) " << endl;
				cout << "  - Boma Dinner(Geleneksel Afrika Gecesi) Akşam yemeği " << endl;
				cout << "  - Botswana ‘da 1 gece 4 * Lodge’de kahvaltı dahil konaklama " << endl;
				cout << "  - Chobe Nehri’nde tekne safarisi " << endl;
				cout << "  - Chobe Milli Parkında sabah kara safarisi " << endl;
				cout << "  - Pilanesberg’de 1.sınıf Lodge de 2 gece yarım pansiyon konaklama(kahvaltı ve akşam yemeği dahil) " << endl;
				cout << "  - Pilanesberg Milli Parkı’nda sabah ve akşam safarisi " << endl;
				cout << "  - Sun City gezisi(öğle yemeği dahil) " << endl;
				cout << "  - Aslan Parkı Ziyareti " << endl;
				cout << "  - Lesedi Kültür Köyü Ziyareti(öğle yemeği dahil) " << endl;
				cout << "  - Johannesburgnesbourg’da 1 gece 4 * Otelde oda - kahvaltı konaklama " << endl;
				cout << "  - Tüm şehirler arası transferler. " << endl;
				cout << "  - Tur boyunca tecrübeli PRONTOPLUS Türkçe rehberlik hizmeti " << endl;
				cout << "  - Lokal rehberlik hizmetleri ve bahşişler " << endl;
				cout << "  - Zorunlu Seyahat sigortası " << endl;
				cout << "  - KDV " << endl;

				goto sefer51; // sefer 5 e 1

			}


			if (sec == 1)
			{



				float yetiskinfiyat = 30689, yetiskinkisisayisi, cocukfyat = 15450, cocuksayisi;
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;
				cout << "  Yetişkin Fiyatı            : 30.689 TL  " << endl;
				cout << "  Çocuk Fiyatı ( 2- 11 Yaş ) : 15.450 TL  " << endl;

				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk :  " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;

				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;
				goto tursec5;

			}
		}

		// ---- SEÇİM -5-2 ----

		if (sec == 2) // seçim 5 / 2
		{

		sefer52:
		yanlis9:

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			cout << "   Süper Promo Güney Afrika	        " << endl;


			cout << " ( Satın alma işlemi : 1 / Ana Menü :2 / Tur Seçim Menüsü : 3 / Tur detayları : 9 ) \n \n \n ";
			cout << "SEÇİMİNİZ : ";
			cin >> sec;

			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;

			if (sec == 2)
			{
				goto anamenu;
			}


			if (sec == 3)
			{
				goto tursec5;
			}

			if (sec != 1 && sec != 2 && sec != 3 && sec != 9)
			{
				cout << "( Hatalı Giriş Yaptınız! )" << endl;
				goto yanlis9;
			}

			if (sec == 9)
			{

				cout << "  Sefer Detayları : " << endl;
				cout << "____________________________________________________________________________" << endl;
				cout << "" << endl;
				cout << "  Kalkış İstanbul' dan yapılacaktır.  " << endl;
				cout << "" << endl;

				cout << "  	1.Gün -- >  İstanbul - Johannesburg " << endl;
				cout << "  	2.Gün -- >  Johannesburg " << endl;
				cout << "  	3.Gün -- >  Johannesburg " << endl;
				cout << "  	4.Gün -- >  Johannesburg - Cape Town " << endl;
				cout << "  	5.Gün -- >  Cape Town " << endl;
				cout << "  	6.Gün -- >  Cape Town " << endl;
				cout << "  	7.Gün -- >  Cape Town " << endl;
				cout << "  	8.Gün -- >  Cape Town - İstanbul " << endl;



				cout << "" << endl;

				cout << "   Seyahate Dahil Olan Hizmetler " << endl;
				cout << "____________________________________________________________________________   " << endl;

				cout << "" << endl;


				cout << "  - Türk Hava Yolları ile İstanbul – Johannesburg/ Cape Town– İstanbul arası ekonomi sınıf uçak bileti " << endl;
				cout << "  - Yerel Havayolları ile Johannesburg- Cape town parası ekonomi sınıf uçak bileti" << endl;
				cout << "  - Havalimanı vergileri " << endl;
				cout << "  - Johannesburg'da 4* otelde 3 gece oda+ kahvaltı konaklama" << endl;
				cout << "  - Cape Town'da 3* otelde 4 gece oda+ kahvaltı konaklama " << endl;
				cout << "  - Sabah kahvaltıları " << endl;
				cout << "  - Johannesburg ve Cape Town panoramik şehir turu " << endl;
				cout << "  - Johannesburgnesbourg’da 1 gece 4 * Otelde oda - kahvaltı konaklama " << endl;
				cout << "  - Tüm şehirler arası transferler. " << endl;
				cout << "  - Tur boyunca tecrübeli PRONTOPLUS Türkçe rehberlik hizmeti " << endl;
				cout << "  - Lokal rehberlik hizmetleri ve bahşişler " << endl;
				cout << "  - Zorunlu Seyahat sigortası " << endl;
				cout << "  - KDV " << endl;

				goto sefer52; // sefer 5 e 2

			}


			if (sec == 1)
			{

				float yetiskinfiyat = 8789, yetiskinkisisayisi, cocukfyat = 4450, cocuksayisi;
				cout << "____________________________________________________________________________" << endl; // FİYAT BİLGİLERİNİN GÖRÜNTÜLENMESİ.
				cout << "" << endl;
				cout << "  Fiyat Bilgisi :            " << endl;
				cout << "" << endl;
				cout << "  Yetişkin Fiyatı            : 8.789 TL  " << endl;
				cout << "  Çocuk Fiyatı ( 2- 11 Yaş ) : 4.450 TL  " << endl;


				cout << "" << endl;
				ucrethesaplama i;
				cout << " Fiyat Hesaplama Aracı ---> \n " << endl;
				cout << " Yetişkin Sayısı Giriniz : ";
				cin >> yetiskinkisisayisi;
				cout << " Çocuk Sayısı Giriniz : ";
				cin >> cocuksayisi;
				cout << " Yetişkin : " << yetiskinkisisayisi << " Kişi Ve Çocuk :  " << cocuksayisi << " Kişidir .. \n" << endl;

				cout << " Toplam Ücret : " << i.islemsonucu(yetiskinfiyat, yetiskinkisisayisi, cocukfyat, cocuksayisi) << " TL Değerini Vermektedir. " << endl;

				cout << "____________________________________________________________________________ \n\n\n" << endl;
				cout << " Tur Seçimine Geri Döndürüldünüz ... \n\n\n" << endl;


				goto tursec5;



			}
		}
	}


	system("pause");
	return 0;



}