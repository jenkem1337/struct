#include <iostream>
#include<stdlib.h>

using namespace std;

typedef void (*AracDetay)(void *structPtr);
	
	typedef struct arac{
		int motorHacmi;
		float kuruAgirlik;
		float yakitTuketimi;
		AracDetay detayGetter;
		AracDetay detaySetter;
	
	} Arac;
	

	
	void setAracDetay(void *structPtr){
		
		Arac* self = (Arac*) structPtr;
		
		cout<<"Aracin bilgilerini giriniz: "<<endl;
		cout<<endl;
		int motorHacmi;
		float kuruAgirlik;
		float yakitTuketimi;
		
		cout<< "Aracin motor hacmini giriniz -> ";
		cin>>motorHacmi;
		
		cout<< "Aracin kuru agirligini giriniz  -> ";
		cin>> kuruAgirlik;
		
		cout<< "Aracin yakit tuketimini giriniz -> ";
		cin>> yakitTuketimi;
		
		self->motorHacmi = motorHacmi;
		self->yakitTuketimi = yakitTuketimi;
		self->kuruAgirlik = kuruAgirlik;
	}
	
	void getAracDetay(void *structPtr){
		
		Arac* self = (Arac*) structPtr;
		
		cout<<"Aracin bilgileri"<<endl;
		cout<<endl;
		cout<< "Aracin motor hacmi -> "<< self->motorHacmi <<endl;
		cout<< "Aracin kuru agirligi -> "<< 	self->kuruAgirlik <<endl;
		cout<< "Aracin yakit tuketimini -> "<<self->yakitTuketimi <<endl;
		
	}
	Arac *new_Arac(){
		Arac* arac =  ( Arac*) malloc(sizeof(Arac));
		arac->detaySetter = setAracDetay;
		arac->detayGetter = getAracDetay;
		return arac;
	}
	
	typedef struct motorsiklet{
		Arac *arac;
		
		AracDetay detayGetter;
		AracDetay detaySetter;
		
	} Motorsiklet;
	
	void setMotorsikletDetay(void *structPtr){
		
		Motorsiklet* self = (Motorsiklet*) structPtr;
		
		
		cout<<"Motorsikletin bilgilerini giriniz"<<endl;
		cout<<endl;
		int motorHacmi;
		float kuruAgirlik;
		float yakitTuketimi;
		
		cout<< "Motorsikletin motor hacmini giriniz -> ";
		cin>>motorHacmi;
		
		cout<< "Motorsikletin kuru agirligini giriniz  -> ";
		cin>> kuruAgirlik;
		
		cout<< "Motorsikletin yakit tuketimini giriniz -> ";
		cin>> yakitTuketimi;
		
		self->arac->motorHacmi = motorHacmi;
		self->arac->yakitTuketimi = yakitTuketimi;
		self->arac->kuruAgirlik = kuruAgirlik;
	}
	
	void getMotorsikletDetay(void *structPtr){
		
		Motorsiklet* self = (Motorsiklet*) structPtr;
		
		cout<< "Motorsiklet icin girilen bilgiler :"<<endl;
		cout<<endl;
		cout<< "Motorsikletin motor hacmi -> "<<      self->arac->motorHacmi <<endl;
		cout<< "Motorsikletin kuru agirligi -> "<< 	  self->arac->kuruAgirlik <<endl;
		cout<< "Motorsikletin yakit tuketimini -> "<< self->arac->yakitTuketimi <<endl;
		
	}

	void extend(Motorsiklet *motorsiklet, Arac* arac){
		motorsiklet->arac  = arac;
	}

	Motorsiklet *new_Motorsiklet(){
		
		Motorsiklet *motorsiklet = ( Motorsiklet*) malloc(sizeof(Motorsiklet));
		extend(motorsiklet, new_Arac());
		motorsiklet->detaySetter = setMotorsikletDetay;
		motorsiklet->detayGetter = getMotorsikletDetay;
		
		return motorsiklet;
	}
	
	
int main(int argc, char** argv) {
	
	
	Motorsiklet *motorsiklet = new_Motorsiklet();
	
	//motorsiklet->arac->detaySetter((Arac*)motorsiklet->arac);
	
	motorsiklet->detaySetter((Motorsiklet*)motorsiklet);
	
	cout<<endl;
		
	motorsiklet->detayGetter((Motorsiklet*)motorsiklet);
}


