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
//
//void afisareArboreHoteluri(Nod* rad) {
//	if(rad){
//		afisareArboreHoteluri(rad->st);
//		afisareHotel(rad->info);
//		afisareArboreHoteluri(rad->dr);
//	}
//}
//
//int calculareInaltime(Nod* rad) {
//	if (rad) {
//		int hs = calculareInaltime(rad->st);
//		int hd = calculareInaltime(rad->dr);
//		int max = (hs < hd ? hd : hs);
//		max++;
//		return max;
//	}
//	else {
//		return 0;
//	}
//}
//
//int calculGradEchilibru(Nod* rad) {
//	if (rad) {
//		return calculareInaltime(rad->st) - calculareInaltime(rad->dr);
//	}
//	else {
//		return 0;
//	}
//}
//
//Hotel cautareHotelDupaNume(Nod* rad, const char* denumire) {
//	if (rad) {
//		if (strcmp(rad->info.denumire, denumire)==0) {
//			return rad->info;
//		}
//		else if (strcmp(rad->info.denumire, denumire) < 0) {
//			return cautareHotelDupaNume(rad->dr, denumire);
//		}
//		else {
//			return cautareHotelDupaNume(rad->st, denumire);
//		}
//	}
//	else {
//		throw "Hotel inexistent";
//	}
//}
//
//void rotireStanga(Nod* & rad) {
//	Nod*temp = rad->dr;
//	rad->dr = temp->st;
//	temp->st = rad;
//	rad = temp;
//}
//
//void rotireDreapta(Nod* & rad) {
//	Nod*aux = rad->st;
//	rad->st = aux->dr;
//	aux->dr = rad;
//	rad = aux;
//}
//
//
//void inserareInArboreAVL(Nod* &rad, Hotel h) {
//	if (rad == NULL) {
//		rad = (Nod*)malloc(sizeof(Nod));
//		rad->info = h;
//		rad->dr = NULL;
//		rad->st = NULL;
//	}
//	else {
//		if (strcmp(rad->info.denumire, h.denumire) > 0) {
//			inserareInArboreAVL(rad->st, h);
//		}
//		else if (strcmp(rad->info.denumire, h.denumire) < 0) {
//			inserareInArboreAVL(rad->dr, h);
//		}
//		else {
//			throw "Hotelul deja exista";
//		}
//
//		int GE = calculGradEchilibru(rad);
//		if (GE == -2) {
//			if (calculGradEchilibru(rad->dr) == -1) {
//				rotireStanga(rad);
//			}
//			else {
//				rotireDreapta(rad->dr);
//				rotireStanga(rad);
//			}
//		}
//		else if (GE == 2) {
//			if (calculGradEchilibru(rad->st) == -1) {
//				rotireStanga(rad->st);
//			}
//			rotireDreapta(rad);
//		}
//	}
//}
//
//
//Nod* citireArboreDinFisier(const char* fileName) {
//	FILE* f = fopen(fileName, "r");
//	if (f) {
//		Nod* rad = NULL;
//		while (!feof(f)) {
//			inserareInArboreAVL(rad, citesteHotelDinFisier(f));
//		}
//		fclose(f);
//		return rad;
//	}
//	else {
//		throw "Fisierul nu a putut fi deschis.";
//	}
//}
//
//void main() {
//	Nod* radacina = NULL;
//	radacina = citireArboreDinFisier("hoteluri.txt");
//	afisareArboreHoteluri(radacina);
//
//	try {
//		afisareHotel( cautareHotelDupaNume(radacina,"Ramada"));
//	}
//	catch (...) {
//		printf("Am pimit exceptie");
//	}
//
//}