//#include<stdio.h>
//#include<string>
//
//struct Floare {
//	char* nume;
//	float pret;
//};
//
//
//struct Nod {
//	Floare info;
//	Nod* next;
//};
//
//
//struct HashTable {
//	Nod ** vector;
//	int dim;
//};
//
//Floare initFloare(const char* nume, float pret) {
//	Floare f;
//	f.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(f.nume, nume);
//	f.pret = pret;
//	return f;
//}
//
//
//void afisareFLoare(Floare f) {
//	printf("Floarea %s costa %5.2f\n", f.nume, f.pret);
//}
//
//void inserareSfarsit(Nod* &lista, Floare f) {
//	Nod*nou=(Nod*)malloc(sizeof(Nod));
//	nou->info = f;
//	nou->next = NULL;
//	if (lista) {
//		Nod* temp = lista;
//		while (temp->next) {
//			temp = temp->next;
//		}
//		temp->next = nou;
//	}
//	else {
//		lista = nou;
//	}
//
//}
//
//HashTable initHashTable(int dim) {
//	HashTable h;
//	h.dim = dim;
//	h.vector = (Nod**)malloc(sizeof(Nod*)*dim);
//	for (int i = 0; i < h.dim; i++) {
//		h.vector[i] = NULL;
//	}
//	return h;
//}
//int calculHash(const char* nume, int dim) {
//	int lungime = strlen(nume);
//	lungime *= 11;
//	return lungime % dim;
//}
//
//void inserareHashTable(HashTable &tabela, Floare f) {
//	if (tabela.dim > 0) {
//		int cod = calculHash(f.nume, tabela.dim);
//		//if (tabela.vector[cod]) {
//		//	//avem coliziune--exista deja un obiect pe aceas pozitie
//		//	inserareSfarsit(tabela.vector[cod], f);
//		//}
//		//else {
//		//	inserareSfarsit(tabela.vector[cod], f);
//		//}
//		inserareSfarsit(tabela.vector[cod], f);
//	}
//	else {
//		throw "Tabela neintializata";
//	}
//}
//
//void afisareLista(Nod* lista) {
//	while (lista) {
//		afisareFLoare(lista->info);
//		lista = lista->next;
//	}
//}
//
//void afisareFloriTabela(HashTable h) {
//	for (int i = 0; i < h.dim; i++) {
//		afisareLista(h.vector[i]);
//		printf("\n");
//	}
//}
//
//float cautarePretDupaNume(HashTable h, const char* nume) {
//	int cod = calculHash(nume, h.dim);
//	if (cod >= 0 && cod < h.dim) {
//		if (h.vector[cod]) {
//			Nod*p = h.vector[cod];
//			while (p) {
//				if (strcmp(p->info.nume, nume) == 0) {
//					return p->info.pret;
//				}
//				p = p->next;
//			}
//			throw "Floare nu exista";
//		}
//		else {
//			throw "Floare nu exista";
//		}
//	}
//	else {
//		throw "Floare nu exista";
//	}
//}
//
//void main() {
//	HashTable h = initHashTable(5);
//	Floare f1 = initFloare("Lalea", 12);
//	Floare f2 = initFloare("Margareta", 10);
//	Floare f3 = initFloare("Zambila", 8);
//	Floare f4 = initFloare("Trandafir", 15);
//	inserareHashTable(h, f1);
//	inserareHashTable(h, f2);
//	inserareHashTable(h, f3);
//	inserareHashTable(h, f4);
//
//	afisareFloriTabela(h);
//
//	printf("Pretul unei flori este de %5.2f.\n\n", cautarePretDupaNume(h, "Trandafir"));
//
//}