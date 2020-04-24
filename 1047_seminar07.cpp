//#include<stdio.h>
//#include<string>
//
//struct Telefon {
//	char* model;
//	float pret;
//};
//
//struct Nod {
//	Telefon info;
//	Nod* next;
//};
//
//struct HashTable {
//	Nod** vector;
//	int dim;
//};
//
//Telefon initTelefon(const char* model, float pret) {
//	Telefon t;
//	t.model=(char*)malloc(sizeof(char)*(strlen(model) + 1));
//	strcpy(t.model, model);
//	t.pret = pret;
//
//	return t;
//}
//
//void afisare(Telefon t) {
//	printf("Telfonul %s costa %5.2f\n", t.model, t.pret);
//}
//
//void inserareSfarsit(Nod*& cap, Telefon t) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = t;
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
//HashTable initHashTale(int dim) {
//	HashTable h;
//	h.dim = dim;
//	h.vector = (Nod**)malloc(sizeof(Nod*)*dim);
//	for (int i = 0; i < dim; i++) {
//		h.vector[i] = NULL;
//	}
//	return h;
//}
//
//int calculHashCode(const char* model, int dim) {
//	return (strlen(model) * 13) % dim;
//}
//
//void inserareHash(HashTable &h, Telefon t) {
//	if (h.dim > 0) {
//		int cod = calculHashCode(t.model, h.dim);
//		if (cod >= 0 && cod < h.dim) {
//			if (h.vector[cod]) {
//				inserareSfarsit(h.vector[cod], t);
//			}
//			else {
//				//aici avem coliziune
//				inserareSfarsit(h.vector[cod], t);
//			}
//		}
//		else {
//			throw "Codul nu ete corect";
//		}
//	}
//	else {
//		throw "NU avem tabela";
//	}
//}
//
//void afisareLista(Nod* cap)
//{
//	Nod*p = cap;
//	while (p) {
//		afisare(p->info);
//		p = p->next;
//	}
//}
//void afisareTabla(HashTable ht) {
//	for (int i = 0; i < ht.dim; i++) {
//		afisareLista(ht.vector[i]);
//		printf("\n");
//	}
//}
//
//Telefon cautareTelefonDupaModel(HashTable h, const char* model) {
//	if (h.dim > 0 && model) {
//		int cod = calculHashCode(model, h.dim);
//		if (cod >= 0 && cod < h.dim) {
//			Nod* p = h.vector[cod];
//			while (p) {
//				if (strcmp(p->info.model, model) == 0) {
//					return p->info;
//				}
//				p = p->next;
//			}
//			throw "Tlefonul nu a fost gasit";
//		}else{
//			throw "cod calculat gresit";
//		}
//	}
//	else {
//		throw "parametri incorecti";
//	}
//}
//
//void stergereLista(Nod* &cap) {
//	while (cap) {
//		Nod*aux = cap;
//		cap = cap->next;
//		free(aux->info.model);
//		free(aux);
//	}
//}
//
//void stergereTabela(HashTable& h) {
//	if(h.dim>0){
//		for (int i = 0; i < h.dim; i++) {
//			stergereLista(h.vector[i]);
//		}
//		free(h.vector);
//		h.vector = NULL;
//		h.dim = 0;
//	}
//}
//
//void main() {
//	HashTable h=initHashTale(5);
//	inserareHash(h, initTelefon("samsung", 3000));
//	inserareHash(h, initTelefon("Iphone", 7000));
//	inserareHash(h, initTelefon("Huawei", 8000));
//	inserareHash(h, initTelefon("Apple", 5000));
//
//	//afisareTabla(h);
//	afisare(cautareTelefonDupaModel(h, "Iphone"));
//
//	stergereTabela(h);
//}