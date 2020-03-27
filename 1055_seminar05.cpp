//#include<stdio.h>
//#include<string>
//
//struct Angajat {
//	char* nume;
//	float salariu;
//	int marca;
//};
//
//struct Nod {
//	Angajat info;
//	Nod*next;
//	Nod*prev;
//};
//
//struct ListaDubla {
//	Nod* first;
//	Nod* last;
//};
//
//Angajat initAngajat(const char* nume, float salaru, int marca) {
//	Angajat a;
//	a.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(a.nume, nume);
//	a.salariu = salaru;
//	a.marca = marca;
//	return a;
//}
//
//void afisareAngajat(Angajat a) {
//	printf("Angajatul %s are salariu %5.2f si marca %d.\n", a.nume, a.salariu, a.marca);
//}
//
//void inserareLaInceput(ListaDubla &lista, Angajat a) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = a;
//	nou->next = lista.first;
//	nou->prev = NULL;
//	if (lista.first) {
//		lista.first->prev = nou;
//		lista.first = nou;
//	}
//	else {
//		lista.first = nou;
//		lista.last = nou;
//	}
//}
//
//void afisareLista(ListaDubla lista) {
//	for (Nod*p = lista.first; p; p = p->next) {
//		afisareAngajat(p->info);
//	}
//}
//
//void afisareListaSfarsitInceput(ListaDubla lista) {
//	Nod* p = lista.last;
//	while (p) {
//		afisareAngajat(p->info);
//		p = p->prev;
//	}
//}
//
//void stergereLista(ListaDubla& lista) {
//	while (lista.first) {
//		free(lista.first->info.nume);
//		Nod* temp = lista.first;
//		lista.first = lista.first->next;
//		free(temp);
//	}
//	lista.last = NULL;
//}
//
//void inserareLaSfarsit(ListaDubla & lista, Angajat a) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = a;
//	nou->next = NULL;
//	nou->prev = lista.last;
//	if (lista.last) {
//		lista.last->next = nou;
//		lista.last = nou;
//	}
//	else {
//		lista.first = nou;
//		lista.last = nou;
//	}
//}
//
//void main() {
//
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//
//	inserareLaSfarsit(lista, initAngajat("Popescu", 4000, 1234));
//	inserareLaSfarsit(lista, initAngajat("Ionescu", 3500, 1235));
//	inserareLaSfarsit(lista, initAngajat("Vasilescu", 2800, 1236));
//
//	afisareLista(lista);
//	printf("\n");
//	afisareListaSfarsitInceput(lista);
//
//	stergereLista(lista);
//
//	afisareLista(lista);
//	printf("\n");
//	afisareListaSfarsitInceput(lista);
//}
