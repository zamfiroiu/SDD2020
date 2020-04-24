//#include<stdio.h>
//#include<string>
//
//struct Copac {
//	int id;
//	char* locatie;
//	float inaltime;
//};
//
//struct Nod {
//	Copac info;
//	Nod* st;
//	Nod* dr;
//};
//
//Copac citireCopacDinFIsier(FILE* f) {
//	Copac c;
//	fscanf(f, "%d", &c.id);
//	char buffer[20];
//
//	fscanf(f, "%s", buffer);
//	c.locatie = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy(c.locatie, buffer);
//
//	fscanf(f, "%f", &c.inaltime);
//
//	return c;
//}
//
//
//Nod* inserareCopac(Nod* rad, Copac c) {
//	if (rad) {
//		if (c.id > rad->info.id) {
//			rad->dr = inserareCopac(rad->dr, c);
//		}
//		else if (c.id < rad->info.id) {
//			rad->st = inserareCopac(rad->st, c);
//		}
//		else {
//			throw "Id-ul exista deja";
//		}
//		return rad;
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = c;
//		nou->st = NULL;
//		nou->dr = NULL;
//		return nou;
//	}
//}
//
//void afisareCopac(Copac c) {
//	printf("%d. Copacul se aflasa in %s si are o inaltime %5.2f.\n ", c.id, c.locatie, c.inaltime);
//}
//
//void afisareArbore(Nod* rad) {
//	if (rad) {
//		afisareArbore(rad->st);
//		afisareCopac(rad->info);
//		afisareArbore(rad->dr);
//	}
//}
//
//void main() {
//	Nod* rad = NULL;
//	FILE* f = fopen("copaci.txt", "r");
//	if (f) {
//		while (!feof(f)) {
//			rad = inserareCopac(rad, citireCopacDinFIsier(f));
//		}
//		fclose(f);
//	}
//	else {
//		printf("Fisierul nu exista");
//	}
//
//	afisareArbore(rad);
//}