//#include<stdio.h>
//#include<string>
//
//struct Biblioteca {
//	char* denumire;
//	int nrCarti;
//};
//
//struct Nod {
//	Biblioteca info;
//	Nod*next;
//};
//
//Biblioteca initBiblioteca(const char* denumire, int nr) {
//	Biblioteca b;
//	b.denumire = (char*)malloc(sizeof(char)*(strlen(denumire) + 1));
//	strcpy(b.denumire, denumire);
//	b.nrCarti = nr;
//	return b;
//}
//
//void afisareBiblioteca(Biblioteca b) {
//	printf("Biblioteca %s are %d carti.\n", b.denumire, b.nrCarti);
//}
//
//void push(Nod* &cap, Biblioteca b) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = b;
//	nou->next = cap;
//	cap = nou;
//}
//
//Biblioteca pop(Nod* * cap) {
//	if (*cap) {
//		Nod*temp = *cap;
//		Biblioteca rez = initBiblioteca(temp->info.denumire, temp->info.nrCarti);
//		(*cap) = (*cap)->next;
//		free(temp->info.denumire);
//		free(temp);
//		return rez;
//	}
//}
//
//int nrTotalCarti(Nod* &stiva) {
//	int nr = 0;
//	Nod* copie = NULL;
//	while (stiva) {
//		Biblioteca b = pop(&stiva);
//		nr += b.nrCarti;
//		push(copie, b);
//	}
//	while (copie) {
//		push(stiva, pop(&copie));
//	}
//	return nr;
//}
//
//void stergereBilioteca(Nod* &stiva, const char* nume) {
//	Nod* copie = NULL;
//	while (stiva && strcmp(stiva->info.denumire, nume) != 0)
//	{
//		push(copie, pop(&stiva));
//	}
//	Biblioteca b = pop(&stiva);
//	free(b.denumire);
//	while (copie) {
//		push(stiva, pop(&copie));
//	}
//}
//
//void main() {
//	Nod* stiva = NULL;
//	push(stiva, initBiblioteca("Eminescu", 1000));
//	push(stiva, initBiblioteca("Sadoveanu", 600));
//	push(stiva, initBiblioteca("Centrala", 1400));
//
//	//afisareBiblioteca(pop(&stiva));
//
//	printf("Nr carti: %d\n", nrTotalCarti(stiva));
//	
//}