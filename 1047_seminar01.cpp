//#include<stdio.h>
//#include<string>
//
//struct Hotel {
//	char* nume;
//	int nrCamere;
//	float pretNoapte;
//};
//
//Hotel initializareHotel(const char* nume, int nrCamere, float pretNoapte) {
//	Hotel h;
//	//h.nume = new char[strlen(nume) + 1];
//	h.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(h.nume, nume);
//	h.nrCamere = nrCamere;
//	h.pretNoapte = pretNoapte;
//	return h;
//}
//
//void afisareHotel(Hotel h) {
//	printf("Hotelul %s are %d camere la un pret pe noapte de %5.2f RON.\n",
//		h.nume, h.nrCamere, h.pretNoapte);
//}
//
//
////nu merge
////nu este corecta
////trebuie modificata
//void adaugareHotelinVector(Hotel* v, int nrHoteluri, Hotel h) {
//	Hotel*copie = (Hotel*)malloc(sizeof(Hotel)*(nrHoteluri + 1));
//	for (int i = 0; i < nrHoteluri; i++) {
//		copie[i] = v[i];
//	}
//	copie[nrHoteluri] = h;
//	free(v);
//	v = copie;
//	nrHoteluri = 4;
//}
//
//void main() {
//	Hotel hotel;
//	hotel = initializareHotel("Sheraton", 20, 100);
//	afisareHotel(hotel);
//
//	free(hotel.nume);
//
//	Hotel * ph;
//	ph = (Hotel*)malloc(sizeof(Hotel));
//	*ph = initializareHotel("RadissonBlue", 22, 150);
//	afisareHotel(*ph);
//
//	free((*ph).nume);//free(ph->nume);
//	free(ph);
//
//	Hotel* vh;
//	int nrHoteluri = 3;
//	vh = (Hotel*)malloc(sizeof(Hotel)*nrHoteluri);
//	for (int i = 0; i < nrHoteluri; i++) {
//		vh[i] = initializareHotel("Hilton", (i + 1) * 5, (i + 1) * 100);
//	}
//
//	for (int i = 0; i < nrHoteluri; i++) {
//		afisareHotel(*(vh + i));//afisareHotel(vh[i]);
//	}
//
//	for (int i = 0; i < nrHoteluri; i++) {
//		free(vh[i].nume);
//	}
//
//	free(vh);
//
//	Hotel** vph;
//	int nrPointeri = 5;
//	vph = (Hotel**)malloc(sizeof(Hotel*)*nrPointeri);
//	for (int i = 0; i < nrPointeri; i++) {
//		vph[i] = (Hotel*)malloc(sizeof(Hotel));
//		*(vph[i]) = initializareHotel("Intercontinental", i * 10, i * 200);
//	}
//
//	for (int i = 0; i < nrPointeri; i++) {
//		afisareHotel(*vph[i]);
//	}
//
//	for (int i = 0; i < nrPointeri; i++) {
//		free((*vph[i]).nume);
//		free(vph[i]);
//	}
//	free(vph);
//
//
//
//		
//}