//#include<stdio.h>
//#include<string>
//
//struct Rezervare {
//	char* client;
//	float pret;
//};
//
//Rezervare initRezervare(const char* client, float pret) {
//	Rezervare r;
//	r.client = (char*)malloc(sizeof(char)*(strlen(client) + 1));
//	strcpy(r.client, client);
//	r.pret = pret;
//	return r;
//}
//
//void afisareRezervare(Rezervare r) {
//	printf("CLientul %s a facut o rezervare de %5.2 RON.\n", r.client, r.pret);
//}
//
//struct Nod {
//	Rezervare info;
//	Nod* next;
//};
//
//struct HashTable {
//	Nod** vector;
//	int dim;
//};
//
//HashTable initHashTable(int dim) {
//	HashTable h;
//	h.vector = (Nod**)malloc(sizeof(Nod*)*dim);
//	h.dim = dim;
//	for (int i = 0; i < dim; i++) {
//		h.vector[i] = NULL;
//	}
//	return h;
//}
//
//int calculareHashCode(const char* client, int dim) {
//	int s = 0;
//	for (int i = 0; i < strlen(client); i++) {
//		s += client[i];
//	}
//	s *= 7;
//	return s%dim;
//}
//
//void inserareSfarsit(Nod* & cap, Rezervare r) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = r;
//	nou->next = NULL;
//	if (cap) {
//		Nod*p = cap;
//		while (p->next) {
//			p = p->next;
//		}
//		p->next = nou;
//	}
//	else {
//		cap = nou;
//	}
//}
//
//
//void inserareInTabela(HashTable h, Rezervare r) {
//	if (h.dim > 0) {
//		int cod = calculareHashCode(r.client, h.dim);
//		if (cod >= 0 && cod < h.dim) {
//			if (h.vector[cod]) {
//				//avem coliziune
//				inserareSfarsit(h.vector[cod], r);
//			}
//			else {
//				inserareSfarsit(h.vector[cod], r);
//			}
//		}
//		else {
//			throw "cod gresit";
//		}
//	}
//	else {
//		throw "nu avem tabela";
//	}
//}
//
//float cautarePretDupaNUmeClient(HashTable h, const char* client) {
//	int cod = calculareHashCode(client, h.dim);
//	if (cod >= 0 && cod < h.dim) {
//		if (h.vector[cod]) {
//			Nod* p = h.vector[cod];
//			while (p && strcmp(p->info.client, client) != 0) {
//				p = p->next;
//			}
//			if (p) {
//				return p->info.pret;
//			}
//			else {
//				throw "Elementul nu a fot gasit";
//			}
//		}
//		else {
//			throw "Elementul nu a fot gasit";
//		}
//	}
//	else {
//		throw "codul nu este corect";
//	}
//}
//
//
//void main() {
//	HashTable h=initHashTable(5);
//
//	inserareInTabela(h, initRezervare("Popescu", 10.3));
//	inserareInTabela(h, initRezervare("Vasilsecu", 34));
//	inserareInTabela(h, initRezervare("Ionesu", 78));
//	inserareInTabela(h, initRezervare("Vasilescu", 14.3));
//
//	printf("Pretul rezervarii este: %5.2f", cautarePretDupaNUmeClient(h, "Vasilescu"));
//}