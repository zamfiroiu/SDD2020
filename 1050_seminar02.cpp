#include<stdio.h>
#include<string>

struct Echipa {
	char* nume;
	int nrMembri;
	int esteSportiva;
};

Echipa citesteEchipa() {
	Echipa e;
	char aux[20];
	printf("NUme echipa:");
	scanf("%s", aux);
	e.nume = (char*)malloc(sizeof(char)*(strlen(aux) + 1));
	strcpy(e.nume, aux);
	printf("Numar membri:");
	scanf("%d", &e.nrMembri);
	printf("Echipa sportiva? 1-DA, 0-NU:");
	scanf("%d", &e.esteSportiva);
	return e;
}

void afisareEchipa(Echipa e) {
	printf("%s are %d si %d de sport\t", 
		e.nume, 
		e.nrMembri, 
		e.esteSportiva);
}

Echipa**citireMatriceEchipe(int *nrLinii, int* *nrColoane) {
	Echipa** matrice;
	printf("Numar linii:");
	scanf("%d", nrLinii);
	*nrColoane = (int*)malloc(sizeof(int)*(*nrLinii));
	matrice = (Echipa**)malloc(sizeof(Echipa*)*(*nrLinii));
	for (int i = 0; i < *nrLinii; i++) {
		printf("Cate elemente avem pe linia %d", i);
		scanf("%d", &((*nrColoane)[i]));
		matrice[i] = (Echipa*)malloc(sizeof(Echipa)*(*nrColoane)[i]);
		for (int j = 0; j < (*nrColoane)[i]; j++) {
			matrice[i][j] = citesteEchipa();
		}
	}
	return matrice;
}


void afisareVectorEchipe(Echipa* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisareEchipa(vector[i]);
	}
}

void afisareMatriceEchipe(Echipa** matrice, int nrLinii, int* nrColoane) {
	for (int i = 0; i < nrLinii; i++) {
		afisareVectorEchipe(matrice[i], nrColoane[i]);
		printf("\n");
	}
}

void adaugareEchipa(Echipa** matrice, int nrLinii, int* nrColoane) {
	int linie;
	printf("Pe ce linie adaugam echipa:");
	scanf("%d", &linie);

	Echipa* copie = (Echipa*)malloc(sizeof(Echipa)*(nrColoane[linie] + 1));
	for (int i = 0; i < nrColoane[linie]; i++)
	{
		copie[i] = matrice[linie][i];//shallow copy
	}
	copie[nrColoane[linie]] = citesteEchipa();
	free(matrice[linie]);
	matrice[linie] = copie;
	nrColoane[linie]++;
}

void main() {

	//Echipa e;
	//e = citesteEchipa();
	//afisareEchipa(e);

	int nrLinii;
	int* nrColoane;
	Echipa** matrice;

	matrice = citireMatriceEchipe(&nrLinii, &nrColoane);
	afisareMatriceEchipe(matrice, nrLinii, nrColoane);
}