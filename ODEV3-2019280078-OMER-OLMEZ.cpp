#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	
	// 2019280078-�MER �LMEZ
	
	ifstream dosyaOku;
	dosyaOku.open("input.txt");
	int dongu = 0 , sub = 0;
	string dogruCevaplar,ogrenciCevaplar;
	int soruSayisi;
	double ortalama=0;
	int kontrol = 0 ,sinir =0;
	string oku,oku1;
	string ogrenciNo[101];
	double ogrenciPuan[101];
	fstream dosyaYaz;
	dosyaYaz.open("output.txt",ios::out | ios::in | ios::app);
	
	// �lk olarak maksimum 100 ki�i olaca�� i�in bunun kontrol�n� yap�yoruz
	while(getline(dosyaOku,oku1))
	{
		sinir++;
	}
	dosyaOku.close();
	
	if(sinir < 103)

{
// Soru say�s�n� ve do�ru cevaplar� de�i�kenlere at�yoruz.
dosyaOku.open("input.txt");
	while(getline(dosyaOku,oku))
	{
		dongu++;
		kontrol = oku.length();
		ogrenciPuan[dongu-2] = 0;
		if(dongu == 1) 
		{
			soruSayisi = atoi(oku.c_str());
			dogruCevaplar[soruSayisi];
			
		}
		if(dongu == 2)
		{
			for(int i = 0; i < soruSayisi; i++)
			{
				dogruCevaplar[i] = oku[sub];
				sub = sub + 2;
			}
		}
		
		if(dongu > 2)
		{
			// Sat�r sat�r verileri okuyup ��rencinin verdi�i cevap ile cevap anahtar�n� kar��la�t�r�p puanlamas�n� yap�yoruz.
			ogrenciNo[dongu-3] = oku.substr(0,9);
			sub = 10;
			for(int j = 0; j < soruSayisi; j++)
			{
			
				ogrenciCevaplar[j] = oku[sub];
				sub = sub + 2;
				
				// Son sorunun bo� olup olmad���n� kontrol ediyoruz.
				if((oku[kontrol-1] == ',' ) && (j == soruSayisi -1)) 
				{
					
				}
				else {
				
				
				if(ogrenciCevaplar[j] == ',')
				{
					sub = sub - 1;
					
				}
				 
			
				if((dogruCevaplar[j] == ogrenciCevaplar[j]) && (ogrenciCevaplar[j] != ' ') && (ogrenciCevaplar[j] != ',') )
				{
					ogrenciPuan[dongu-3]= ogrenciPuan[dongu-3] + 4;
					
			
				}
				else if((dogruCevaplar[j] != ogrenciCevaplar[j] )&& (ogrenciCevaplar[j] != ' ') && (ogrenciCevaplar[j] != ',') )
				{
					ogrenciPuan[dongu-3] = ogrenciPuan[dongu-3] - 1;
				}
				
			}
		}
						//Puan 0'dan k���k ise 0'a e�itliyoruz.
						if(ogrenciPuan[dongu-3] < 0) ogrenciPuan[dongu-3] = 0;
						//Ortalamay� hesapl�yoruz.
						ortalama = ortalama + ogrenciPuan[dongu-3];
		}
		
}	
			//BubbleSort algoritmas�n� kullanarak notlar� b�y�kten k����e ayn� zamanda ��renci numaralar�n�da notlara g�re s�ral�yoruz.
			 double temp;
			 string temp1;
			 for(int a =0; a < (dongu-3); a++)
			 {
			 	for(int b=0; b < ((dongu-2)-a-1); b++)
			 	{
			 		if(ogrenciPuan[b]>ogrenciPuan[b+1])
			 		{
			 			temp = ogrenciPuan[b];
			 			temp1 = ogrenciNo[b];
			 			ogrenciPuan[b] = ogrenciPuan[b+1];
			 			ogrenciNo[b] = ogrenciNo[b+1];
			 			ogrenciPuan[b+1] = temp;
			 			ogrenciNo[b+1] = temp1;
					 }
				 }
			 }
	  int c = 0, d = 0;
	  int medyan,medyanhesap;
	
	  c = dongu -3;
	  //Medyan hesaplamas�n� yapmak i�in ��renci say�s�n�n �ift yada tek oldu�unu hesaplay�p ona g�re medyan� buluyoruz.
	  if((dongu - 2)%2 == 0)
	  {
	  	medyanhesap = (dongu - 2)/2;
	  	medyan = ogrenciPuan[medyanhesap-1];
	  	medyanhesap = ((dongu - 2)/2)+1;
	  	medyan = medyan + ogrenciPuan[medyanhesap-1];
	  	medyan = medyan / 2;
	  }
	  else
	  {
	  	medyan = ((dongu-2)+1)/2-1;
	  }
	  for(c = dongu - 3; c >= 0; c--)
	  {
	  	//��rencilerin puanlar�n� ��renci numaras�yla birlikte yazd�r�yoruz. Ayn� zamanda 100'e normalize etmek i�in 2.5 ile �arp�yoruz.
	  	cout << ogrenciNo[c]<<","<<ogrenciPuan[c]*2.5<<endl;
	  	dosyaYaz <<ogrenciNo[c]<<","<<ogrenciPuan[c]*2.5<<endl;
	  }
	
		cout << ogrenciPuan[dongu-3]*2.5<<","<< ogrenciPuan[0]*2.5<<","<<((ortalama/(dongu-2)))*2.5<<","<<medyan*2.5<<","<<(ogrenciPuan[dongu-3]-ogrenciPuan[0])*2.5<<endl;
		dosyaYaz << ogrenciPuan[dongu-3]*2.5<<","<< ogrenciPuan[0]*2.5<<","<<((ortalama/(dongu-2)))*2.5<<","<<medyan*2.5<<","<<(ogrenciPuan[dongu-3]-ogrenciPuan[0])*2.5<<endl;
	




	dosyaOku.close();
	dosyaYaz.close();
	return 0;
}
else
{
	cout <<"Lutfen Maksimum 100 Kisi Giriniz" << endl;
}	
}

//BU �DEV YAPIMINDA QU�Z-2'DE KULLANDI�IM BUBBLE SORT ALGOR�TMASINDAN KAYNAK ALDIM.ONUN HAR�C�NDE HERHANG� B�R KAYNAKTAN YAPILMAMI�TIR.
//B�T�N ALGOR�TMA VE KODLAR BANA A�TT�R.


