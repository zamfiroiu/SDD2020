#include<stdio.h>
#include<string>


struct Oras {
	char* nume;
	int nrLocuitori;
	float suprafata;
};

Oras citesteOras() {
	Oras o;
	char aux[20];
	printf("Numele orasului:");
	scanf("%s", aux);
	o.nume = (char*)malloc(sizeof(char)*(strlen(aux) + 1));
	strcpy(o.nume, aux);
	printf("Numar locuitori:");
	scanf("%d", &o.nrLocuitori);
	printf("Suprafata oras:");
	scanf("%f", &o.suprafata);
	return o;
}

void afisareOras(Oras o) {
	printf("%s are %d loc. si %5.2f km.",
		o.nume,
		o.nrLocuitori,
		o.suprafata);
}


void adaugareOras(Oras**matrice, int nrLinii, int* nrElementePeLinie) {
	int linie = 0;
	printf("Pe ce linie adaugam orasul:");
	scanf("%d", &linie);
	Oras* copie = (Oras*)malloc(sizeof(Oras)*(nrElementePeLinie[linie] + 1));
	for (int i = 0; i < nrElementePeLinie[linie]; i++) {
		copie[i] = matrice[linie][i];
	}
	copie[nrElementePeLinie[linie]] = citesteOras();
	free(matrice[linie]);
	matrice[linie] = copie;
	nrElementePeLinie[linie]++;
}

void citireMatrice(Oras** *matrice, int* nrLinii, int* *nrElemente) {
	printf("Cate linii avem?:");
	scanf("%d", nrLinii);
	*matrice = (Oras**)malloc(sizeof(Oras*)*(*nrLinii));
	*nrElemente = (int*)malloc(sizeof(int)*(*nrLinii));
	for (int i = 0; i < *nrLinii; i++) {
		printf("Numarul de elemente de pe linia %d:", i);
		scanf("%d", &(*nrElemente)[i]);
		(*matrice)[i] = (Oras*)malloc(sizeof(Oras)*(*nrElemente)[i]);
		for (int j = 0; j < (*nrElemente)[i]; j++) {
			(*matrice)[i][j] = citesteOras();
		}
	}
}

//TODO de facut si cu return

void afisareVectorOrase(Oras* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisareOras(vector[i]);
	}
}

void afisareMatriceOrase(Oras** matrice, int nrLinii, int* nrElementeLinie) {
	for (int i = 0; i < nrLinii; i++) {
		afisareVectorOrase(matrice[i], nrElementeLinie[i]);
		printf("\n");
	}
}

void main() {
	//Oras oras;
	//oras = citesteOras();
	//afisareOras(oras);

	Oras** matrice;
	int nrLinii;
	int* nrElementePeLinie;
	citireMatrice(&matrice, &nrLinii, &nrElementePeLinie);
	afisareMatriceOrase(matrice, nrLinii, nrElementePeLinie);
}