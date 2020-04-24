//#include<stdio.h>
//#include<string>
//
//struct Calculator {
//	char* prod;
//	int memorie;
//};
//
//Calculator initCalc(const char* prod, int mem) {
//	Calculator c;
//	c.prod = (char*)malloc(sizeof(char*)*(strlen(prod) + 1));
//	strcpy(c.prod, prod);
//	c.memorie = mem; 
//	return c;
//}
//
//void afisareCalc(Calculator c) {
//	printf("Calculatorul produs de %s, are %d memorie\n", c.prod, c.memorie);
//}
//
//struct Nod {
//	Calculator info;
//	Nod* next;
//};
//
//struct HashTable {
//	Nod** vector;
//	int dim;
//};
//
//void inserareSfarsit(Nod* &cap, Calculator c) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = c;
//	nou->next = NULL;
//	if (cap == NULL) {
//		cap = nou;
//	}else{
//		Nod* p = cap;
//		while (p->next) {
//			p = p->next;
//		}
//		p->next = nou;
//	}
//}
//
//HashTable initHashTable(int dim) {
//	HashTable h;
//	h.dim = dim;
//	h.vector = (Nod**)malloc(sizeof(Nod*)*dim);
//	for (int i = 0; i < h.dim; i++) {
//		h.vector[i] = NULL;
//	}
//
//	return h;
//}
//
//int calculareHashCode(const char* prod, int dim) {
//	int s = 0;
//	for (int i = 0; i < strlen(prod); i++) {
//		s += prod[i];
//	}
//	s *= 13;
//	return s%dim;
//}
//
//void inserareHashTable(HashTable h, Calculator c) {
//	if (h.dim > 0) {
//		int cod = calculareHashCode(c.prod, h.dim);
//		if (cod >= 0 && cod < h.dim) {
//			if (h.vector[cod]) {
//				//aici avem coliziune
//				inserareSfarsit(h.vector[cod], c);
//			}
//			else {
//				h.vector[cod] = (Nod*)malloc(sizeof(Nod));
//				h.vector[cod]->info = c; //shallow copy
//				h.vector[cod]->next = NULL;
//			}
//		}
//		else {
//			throw "cod incorect";
//		}
//	}
//	else {
//		throw "nu avem tabela";
//	}
//}
//
//void afisareLista(Nod*cap) {
//	while (cap) {
//		afisareCalc(cap->info);
//		cap = cap->next;
//	}
//}
//
//void afisareTabela(HashTable h) {
//	for (int i = 0; i < h.dim; i++) {
//		if (h.vector[i]) {
//			afisareLista(h.vector[i]);
//			printf("\n");
//		}
//	}
//}
//
//int cautareMemorieDupaProducator(HashTable h, const char* prod) {
//	if (h.dim > 0) {
//		int cod = calculareHashCode(prod, h.dim);
//		if (cod >= 0 && cod < h.dim) {
//			if (h.vector[cod]) {
//				Nod* p = h.vector[cod];
//				while (p && strcmp(p->info.prod, prod) != 0) {
//					p = p->next;
//				}
//				if (p) {
//					return p->info.memorie;
//				}
//				else {
//					throw "Calculatorul nu a fost gasit";
//				}
//			}
//			else {
//				throw "Calculatorul nu a fost gasit";
//			}
//		}
//		else {
//			throw "Cod incorect";
//		}
//	}
//	else {
//		throw "Tabela nu exista";
//	}
//}
//
//void strergereTabela(HashTable &h) {
//	for (int i = 0; i < h.dim; i++) {
//		while (h.vector[i]) {
//			Nod*aux = h.vector[i];
//			h.vector[i] = h.vector[i]->next;
//			free(aux->info.prod);
//			free(aux);
//		}
//	}
//	free(h.vector);
//	h.vector = NULL;
//	h.dim = 0;
//}
//
//void main() {
//	HashTable h=initHashTable(5);
//
//	inserareHashTable(h, initCalc("DELL", 16));
//	inserareHashTable(h, initCalc("LLED", 24));
//	inserareHashTable(h, initCalc("ASUS", 12));
//	inserareHashTable(h, initCalc("HP", 8));
//
//
//	afisareTabela(h);
//
//
//	printf("Memoia cautata este: %d.\n", cautareMemorieDupaProducator(h, "ASUS"));
//
//	strergereTabela(h);
//}