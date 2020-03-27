//#include<stdio.h>
//#include<string>
//
//struct Agent {
//	char* cod;
//	int varsta;
//	float salariu;
//};
//
//struct Nod {
//	Agent info;
//	Nod* next;
//	Nod* prev;
//};
//
//struct ListaDubla {
//	Nod*prim;
//	Nod*ultim;
//};
//
//Agent initAgent(const char* cod, int varsta, float salariu) {
//	Agent a;
//	a.cod = (char*)malloc(sizeof(char)*(strlen(cod) + 1));
//	strcpy(a.cod, cod);
//	a.varsta = varsta;
//	a.salariu = salariu;
//	return a;
//}
//
//void afisareAgent(Agent a) {
//	printf("Agentul %s are %d ani si un salariu de %5.2f\n", 
//		a.cod, a.varsta, a.salariu);
//}
//
//ListaDubla inserareInceput(ListaDubla lista, Agent a) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = a;
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
//	for (Nod*p = lista.prim; p ; p = p->next) {
//		afisareAgent(p->info);
//	}
//}
//
//void afisareSfarsitInceput(ListaDubla lista) {
//	Nod*p = lista.ultim;
//	while (p) {
//		afisareAgent(p->info);
//		p = p->prev;
//	}
//}
//
//void stergereLista(ListaDubla & lista) {
//	while (lista.prim) {
//		Nod*p = lista.prim;
//		lista.prim = lista.prim->next;
//		free(p->info.cod);
//		free(p);
//	}
//	lista.ultim = NULL;
//
//
//}
//
//void main() {
//	ListaDubla lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//	lista=inserareInceput(lista, initAgent("007", 52, 2000));
//	lista= inserareInceput(lista, initAgent("009", 37, 3000));
//	afisareInceputSfarsit(lista);
//	printf("\n");
//	afisareSfarsitInceput(lista);
//	stergereLista(lista);
//	afisareSfarsitInceput(lista);
//}
