//#include<stdio.h>
//#include<string>
//
//struct Cinema {
//	int id;
//	char* nume;
//	int nrSali;
//};
//
//struct Nod {
//	Cinema info;
//	Nod*st;
//	Nod*dr;
//};
//
//Cinema citesteCinemaDinFisier(FILE* f) {
//	Cinema c;
//	fscanf(f, "%d", &c.id);
//	fscanf(f, "%d", &c.nrSali);
//	char aux[20];
//
//	fscanf(f, "%s", aux);
//	c.nume = (char*)malloc(sizeof(char)*(strlen(aux) + 1));
//	strcpy(c.nume, aux);
//
//	return c;
//}
//
//void inserareNodInArbore(Nod* &rad, Cinema c) {
//	if (rad) {
//		if (rad->info.id == c.id) {
//			throw "Cinema existent deja";
//		}
//		else {
//			if (rad->info.id > c.id) {
//				inserareNodInArbore(rad->st, c);
//			}
//			else {
//				inserareNodInArbore(rad->dr, c);
//			}
//		}
//	}
//	else {
//		Nod* frunza = (Nod*)malloc(sizeof(Nod));
//		frunza->info = c;
//		frunza->dr = NULL;
//		frunza->st = NULL;
//		rad = frunza;
//	}
//}
//
//Nod* citireAboreDinFisier(const char* fileName) {
//	FILE* f = fopen(fileName, "r");
//	if (f) {
//		Nod*arbore = NULL;
//		while (!feof(f)) {
//			Cinema c = citesteCinemaDinFisier(f);
//			inserareNodInArbore(arbore, c);
//		}
//		fclose(f);
//		return arbore;
//	}
//	else {
//		throw "Fisierul nu a fost deschis";
//	}
//
//}
//
//void afisareCinema(Cinema c) {
//	printf("%d. Cinema %s are %d sali\n", c.id, c.nume, c.nrSali);
//}
//
//void afisareArbore(Nod* rad) {
//	if (rad) {
//		afisareCinema(rad->info);
//		afisareArbore(rad->st);
//		
//		afisareArbore(rad->dr);
//	}
//}
//
//void main(){
//	Nod* arbore = citireAboreDinFisier("cinematografe.txt");
//	afisareArbore(arbore);
//}