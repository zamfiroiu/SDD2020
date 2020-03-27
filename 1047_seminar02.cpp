//#include<stdio.h>
//#include<string>
//
//struct Laptop {
//	char* model;
//	int RAM;
//	int cameraWeb;
//};
//
//Laptop citesteLaptop() {
//	Laptop laptop;
//	printf("Model laptop:");
//	char aux[20];
//	scanf("%s", aux);
//	laptop.model = (char*)malloc((strlen(aux) + 1) * sizeof(char));
//	strcpy(laptop.model, aux);
//	printf("RAM:");
//	scanf("%d", &laptop.RAM);
//	printf("Are camera web? (1-DA, 0-NU:");
//	scanf("%d", &laptop.cameraWeb);
//
//	return laptop;
//}
//
//void afisareLaptop(Laptop laptop) {
//	printf("%s are %d RAM si %d camera Web",
//		laptop.model, 
//		laptop.RAM, 
//		laptop.cameraWeb);
//}
//
//Laptop** citesteMatriceLaptopuri(int * nrLinii, int* *nrColoane) {
//	printf("Cate linii are matricea:");
//	scanf("%d", nrLinii);
//	*nrColoane = (int*)malloc(sizeof(int)*(*nrLinii));
//	Laptop** matrice;
//	matrice = (Laptop**)malloc(sizeof(Laptop*)*(*nrLinii));
//	for (int i = 0; i < *nrLinii; i++) {
//		printf("Cate elemente avem pe linia %d", i);
//		scanf("%d", &((*nrColoane)[i]));
//
//		matrice[i] = (Laptop*)malloc(sizeof(Laptop)*(*nrColoane)[i]);
//		for (int j = 0; j < (*nrColoane)[i]; j++) {
//			matrice[i][j] = citesteLaptop();
//		}
//	}
//	return matrice;
//}
//
//void afisareVectorLaptopuri(Laptop* vector, int nrElemente) {
//	for (int i = 0; i < nrElemente; i++) {
//		afisareLaptop(vector[i]);
//	}
//}
//
//void afisareMatriceLaptopuri(Laptop** matrice, int nrLinii, int *nrColoane) {
//	for (int i = 0; i < nrLinii; i++) {
//		afisareVectorLaptopuri(matrice[i], nrColoane[i]);
//		printf("\n");
//	}
//}
//
//void f(int* *d) {
//	*d = new int(4);
//	//(*d) = 4;
//}
//
//void main() {
//
//	/*Laptop laptop = citesteLaptop();
//	afisareLaptop(laptop);*/
//
//	Laptop** laptopuri;
//	int nrLinii = 0;
//	int* nrColoane;
//
//
//	laptopuri = citesteMatriceLaptopuri(&nrLinii, &nrColoane);
//
//	afisareMatriceLaptopuri(laptopuri, nrLinii, nrColoane);
//
//
//	//int a = 9;
//
//	//int* b = &a;
//	//printf("%d", *b);
//
//	//int ** c = &b;
//	//f(&b);
//
//}