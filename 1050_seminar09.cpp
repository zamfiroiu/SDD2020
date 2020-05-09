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
//Cinema cautareCinemaInArbore(Nod* rad, int id) {
//	if (rad) {
//		if (rad->info.id > id) {
//			return cautareCinemaInArbore(rad->st, id);
//		}
//		else if (rad->info.id < id) {
//			return cautareCinemaInArbore(rad->dr, id);
//		}
//		else {
//			return rad->info;
//		}
//	}
//	else {
//		throw "Cinematgraful nu exista";
//	}
//}
//
//int inaltimeArbore(Nod* rad) {
//	if (rad) {
//		int hs = inaltimeArbore(rad->st);
//		int hd = inaltimeArbore(rad->dr);
//		return 1 + (hs < hd ? hs : hd);
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
//
//	//return rad ? inaltimeArbore(rad->st) - inaltimeArbore(rad->dr) : 0;
//}
//
//void rotireStanga(Nod* &rad) {
//	Nod* temp = rad->dr;
//	rad->dr = temp->st;
//	temp->st = rad;
//	rad = temp;
//}
//
//void rotireDreapta(Nod* &rad) {
//	Nod* temp = rad->st;
//	rad->st = temp->dr;
//	temp->dr = rad;
//	rad = temp;
//}
//
//
//
//void inserareNodInArboreAVL(Nod* &rad, Cinema c) {
//	if (rad) {
//		if (rad->info.id == c.id) {
//			throw "Cinema existent deja";
//		}
//		else {
//			if (rad->info.id > c.id) {
//				inserareNodInArboreAVL(rad->st, c);
//			}
//			else {
//				inserareNodInArboreAVL(rad->dr, c);
//			}
//		}
//		int GE = gradEchilibru(rad);
//		if (GE == -2) {
//			if (gradEchilibru(rad->dr)==-1) {
//				rotireStanga(rad);
//			}
//			else {
//				rotireDreapta(rad->dr);
//				rotireStanga(rad);
//			}
//		}
//		if (GE == 2) {
//			if (gradEchilibru(rad->st) != 1) {
//				rotireStanga(rad->st);
//			}
//			rotireDreapta(rad);
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
//
//Nod* citireAboreDinFisier(const char* fileName) {
//	FILE* f = fopen(fileName, "r");
//	if (f) {
//		Nod*arbore = NULL;
//		while (!feof(f)) {
//			Cinema c = citesteCinemaDinFisier(f);
//			inserareNodInArboreAVL(arbore, c);
//		}
//		fclose(f);
//		return arbore;
//	}
//	else {
//		throw "Fisierul nu a fost deschis";
//	}
//
//}
//void main(){
//	Nod* arbore = citireAboreDinFisier("cinematografe.txt");
//	afisareArbore(arbore);
//	printf("cinematograf cautat:");
//	afisareCinema(cautareCinemaInArbore(arbore, 5));
//}