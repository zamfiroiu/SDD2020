#include<stdio.h>
#include<string>

struct Carte {
	char* titlu;
	int nrPagini;
	float pret;
};

Carte initializareCarte(const char* titlu, int nrPagini, float pret) {
	Carte c;
	c.titlu = (char*)malloc(sizeof(char)*(strlen(titlu) + 1));
	strcpy(c.titlu, titlu);
	c.nrPagini = nrPagini;
	c.pret = pret;
	return c;
}

void afisareCarte(Carte c) {
	printf("Cartea %s are %d pagini si costa %5.2f.\n",c.titlu,c.nrPagini,c.pret);
}

struct Nod {
	Carte info;
	Nod* next;
};

Nod* inserareLaInceput(Nod* cap, Carte c) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = c; //shallow copy util
	nou->next = cap;
	return nou;
}

void afisareListaCarti(Nod* cap) {
	while (cap) {
		afisareCarte(cap->info);
		cap = cap->next;
	}
}

void stergereLista(Nod* &cap) {
	while (cap) {
		free(cap->info.titlu);
		Nod*temp = cap;
		cap = cap->next;
		free(temp);
	}
}


void inserareSortataDupaNrPagini(Nod* &primulNod, Carte c) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = c;
	if (primulNod) {
		//strcmp(primulNod->info.titlu, c.titlu)>0
		if (primulNod->info.nrPagini > c.nrPagini) {
			nou->next = primulNod;
			primulNod = nou;
		}
		else {
			Nod* temp = primulNod;
			// while (temp->next && strcmp(temp->next->info.titlu, c.titlu) < 0)
			while (temp->next && temp->next->info.nrPagini < c.nrPagini) {
				temp = temp->next;
			}
			nou->next = temp->next;
			temp->next = nou;
		}
	}
	else {
		nou->next = NULL;
		primulNod = nou;
	}
}

void main() {
	Nod* lista = NULL;
	inserareSortataDupaNrPagini(lista, initializareCarte("Morometii", 400, 30));
	inserareSortataDupaNrPagini(lista, initializareCarte("Tehnlogii mobile", 560, 60));
	inserareSortataDupaNrPagini(lista, initializareCarte("Crima", 350, 40));
	inserareSortataDupaNrPagini(lista, initializareCarte("Statistica", 450, 60));

	afisareListaCarti(lista);
	stergereLista(lista);

	afisareListaCarti(lista);
}