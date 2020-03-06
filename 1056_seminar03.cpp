#include<stdio.h>
#include<malloc.h>
#include<string>

struct Casa {
	char* strada;
	int nrEtaje;
	float suprafataUtila;
};

Casa citesteCasa() {
	Casa c;
	char aux[30];
	printf("Numele strazii:");
	scanf("%s", aux);
	c.strada = (char*)malloc(sizeof(char)*(strlen(aux) + 1));
	strcpy(c.strada, aux);
	printf("Numar etaje:");
	scanf("%d", &c.nrEtaje);
	printf("Suprafata utila:");
	scanf("%f", &c.suprafataUtila);
	return c;
}

void CitesteCartierDeCase(int *nrLinii, int* *nrColoane, Casa** *cartier)
{
	printf("Cate linii are cartierul:");
	scanf("%d", nrLinii);
	(*nrColoane) = (int*)malloc(sizeof(int)*(*nrLinii));
	(*cartier) = (Casa**)malloc(sizeof(Casa*)*(*nrLinii));
	for (int i = 0; i < *nrLinii; i++) {
		printf("cate case avem pe linia %d", i);
		scanf("%d", &(*nrColoane)[i]);
		(*cartier)[i] = (Casa*)malloc(sizeof(Casa)*(*nrColoane)[i]);
		for (int j = 0; j < (*nrColoane)[i]; j++) {
			(*cartier)[i][j] = citesteCasa();
			//*((*((*cartier)+i))+j)= citesteCasa();
		}
	}
}

void afisareCasa(Casa c) {
	printf("Pe strada %s casa are %d etaje si  %5.2f mp.", c.strada, c.nrEtaje, c.suprafataUtila);
}

void afisareVectorCase(Casa* casele, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisareCasa(casele[i]);
		printf(" ");
	}
	printf("\n");
}

void afisareCartier(Casa** cartier, int nrLinii, int* nrColoane) {
	for (int i = 0; i < nrLinii; i++) {
		afisareVectorCase(cartier[i], nrColoane[i]);
	}
}

void adaugaCasaInMatrice(Casa ** cartier, int nrLinii, int *nrColoane) {
	printf("Pe ce linie adaugam:");
	int linie=0;
	scanf("%d", &linie);
	Casa * copie = (Casa*)malloc(sizeof(Casa)*(nrColoane[linie] + 1));
	for (int i = 0; i < nrColoane[linie]; i++) {
		copie[i] = cartier[linie][i];
	}
	printf("introducet noua casa:");
	copie[nrColoane[linie]] = citesteCasa();
	free(cartier[linie]);
	cartier[linie] = copie;
	nrColoane[linie]++;
}

void main() {

	Casa ** cartier;
	int nrLinii;
	int*nrColoane;

	CitesteCartierDeCase(&nrLinii, &nrColoane, &cartier);

	afisareCartier(cartier, nrLinii, nrColoane);
	adaugaCasaInMatrice(cartier, nrLinii, nrColoane);
	printf("\n");
	afisareCartier(cartier, nrLinii, nrColoane);

}