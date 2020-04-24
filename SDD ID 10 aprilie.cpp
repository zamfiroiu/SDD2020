#include<stdio.h>
#include<string>


struct Biblioteca {
	char* nume;
	int nrCarti;
	float *preturi;
};

Biblioteca initBiblioteca(const char* nume, int nrCarti, float* preturi) {
	Biblioteca b;
	b.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
	strcpy(b.nume, nume);
	b.nrCarti = nrCarti;
	b.preturi = (float*)malloc(sizeof(float)*nrCarti);
	for (int i = 0; i < nrCarti; i++) {
		b.preturi[i] = preturi[i];
	}

	return b;
}

void afisareBiblioteca(Biblioteca b) {
	printf("Biblioteca %s are %d carti cu preturile:", b.nume, b.nrCarti);
	for (int i = 0; i < b.nrCarti; i++) {
		printf("%5.2f,", b.preturi[i]);
	}
	printf("\n");
}

struct Nod {
	Biblioteca info;
	Nod*next;
};

void inserareInLista(Nod* & cap, Biblioteca b) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = b;//shallow copy
	nou->next = NULL;
	if (cap) {
		Nod* p = cap;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
	}
	else {
		cap = nou;
	}
}



struct HashTable {
	Nod* * vector;
	int dim;
};

HashTable initHashTable(int dim) {
	HashTable ht;
	ht.dim = dim;
	ht.vector = (Nod**)malloc(sizeof(Nod*)*dim);
	for (int i = 0; i < dim; i++) {
		ht.vector[i] = NULL;
	}
	return ht;
}

int hashFunction(const char* nume, int dim) {
	int valoare = strlen(nume);
	valoare *= 17;
	return valoare % dim;
}

void inserareBibliotecaInTabela(HashTable ht, Biblioteca b) {
	if (ht.dim > 0) {
		int codHash = hashFunction(b.nume, ht.dim);
		if (codHash >= 0 && codHash < ht.dim) {
			if (ht.vector[codHash]) {
				//avem coliziune
				inserareInLista(ht.vector[codHash], b);
			}
			else {
				//nu avem coliziune
				//pozitia nu are niciun element
				ht.vector[codHash] = (Nod*)malloc(sizeof(Nod));
				ht.vector[codHash]->info = b;
				ht.vector[codHash]->next = NULL;
			}
		}
		else {
			throw "Codul hash nu este corect.";
		}
	}
	else {

		throw "Tabela nu a fost initializata";
	}
}

void afisareLista(Nod* cap) {
	while (cap) {
		afisareBiblioteca(cap->info);
		cap = cap->next;
	}
}

void afisareHashTable(HashTable ht) {
	for (int i = 0; i < ht.dim; i++) {
		if (ht.vector[i]) {
			afisareLista(ht.vector[i]);
		}
		printf("\n");
	}
}

Biblioteca cautaBibliotecaDupaNume(HashTable ht, const char* nume) {
	if (ht.dim > 0) {
		int cod = hashFunction(nume, ht.dim);
		if (cod >= 0 && cod < ht.dim) {
			if (ht.vector[cod]) {
				Nod* p = ht.vector[cod];
				while (p) {
					if (strcmp(p->info.nume, nume) == 0) {
						Biblioteca rezultat = initBiblioteca(p->info.nume, p->info.nrCarti, p->info.preturi);
						return rezultat;
					}
					p = p->next;
				}
				throw "Biblioteca nu a fost gasita";
			}
			else {
				throw "Biblioteca nu a fost gasita";
			}
		}
		else {
			throw "Codul hash nu este calculat corect";
		}
	}
	else {
		throw "Tabela nu exista";
	}
}

float calulcareSumaPreturiCarti(Biblioteca b) {
	float s = 0;
	for (int i = 0; i < b.nrCarti; i++) {
		s += b.preturi[i];
	}
	return s;
}

void stergereTabela(HashTable &ht) {
	for (int i = 0; i < ht.dim; i++) {
		while (ht.vector[i]) {
			Nod* temp = ht.vector[i];
			ht.vector[i] = ht.vector[i]->next;
			free(temp->info.nume);
			free(temp->info.preturi);
			free(temp);
		}
	}
	free(ht.vector);
	ht.vector = NULL;
	ht.dim = 0;
}

void main() {
	//HashTable tabela = initHashTable(5);

	//int nrCarti = 3;
	//float * preturi = (float*)malloc(sizeof(float)*nrCarti);
	//for (int i = 0; i < nrCarti; i++) {
	//	preturi[i] = i + 2;
	//}

	//float pret1[2]{ 78,89 };

	//inserareBibliotecaInTabela(tabela, initBiblioteca("Eminescu", nrCarti, preturi));
	//inserareBibliotecaInTabela(tabela, initBiblioteca("Sadoveanu", nrCarti, preturi));
	//inserareBibliotecaInTabela(tabela, initBiblioteca("Slavescu", 2, pret1));
	//inserareBibliotecaInTabela(tabela, initBiblioteca("Creanga", nrCarti, preturi));
	//inserareBibliotecaInTabela(tabela, initBiblioteca("Arhezi", nrCarti, preturi));
	//inserareBibliotecaInTabela(tabela, initBiblioteca("Carol I", nrCarti, preturi));

	////afisareHashTable(tabela);
	//Biblioteca biblioteca = cautaBibliotecaDupaNume(tabela, "Slavescu");
	//printf("SUma preturilor cartilor din biblioteca Slavescu este:%5.2f",
	//	calulcareSumaPreturiCarti(biblioteca));

	//free(biblioteca.nume);
	//free(biblioteca.preturi);

	//stergereTabela(tabela);
	
	
	float pret1[2]{ 78,89 };

	
	Nod* p = (Nod*)malloc(sizeof(Nod));
	p->info = initBiblioteca("Eminescu", 2, pret1);
	p->next = NULL;
	free(p->info.nume);
	free(p->info.preturi);
	free(p);
	p=NULL;
	inserareInLista(p, initBiblioteca("Eminescu", 2, pret1));

}