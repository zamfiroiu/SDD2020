//#include<stdio.h>
//#include<string>
//
//struct Oras {
//	char* denumire;
//	int nrLocuitori;
//	float suprafata;
//};
//
//Oras initOras(const char* denumire, int nrLocuirtori, float suprafata) {
//	Oras o;
//	o.denumire = (char*)malloc(sizeof(char)*(strlen(denumire) + 1));
//	strcpy(o.denumire, denumire);
//	o.nrLocuitori = nrLocuirtori;
//	o.suprafata = suprafata;
//
//	return o;
//}
//
//void afisareOras(Oras o) {
//	printf("Orasul %s are %d locuitori si %5.2f suprafata\n", o.denumire, o.nrLocuitori, o.suprafata);
//}
//
//struct Nod {
//	Oras info;
//	Nod* next;
//};
//
//void push(Nod*&stiva, Oras o) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = o;
//	nou->next = NULL;
//	if (stiva) {
//		Nod* p = stiva;
//		while (p->next) {
//			p = p->next;
//		}
//		p->next = nou;
//	}
//	else {
//		stiva = nou;
//	}
//}
//
//Oras pop(Nod* & stiva) {
//	if (stiva) {
//		Nod*p = stiva;
//		while (p->next && p->next->next) {
//			p = p->next;
//		}
//		if (p->next) {
//			Oras o = p->next->info;
//			free(p->next);
//			p->next = NULL;
//			return o;
//		}
//		else {
//			Oras o = p->info;
//			free(p);
//			stiva = NULL;
//			return o;
//		}
//	}
//	else {
//		throw "NU avem stiva";
//	}
//}
//
//
//int nrTotalLocuitori(Nod* &stiva) {
//	Nod*copie = NULL;
//	int nrTotal = 0;
//	while (stiva) {
//		Oras o = pop(stiva);
//		nrTotal += o.nrLocuitori;
//		push(copie, o);
//	}
//	while (copie) {
//		push(stiva, pop(copie));
//	}
//	return nrTotal;
//}
//
//void stergereOrasDupaNume(Nod*&stiva, const char* denumire) {
//	Nod* copie = NULL;
//	int ok = 1;
//	while (stiva && ok) {
//		Oras o = pop(stiva);
//		if (strcmp(o.denumire, denumire) == 0) {
//			free(o.denumire);
//			ok = 0;
//		}
//		else {
//			push(copie, o);
//		}
//	}
//	while (copie) {
//		push(stiva, pop(copie));
//	}
//}
//
//void afisareStiva(Nod* &stiva) {
//	while (stiva) {
//		afisareOras(pop(stiva));
//	}
//}
//
//void main() {
//	Nod* stiva = NULL;
//
//	push(stiva, initOras("Bucuresti", 2000, 450));
//	push(stiva, initOras("Craiova", 300, 23));
//	push(stiva, initOras("Cluj", 350, 34));
//
//	//afisareOras(pop(stiva));
//
//	printf("Numar total locuitori:%d", nrTotalLocuitori(stiva));
//	stergereOrasDupaNume(stiva, "Craiova");
//	afisareStiva(stiva);
//}
//
