//#include<stdio.h>
//#include<string>
//
//struct Hotel {
//	char* denumire;
//	int nrCamere;
//};
//
//struct Nod {
//	Hotel info;
//	Nod* st;
//	Nod* dr;
//};
//
//Hotel citesteHotelDinFisier(FILE* f) {
//	Hotel h;
//	char buffer[20];
//	fscanf(f, "%s", buffer);
//	h.denumire = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy(h.denumire, buffer);
//	fscanf(f, "%d", &h.nrCamere);
//	return h;
//}
//
//void afisareHotel(Hotel h) {
//	printf("%s are %d camere\n", h.denumire, h.nrCamere);
//}
//
//void inserareInArbore(Nod* &rad, Hotel h) {
//	if (rad==NULL) {
//		rad = (Nod*)malloc(sizeof(Nod));
//		rad->info = h;
//		rad->dr = NULL;
//		rad->st = NULL;
//	}
//	else {
//		if (strcmp(rad->info.denumire, h.denumire) > 0) {
//			inserareInArbore(rad->st, h);
//		}
//		else if (strcmp(rad->info.denumire, h.denumire) < 0) {
//			inserareInArbore(rad->dr, h);
//		}
//		else {
//			throw "Hotelul deja exista";
//		}
//	}
//}
//
//Nod* citireArboreDinFisier(const char* fileName) {
//	FILE* f = fopen(fileName, "r");
//	if (f) {
//		Nod* rad = NULL;
//		while (!feof(f)) {
//			inserareInArbore(rad, citesteHotelDinFisier(f));
//		}
//		fclose(f);
//		return rad;
//	}
//	else {
//		throw "Fisierul nu a putut fi deschis.";
//	}
//}
//
//void afisareArboreHoteluri(Nod* rad) {
//	if(rad){
//		afisareArboreHoteluri(rad->st);
//		afisareHotel(rad->info);
//		afisareArboreHoteluri(rad->dr);
//	}
//}
//
//void main() {
//	Nod* radacina = NULL;
//	radacina = citireArboreDinFisier("hoteluri.txt");
//	afisareArboreHoteluri(radacina);
//}