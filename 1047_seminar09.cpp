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
//int inaltimeArbore(Nod* rad) {
//	if (!rad) {
//		return 0;
//	}
//	else {
//		int hd = inaltimeArbore(rad->dr);
//		int hs = inaltimeArbore(rad->st);
//		return 1 + (hs < hd ? hd : hs);
//	}
//}
//
//int calculGradEchilibru(Nod* rad) {
//	if (rad) {
//		return inaltimeArbore(rad->st) - inaltimeArbore(rad->dr);
//	}
//	else { return 0; }
//}
//
//
//Nod* rotireStanga(Nod* rad) {
//	Nod* temp = rad->dr;
//	rad->dr = temp->st;
//	temp->st = rad;
//	return temp;
//}
//
//Nod* rotireDreapta(Nod* rad) {
//	Nod* temp = rad->st;
//	rad->st = temp->dr;
//	temp->dr = rad;
//	return temp;
//}
//
//void inserareSerialInArboreAVL(Nod* &rad, Serial s) {
//	if (rad) {
//		if (strcmp(s.nume, rad->info.nume) < 0) {
//			inserareSerialInArboreAVL(rad->st, s);
//		}
//		else if (strcmp(s.nume, rad->info.nume) > 0) {
//			inserareSerialInArboreAVL(rad->dr, s);
//		}
//		else {
//			throw "Serialul exista in arbore";
//		}
//		int GE = calculGradEchilibru(rad);
//		if (GE == -2) {
//			if (calculGradEchilibru(rad->dr) == -1) {
//				rad = rotireStanga(rad);
//			}
//			else {
//				rad->dr = rotireDreapta(rad->dr);
//				rad = rotireStanga(rad);
//			}
//		}else if (GE == 2) {
//			if (calculGradEchilibru(rad->st) != 1) {
//				rad->st = rotireStanga(rad->st);
//			}
//			rad = rotireDreapta(rad);
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
//			inserareSerialInArboreAVL(rad, s);
//		}
//		fclose(f);
//		return rad;
//	}
//	else {
//		throw "FIsierul nu a fost deschis";
//	}
//}
//
//void afisareSerial(Serial s) {
//	printf("%s are %d episoade.\n", s.nume, s.nrEpisoade);
//}
//
//void afisareArbore(Nod* rad) {
//	if (rad) {
//		afisareArbore(rad->st);
//		afisareSerial(rad->info);
//		afisareArbore(rad->dr);
//	}
//}
//
//Serial cautareSerialDupaNume(Nod* rad, const char* nume) {
//	if (rad) {
//		if (strcmp(nume, rad->info.nume) < 0) {
//			return cautareSerialDupaNume(rad->st, nume);
//		}
//		else if (strcmp(nume, rad->info.nume) > 0) {
//			return cautareSerialDupaNume(rad->dr, nume);
//		}
//		else {
//			return rad->info;
//		}
//	}
//	else {
//		throw "Serialul nu exista";
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
//
//	printf("Seral cautat: ");
//	afisareSerial(cautareSerialDupaNume(arbore, "Narcos"));
//}