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
//	printf("%d. stadionul %s are o capacitate de %d\n", s.cod, s.nume, s.capacitate);
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
//
//
//void afisareInordine(Nod*rad) {
//	if (rad) {
//		afisareInordine(rad->st);
//		afisareStadion(rad->info);
//		afisareInordine(rad->dr);
//	}
//}
//
//Stadion cautareInArboreDupaCod(Nod* rad, int cod) {
//	if (rad) {
//		if (rad->info.cod < cod) {
//			return cautareInArboreDupaCod(rad->dr, cod);
//		}
//		else if (rad->info.cod > cod) {
//			return cautareInArboreDupaCod(rad->st, cod);
//
//		}
//		else {
//			return rad->info;
//		}
//	}
//	else {
//		throw "Stadionul cu acst cod nu exista";
//	}
//}
//
//int inaltimeArbore(Nod* rad) {
//	if (rad) {
//		int hs = inaltimeArbore(rad->st);
//		int hd = inaltimeArbore(rad->dr);
//		int max = 1+(hs > hd ? hs : hd);
//		return max;
//	}
//	else {
//		return 0;
//	}
//}
//
//int gradEchilibru(Nod* rad) {
//	if (rad) {
//		return inaltimeArbore(rad->st) - inaltimeArbore(rad->dr);
//	}
//	else {
//		return 0;
//	}
//}
//
//void rotireStanga(Nod*rad) {
//	Nod*temp = rad->dr;
//	rad->dr = temp->st;
//	temp->st = rad;
//	rad = temp;
//}
//
//void rotireDreapta(Nod* rad) {
//	Nod*temp = rad->st;
//	rad->st = temp->dr;
//	temp->dr = rad;
//	rad = temp;
//}
//
//void insereazaInArboreAVL(Nod*&rad, Stadion s) {
//	if (rad) {
//		if (rad->info.cod < s.cod) {
//			insereazaInArboreAVL(rad->dr, s);
//		}
//		else if (rad->info.cod > s.cod) {
//			insereazaInArboreAVL(rad->st, s);
//		}
//		else {
//			throw "Stadionul exista deja";
//		}
//		int GE = gradEchilibru(rad);
//		if (GE == -2) {
//			if (gradEchilibru(rad->dr) == -1) {
//				rotireStanga(rad);
//			}
//			else {
//				rotireDreapta(rad->dr);
//				rotireStanga(rad);
//			}
//		}
//		else if (GE == 2) {
//			if (gradEchilibru(rad->st) != 1) {
//				rotireDreapta(rad);
//			}
//			else {
//
//			}
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
//			insereazaInArboreAVL(rad, s);
//		}
//		fclose(f);
//		return rad;
//	}
//	else {
//		throw "Fisierul nu a putut fi deschis";
//	}
//}
//void main() {
//	Nod* arbore = NULL;
//	arbore = citireArboreDeStadioane("stadioane.txt");
//	afisareInordine(arbore);
//
//	afisareStadion(cautareInArboreDupaCod(arbore, 4));
//}