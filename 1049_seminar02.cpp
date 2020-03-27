//#include<stdio.h>
//#include<string>
//
//struct Angajat {
//	char* nume;
//	float salariu;
//	int varsta;
//};
//
//Angajat citesteAngajat() {
//	Angajat a;
//	char aux[20];
//	printf("Nume angajat:");
//	scanf("%s", aux);
//	a.nume = (char*)malloc(sizeof(char)*(strlen(aux) + 1));
//	strcpy(a.nume, aux);
//	printf("Salariu:");
//	scanf("%f", &a.salariu);
//	printf("Varsta:");
//	scanf("%d", &a.varsta);
//
//	return a;
//}
//
//void afiseazaAngajat(Angajat a) {
//	printf("%s are %d ani si %5.2f RON.",
//		a.nume,
//		a.varsta,
//		a.salariu);
//}
//
//Angajat** citesteMatriceAngajati(int* nrLinii, int* *nrColoane) {
//	printf("Numarul de linii: ");
//	scanf("%d", nrLinii);
//	*nrColoane = (int*)malloc(sizeof(int)*(*nrLinii));
//	Angajat** matrice;
//	matrice = (Angajat**)malloc(sizeof(Angajat*)*(*nrLinii));
//
//	for (int i = 0; i < *nrLinii; i++) {
//		printf("Numar angajati pe linia %d", i);
//		scanf("%d", &(*nrColoane)[i]);
//		matrice[i] = (Angajat*)malloc(sizeof(Angajat)*(*nrColoane)[i]);
//		for (int j = 0; j < (*nrColoane)[i]; j++) {
//			matrice[i][j] = citesteAngajat();
//		}
//	}
//	return matrice;
//}
//
//void afisareVectorAngajati(Angajat* vector, int nrElemente) {
//	for (int i = 0; i < nrElemente; i++) {
//		afiseazaAngajat(vector[i]);
//	}
//}
//
//void afisareMatriceAngajati(Angajat** matrice, int nrLinii, int* nrColoane) {
//	for (int i = 0; i < nrLinii; i++) {
//		if (nrColoane[i] > 0) {
//			afisareVectorAngajati(matrice[i], nrColoane[i]);
//			printf("\n");
//		}
//	}
//}
//
//void adaugareAngajat(Angajat**matrice, int nrLinii, int* nrColoane) {
//	printf("Pe ce linie adaugam:");
//	int linie;
//	scanf("%d", &linie);
//	Angajat* copie = (Angajat*)malloc(sizeof(Angajat)*(nrColoane[linie]+1));
//	for (int i = 0; i < nrColoane[linie]; i++) {
//		copie[i] = matrice[linie][i];//shallow copy
//	}
//	copie[nrColoane[linie]] = citesteAngajat();
//	free(matrice[linie]);
//	matrice[linie] = copie;
//	nrColoane[linie]++;
//}
//
//void main() {
//
//	/*Angajat a=citesteAngajat();
//	afiseazaAngajat(a);*/
//
//	Angajat**matrice;
//	int*nrColoane;
//	int nrLinii;
//
//	matrice = citesteMatriceAngajati(&nrLinii, &nrColoane);
//	afisareMatriceAngajati(matrice, nrLinii, nrColoane);
//
//
//}