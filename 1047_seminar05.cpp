//#include<stdio.h>
//#include<string>
//
//struct Bloc {
//	int nrEtaje;
//	int* apartamentePerEtaj;
//	float intretinere;
//};
//
//struct Nod {
//	Nod* prev;
//	Nod* next;
//	Bloc info;
//};
//
//struct ListaDubla {
//	Nod* first;
//	Nod* last;
//};
//
//Bloc initBloc(int nrE, int* ap, float intretinere) {
//	Bloc b;
//	b.nrEtaje = nrE;
//	b.apartamentePerEtaj = (int*)malloc(sizeof(int)*nrE);
//	for (int i = 0; i < nrE; i++) {
//		b.apartamentePerEtaj[i] = ap[i];
//	};
//	b.intretinere = intretinere;
//	return b;
//}
//
//void afisareBloc(Bloc b) {
//	printf("Blocul cu %d etaje cu o intretinere de %5.2f: ", b.nrEtaje, b.intretinere);
//	for (int i = 0; i < b.nrEtaje; i++) {
//		printf("%d, ", b.apartamentePerEtaj[i]);
//	}
//	printf("\n");
//}
//
//ListaDubla inserareInceput(ListaDubla lista, Bloc bloc) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = bloc;//shallow copy
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
//	return lista;
//}
//
//void stergereLista(ListaDubla &lista) {
//	Nod* p = lista.first;
//	while (p) {
//		free(p->info.apartamentePerEtaj);
//		Nod* temp = p;
//		p = p->next;
//		free(temp);
//	}
//	lista.first = NULL;
//	lista.last = NULL;
//}
//
//void afisareNormala(ListaDubla l) {
//	Nod* p = l.first;
//	while (p) {
//		afisareBloc(p->info);
//		p = p->next;
//	}
//}
//
//void afisareSfarsitInceput(ListaDubla lista) {
//	for (Nod* p = lista.last; p != NULL; p = p->prev) {
//		afisareBloc(p->info);
//	}
//}
//
//void main() {
//
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//
//	int* v;
//	v = (int*)malloc(sizeof(int) * 3);
//	v[0] = 2;
//	v[1] = 4;
//	v[2] = 3;
//
//	lista=inserareInceput(lista, initBloc(3, v, 120));
//	v[1] = 5;
//	lista=inserareInceput(lista, initBloc(3, v, 120));
//
//	afisareNormala(lista);
//	printf("\n");
//	afisareSfarsitInceput(lista);
//
//	stergereLista(lista);
//	free(v);
//	afisareSfarsitInceput(lista);
//}