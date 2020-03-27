//#include<stdio.h>
//#include<string>
//
//struct Cinema {
//	char* nume;
//	float pretBilet;
//	int nrLocuri;
//};
//
//struct Nod {
//	Cinema info;
//	Nod* next;
//	Nod* prev;
//};
//
//struct ListaDubla {
//	Nod* prim;
//	Nod* ultim;
//};
//
//Cinema initCinema(const char* nume, float pret, int nrLocuri) {
//	Cinema c;
//	c.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(c.nume, nume);
//	c.nrLocuri = nrLocuri;
//	c.pretBilet = pret;
//	return c;
//}
//
//void afisareCinema(Cinema c) 
//{
//	printf("Cinema %s are %d locuri si %5.2f\n", c.nume, c.nrLocuri, c.pretBilet);
//}
//
//ListaDubla inserareINceput(Cinema c, ListaDubla lista) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = c;
//	nou->next = lista.prim;
//	nou->prev = NULL;
//	if (lista.prim) {
//		lista.prim->prev = nou;
//		lista.prim = nou;
//	}
//	else {
//		lista.prim = nou;
//		lista.ultim = nou;
//	}
//	return lista;
//}
//
//void afisareInceputSfarsit(ListaDubla lista) {
//	Nod* p = lista.prim;
//	while (p) {
//		afisareCinema(p->info);
//		p = p->next;
//	}
//}
//
//void afisareSfarsitInceput(ListaDubla lista) {
//	for (Nod* p = lista.ultim; p != NULL; p = p->prev) {
//		afisareCinema(p->info);
//	}
//}
//
//void stergereLista(ListaDubla &lista) {
//	while (lista.prim) {
//		free(lista.prim->info.nume);
//		Nod*p = lista.prim;
//		lista.prim = lista.prim->next;
//		free(p);
//	}
//	lista.prim = NULL;
//	lista.ultim = NULL;
//}
//
//
//void main() {
//	ListaDubla lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//
//	lista=inserareINceput(initCinema("CinemaCity", 15, 200), lista);
//	lista=inserareINceput(initCinema("GrandCinema", 15, 200), lista);
//	afisareInceputSfarsit(lista);
//	printf("\n");
//	afisareSfarsitInceput(lista);
//
//	stergereLista(lista);
//
//	afisareSfarsitInceput(lista);
//}
