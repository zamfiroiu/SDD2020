//#include<stdio.h>
//#include<string>
//
//struct Serial {
//	char* nume;
//	int nrEpisoade;
//};
//
//struct Nod {
//	Serial info;
//	Nod* st;
//	Nod* dr;
//};
//
//Serial citireSerialDinFisiere(FILE* f) {
//	Serial s;
//	char aux[20];
//	fscanf(f, "%s", aux);
//	s.nume = (char*)malloc(sizeof(char)*(strlen(aux) + 1));
//	strcpy(s.nume, aux);
//	fscanf(f, "%d", &s.nrEpisoade);
//	return s;
//}
//
//void inserareSerialInArbore(Nod* &rad, Serial s) {
//	if (rad) {
//		if (strcmp(s.nume, rad->info.nume) < 0) {
//			inserareSerialInArbore(rad->st, s);
//		}
//		else if (strcmp(s.nume, rad->info.nume) > 0) {
//			inserareSerialInArbore(rad->dr, s);
//		}else{
//			throw "Serialul exista in arbore";
//		}
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = s;
//		nou->st = NULL;
//		nou->dr = NULL;
//		rad = nou;
//	}
//}
//
//Nod* citesteArboreDinFisier(const char* fileName) {
//	FILE* f = fopen(fileName, "r");
//	if (f) {
//		Nod*rad = NULL;
//		while (!feof(f)) {
//			Serial s = citireSerialDinFisiere(f);
//			inserareSerialInArbore(rad, s);
//		}
//		fclose(f);
//		return rad;
//	}
//	else {
//		throw "FIsierul nu a fost deschis";
//	}
//}
//
//void afisareArbore(Nod* rad) {
//	if (rad) {
//		afisareArbore(rad->st);
//		printf("%s are %d episoade.\n", rad->info.nume, rad->info.nrEpisoade);
//		afisareArbore(rad->dr);
//	}
//}
//
//void main() {
//
//	Nod* arbore = NULL;
//	try {
//		arbore = citesteArboreDinFisier("seriale.txt");
//	}
//	catch (char* exceptie) {
//		printf(exceptie);
//	}
//
//	afisareArbore(arbore);
//}