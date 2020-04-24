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
//	Nod* next;
//};
//
//struct HashTable {
//	Nod** vector;
//	int dim;
//};
//
//Serial initSerial(const char* nume, int nr) {
//	Serial s;
//	s.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(s.nume, nume);
//	s.nrEpisoade = nr;
//
//	return s;
//}
//
//
//void inserareSfarsit(Nod* &cap, Serial s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = s;
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
//void afisareSerial(Serial s) {
//	printf("Serialul %s are %d episoade.\n", s.nume, s.nrEpisoade);
//}
//
//HashTable initHashTable(int dim) {
//	HashTable h;
//	h.dim = dim;
//	h.vector = (Nod**)malloc(sizeof(Nod*)*dim);
//	for (int i = 0; i < dim; i++) {
//		h.vector[i] = NULL;
//	}
//	return h;
//}
//
//int calculHashCode(const char* nume, int dim) {
//	return (strlen(nume) * 3) % dim;
//}
//
//void inserareTabela(HashTable h, Serial s) {
//	if (h.dim > 0) {
//		int cod = calculHashCode(s.nume, h.dim);
//		if (cod >= 0 && cod < h.dim) {
//			if (h.vector[cod]) {
//				//avem coliziune
//				inserareSfarsit(h.vector[cod], s);
//			}
//			else {
//				//nu avem coliziune
//				h.vector[cod] = (Nod*)malloc(sizeof(Nod));
//				h.vector[cod]->info = s;
//				h.vector[cod]->next = NULL;
//			}
//		}
//	}
//}
//
//void afisareLista(Nod* cap) {
//	while (cap) {
//		afisareSerial(cap->info);
//		cap = cap->next;
//	}
//}
//
//void afisareTabela(HashTable h) {
//	for (int i = 0; i < h.dim; i++) {
//		afisareLista(h.vector[i]);
//		printf("\n");
//	}
//}
//
//int cautareSerialDupaNume(const char* nume, HashTable h) {
//	if (h.dim > 0) {
//		int cod = calculHashCode(nume, h.dim);
//		if (h.vector[cod]) {
//			Nod*p = h.vector[cod];
//			while (p && strcmp(p->info.nume, nume) != 0) {
//				p = p->next;
//			}
//			if (!p) {
//				throw "serialul nu exista";
//			}else{
//				return p->info.nrEpisoade;
//			}
//		}
//		else {
//
//			throw "serialul nu exista";
//		}
//	}
//	else {
//		throw "nu exista tabela.";
//	}
//}
//
//
//void main() {
//	HashTable h = initHashTable(5);
//	inserareTabela(h, initSerial("Gossip Girl", 200));
//	inserareTabela(h, initSerial("Friends", 150));
//	inserareTabela(h, initSerial("Mr. Robot", 200));
//	inserareTabela(h, initSerial("Dinasty", 50));
//
//	afisareTabela(h);
//
//	printf("Serialul are % episoade.\n", cautareSerialDupaNume("Friends",h));
//}