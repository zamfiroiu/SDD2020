//#include<stdio.h>
//#include<string>
//
//struct Ferma {
//	char* nume;
//	int nrAnimale;
//	float suprafataTeren;
//};
//
//Ferma initializareFerma(const char* nume, int nrAnimale, float suprafata) {
//	Ferma f;
//	f.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(f.nume, nume);
//	f.nrAnimale = nrAnimale;
//	f.suprafataTeren = suprafata;
//	return f;
//}
//
//struct Nod {
//	Ferma info;
//	Nod* next;
//};
//
//Nod* inserareInceput(Nod* cap, Ferma f) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = f;//shallow copy util
//	nou->next = cap;
//
//	return nou;
//}
//
//void afisareFerma(Ferma f) {
//	printf("Ferma %s are %d animale si o suprafata de %5.2f.\n",
//		f.nume,
//		f.nrAnimale,
//		f.suprafataTeren);
//}
//
//void afisareListaFerme(Nod* cap) {
//	while (cap) {
//		afisareFerma(cap->info);
//		cap = cap->next;
//	}
//}
//
//void stergereListaFerme(Nod* &cap) {
//	while (cap) {
//		free(cap->info.nume);
//		Nod* temp = cap;
//		cap = cap->next;
//		free(temp);
//	}
//}
//
//void inserareDupaOFerma(Nod* &cap, Ferma f, const char* numeFermaCautata) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = f;//shallow copy util
//	if (cap) {
//		Nod* p = cap;
//		while (strcmp(numeFermaCautata,p->info.nume)!=0 && p->next) {
//			p = p->next;
//		}
//		nou->next = p->next;
//		p->next = nou;
//	}
//	else {
//		nou->next;
//		cap = nou;
//	}
//
//}
//
//void main()
//{
//	Nod* lista = NULL;
//	lista = inserareInceput(lista, initializareFerma("ferma mea", 20, 20));
//	lista = inserareInceput(lista, initializareFerma("Ferma vedetelor", 5, 7));
//	lista = inserareInceput(lista, initializareFerma("Avicola", 2000, 200));
//
//	afisareListaFerme(lista);
//
//	inserareDupaOFerma(lista, initializareFerma("FermaNoua", 200, 40),"Avicola");
//
//	afisareListaFerme(lista);
//	stergereListaFerme(lista);
//	afisareListaFerme(lista);
//}
