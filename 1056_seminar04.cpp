#include<stdio.h>
#include<string>

struct Cofetarie {
	char* nume;
	int nrProduse;
	float cifraAfaceri;
};

Cofetarie initializeazaCofetarie(const char* nume, int nrProduse, float cifraAfaceri) {
	Cofetarie c;
	c.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
	strcpy(c.nume, nume);
	c.nrProduse = nrProduse;
	c.cifraAfaceri = cifraAfaceri;
	return c;
}

void afiseazaCofetarie(Cofetarie c) {
	printf("Cofetariea %s are %d pproduse si o cifra de afaceri de %5.2f.\n", 
		c.nume, 
		c.nrProduse, 
		c.cifraAfaceri
	);
}

struct Nod {
	Cofetarie info;
	Nod* next;
};

Nod* inserareInceput(Nod* cap, Cofetarie c) {
	Nod* nou;
	nou = (Nod*)malloc(sizeof(Nod));
	nou->info = c;//shallow copy
	nou->next = cap;
	return nou;
}

void afisareLista(Nod* cap) {
	while (cap) {
		afiseazaCofetarie(cap->info);
		cap = cap->next;
	}
}

void stergereLista(Nod* &cap) {
	while (cap) {
		Nod*p = cap->next;
		free(cap->info.nume);
		free(cap);
		cap = p;
	}

}

void inserareCofetarieDupaAltaCofetarie(Nod* &cap, Cofetarie c, const char* numeCofetarie) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = c;
	if (cap) {
		Nod*p = cap;
		while (p->next && strcmp(p->info.nume,numeCofetarie)!=0) {
			p = p->next;
		}
		nou->next = p->next;
		p->next = nou;
	}
	else {
		nou->next = NULL;
		cap = nou;
	}
}

void main() {
	Nod* lista = NULL;
	lista = inserareInceput(lista, initializeazaCofetarie("Iepurasul", 10, 1000));
	lista = inserareInceput(lista, initializeazaCofetarie("Zoomseria", 6, 1200));
	lista = inserareInceput(lista, initializeazaCofetarie("Alice", 8, 800));
	lista = inserareInceput(lista, initializeazaCofetarie("Noblesse", 8, 700));

	afisareLista(lista);
	inserareCofetarieDupaAltaCofetarie(lista, initializeazaCofetarie("Ana", 7, 1500), "Alice");
	printf("\n\n");
	afisareLista(lista);
	stergereLista(lista);

	afisareLista(lista);

}