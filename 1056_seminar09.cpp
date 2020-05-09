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
//Copac cautaCopacDupaID(Nod* rad, int id) {
//	if (rad) {
//		if (rad->info.id == id) {
//			return rad->info;
//		}
//		else if (rad->info.id > id) {
//			return cautaCopacDupaID(rad->st, id);
//		}
//		else {
//			return cautaCopacDupaID(rad->dr, id);
//		}
//	}
//	else {
//		throw "NU avem acest copac.";
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
//int inaltime(Nod* rad) {
//	if (rad) {
//		int hS = inaltime(rad->st);
//		int hD = inaltime(rad->dr);
//		int max = hS < hD ? hD : hS;
//		max++;
//		return max;
//	}else{
//		return 0;
//	}
//}
//
//int gradEchilibru(Nod* rad) {
//	if (rad) {
//		int hS = inaltime(rad->st);
//		int hD = inaltime(rad->dr);
//		return hS - hD;
//	}
//	else { return 0; }
//}
//
//void rotireStanga(Nod* &rad) {
//	Nod* temp = rad->dr;
//	rad->dr = temp->st;
//	temp->st = rad;
//	rad = temp;
//}
//
//void rotireDreapta(Nod*&rad) {
//	Nod* temp = rad->st;
//	rad->st = temp->dr;
//	temp->dr = rad;
//	rad = temp;
//}
//
//Nod* inserareCopacInAVL(Nod* rad, Copac c) {
//	if (rad) {
//		if (c.id > rad->info.id) {
//			rad->dr = inserareCopacInAVL(rad->dr, c);
//		}
//		else if (c.id < rad->info.id) {
//			rad->st = inserareCopacInAVL(rad->st, c);
//		}
//		else {
//			throw "Id-ul exista deja";
//		}
//
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
//		if (GE == 2) {
//			if (gradEchilibru(rad->st) == 1) {
//				rotireDreapta(rad);
//			}
//			else {
//				rotireStanga(rad->st);
//				rotireDreapta(rad);
//			}
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
//	printf("\n\n");
//	afisareCopac(cautaCopacDupaID(rad, 4));
//}