//#include<stdio.h>
//#include<string>
//
//struct Stadion {
//	char* nume;
//	int capacitate;
//	int cod;
//};
//
//struct Nod{
//	Stadion info;
//	Nod* st;
//	Nod* dr;
//};
//
//Stadion citesteSadionDinFisier(FILE* f) {
//	Stadion s;
//	char aux[20];
//	fscanf(f, "%s", aux);
//	s.nume = (char*)malloc(sizeof(char)*(strlen(aux) + 1));
//	strcpy(s.nume, aux);
//	fscanf(f, "%d", &s.cod);
//	fscanf(f, "%d", &s.capacitate);
//
//	return s;
//}
//
//void afisareStadion(Stadion s) {
//	printf("%d. stadionul %s are o cpaacitate de %d\n", s.cod, s.nume, s.capacitate);
//}
//
//void insereazaInArbore(Nod*&rad, Stadion s) {
//	if (rad) {
//		if (rad->info.cod < s.cod) {
//			insereazaInArbore(rad->dr, s);
//		}
//		else if (rad->info.cod > s.cod) {
//			insereazaInArbore(rad->st, s);
//		}
//		else {
//			throw "Stadionul exista deja";
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
//Nod* citireArboreDeStadioane(const char*fileName) {
//	FILE* f = fopen(fileName, "r");
//	if (f) {
//		Nod* rad = NULL;
//		while (!feof(f)) {
//			Stadion s = citesteSadionDinFisier(f);
//			insereazaInArbore(rad, s);
//		}
//		fclose(f);
//		return rad;
//	}
//	else {
//		throw "Fisierul nu a putut fi deschis";
//	}
//}
//
//void afisareInordine(Nod*rad) {
//	if (rad) {
//		afisareInordine(rad->st);
//		afisareStadion(rad->info);
//		afisareInordine(rad->dr);
//	}
//}
//
//void main() {
//	Nod* arbore = NULL;
//	arbore = citireArboreDeStadioane("stadioane.txt");
//	afisareInordine(arbore);
//}