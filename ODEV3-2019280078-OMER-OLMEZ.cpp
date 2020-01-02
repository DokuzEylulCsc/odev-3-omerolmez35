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
	
	
	// 2019280078-ÖMER ÖLMEZ
	
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
	
	// Ýlk olarak maksimum 100 kiþi olacaðý için bunun kontrolünü yapýyoruz
	while(getline(dosyaOku,oku1))
	{
		sinir++;
	}
	dosyaOku.close();
	
	if(sinir < 103)

{
// Soru sayýsýný ve doðru cevaplarý deðiþkenlere atýyoruz.
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
			// Satýr satýr verileri okuyup öðrencinin verdiði cevap ile cevap anahtarýný karþýlaþtýrýp puanlamasýný yapýyoruz.
			ogrenciNo[dongu-3] = oku.substr(0,9);
			sub = 10;
			for(int j = 0; j < soruSayisi; j++)
			{
			
				ogrenciCevaplar[j] = oku[sub];
				sub = sub + 2;
				
				// Son sorunun boþ olup olmadýðýný kontrol ediyoruz.
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
						//Puan 0'dan küçük ise 0'a eþitliyoruz.
						if(ogrenciPuan[dongu-3] < 0) ogrenciPuan[dongu-3] = 0;
						//Ortalamayý hesaplýyoruz.
						ortalama = ortalama + ogrenciPuan[dongu-3];
		}
		
}	
			//BubbleSort algoritmasýný kullanarak notlarý büyükten küçüðe ayný zamanda öðrenci numaralarýnýda notlara göre sýralýyoruz.
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
	  //Medyan hesaplamasýný yapmak için öðrenci sayýsýnýn çift yada tek olduðunu hesaplayýp ona göre medyaný buluyoruz.
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
	  	//Öðrencilerin puanlarýný öðrenci numarasýyla birlikte yazdýrýyoruz. Ayný zamanda 100'e normalize etmek için 2.5 ile çarpýyoruz.
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

//BU ÖDEV YAPIMINDA QUÝZ-2'DE KULLANDIÐIM BUBBLE SORT ALGORÝTMASINDAN KAYNAK ALDIM.ONUN HARÝCÝNDE HERHANGÝ BÝR KAYNAKTAN YAPILMAMIÞTIR.
//BÜTÜN ALGORÝTMA VE KODLAR BANA AÝTTÝR.


