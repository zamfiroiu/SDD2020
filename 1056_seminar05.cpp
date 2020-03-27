//#include<stdio.h>
//#include<string>
//
//struct Laptop {
//	char* producator;
//	int RAM;
//	float CPU;
//};
//
//Laptop initializareLaptop(const char* produator, int RAM, float CPU) {
//	Laptop l;
//	l.producator = (char*)malloc(sizeof(char)*(strlen(produator) + 1));
//	strcpy(l.producator, produator);
//	l.RAM = RAM;
//	l.CPU = CPU;
//	return l;
//}
//
//void afisareLaptop(Laptop l) {
//	printf("Laptopul produs de %s are %d RAM si % 5.2f putere procesor.\n", l.producator, l.RAM, l.CPU);
//}
//
//struct Nod {
//	Laptop info;
//	Nod* next;
//	Nod* prev;
//};
//
//struct ListaDubla {
//	Nod* primulNod;
//	Nod* ultimulNod;
//};
//
//
//void inserareSfarsitLD(ListaDubla &lista, Laptop l) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = l;
//	nou->next = NULL;
//	nou->prev = lista.ultimulNod;
//	if (lista.ultimulNod) {
//		lista.ultimulNod->next = nou;
//		lista.ultimulNod = nou;
//	}
//	else {
//		lista.ultimulNod = nou;
//		lista.primulNod = nou;
//	}
//}
//
//void afisareListaDublaNormal(ListaDubla lista) {
//	Nod* p = lista.primulNod;
//	while (p) {
//		afisareLaptop(p->info);
//		p = p->next;
//	}
//}
//
//void afisareListaDublaInvers(ListaDubla lista) {
//	for (Nod* p = lista.ultimulNod; p != NULL; p = p->prev) {
//		afisareLaptop(p->info);
//	}
//}
//
//void stergereLista(ListaDubla & lista) {
//	Nod*p = lista.primulNod;
//	while (p) {
//		Nod* aux = p->next;
//		free(p->info.producator);
//		free(p);
//		p = aux;
//	}
//	lista.primulNod = NULL;
//	lista.ultimulNod = NULL;
//}
//
//
//void stergereDInLista(ListaDubla &lista, const char* prod) {
//	Nod*p = lista.primulNod;
//	while (p && strcmp(p->info.producator, prod) != 0) {
//		p = p->next;
//	}
//	if (p) {
//		Nod*aux = p;
//		if (p->prev) {
//			p->prev->next = p->next;
//			if (p->next) {
//				p->next->prev = p->prev;
//			}
//			else {
//				lista.ultimulNod = p->prev;
//			}
//		}
//		else {
//			p->next->prev = NULL;
//			lista.primulNod = p->next;
//		}
//		free(p->info.producator);
//		free(p);
//	}
//}
//
//
//
//void main() {
//	ListaDubla lista;
//	lista.primulNod = lista.ultimulNod = NULL;
//
//	inserareSfarsitLD(lista, initializareLaptop("HP", 4, 2.2));
//	inserareSfarsitLD(lista, initializareLaptop("Dell", 8, 2.9));
//	inserareSfarsitLD(lista, initializareLaptop("ASUS", 12, 3.2));
//
//	afisareListaDublaNormal(lista);
//	printf("\n\n");
//	afisareListaDublaInvers(lista);
//
//	stergereLista(lista);
//}
