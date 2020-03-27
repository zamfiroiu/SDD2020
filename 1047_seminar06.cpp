//#include<stdio.h>
//#include<string>
//struct Curs {
//	char* materie;
//	int nrCredite;
//};
//
//struct Nod {
//	Curs info;
//	Nod* next;
//};
//
//Curs creareCurs(const char* materie, int credite) {
//	Curs c;
//	c.materie = (char*)malloc(sizeof(char)*(strlen(materie) + 1));
//	strcpy(c.materie, materie);
//	c.nrCredite = credite;
//
//	return c;
//}
//
//void afisareCurs(Curs c) {
//	printf("Cursul %s are %d credite.\n", c.materie, c.nrCredite);
//}
//
//void push(Nod* &stiva, Curs c) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = c;
//	nou->next = stiva;
//	stiva = nou;
//}
//
//Curs pop(Nod* & stiva) {
//	Curs rezultat = stiva->info;
//	Nod* aux = stiva;
//	stiva = stiva->next;
//	free(aux);
//	return rezultat;
//}
//
//int sumaCredite(Nod* &stiva) {
//	Nod* copie = NULL;
//	int suma = 0;
//	while(stiva) {
//		Curs c = pop(stiva);
//		suma += c.nrCredite;
//		push(copie, c);
//	}
//	while (copie) {
//		push(stiva, pop(copie));
//	}
//
//	return suma;
//}
//
//void stergeCurs(Nod* &stiva, const char* materie) {
//	Nod* copie = NULL;
//	while (stiva && strcmp(stiva->info.materie,materie)!=0) {
//		push(copie, pop(stiva));
//	}
//	Curs c = pop(stiva);
//	free(c.materie);
//	while (copie) {
//		push(stiva, pop(copie));
//	}
//}
//
//void afisareStiva(Nod* &stiva) {
//	while (stiva) {
//		Curs c = pop(stiva);
//		afisareCurs(c);
//		free(c.materie);
//	}
//}
//
//void creareVector(Nod* stiva, Curs*&cursuri, int & nrCursuri, int prag) {
//	Nod*copie = NULL;
//	int contor = 0;
//	while (stiva) {
//		Curs c = pop(stiva);
//		push(copie, c);
//		if (c.nrCredite >= prag) {
//			contor++;
//		}
//	}
//	cursuri = (Curs*)malloc(sizeof(Curs)*contor);
//	nrCursuri = contor;
//	while (copie) {
//		Curs c = pop(copie);
//		push(stiva, c);
//		if (c.nrCredite >= prag) {
//			cursuri[--contor] = c;
//			cursuri[contor].materie = (char*)malloc(sizeof(char)*(strlen(c.materie) + 1));
//			strcpy(cursuri[contor].materie, c.materie);
//		}
//	}
//}
//
//void main() {
//	Nod* stiva = NULL;
//	push(stiva, creareCurs("SDD", 5));
//	push(stiva, creareCurs("POO", 4));
//	push(stiva, creareCurs("PAW", 5));
//
//	//afisareCurs(pop(stiva));
//
//	printf("Numar total de credite: %d \n", sumaCredite(stiva));
//
//	stergeCurs(stiva, "POO");
//	printf("Numar total de credite: %d \n\n", sumaCredite(stiva));
//
//	Curs* cursuri = NULL;
//	int dimensiune = 0;
//	creareVector(stiva, cursuri, dimensiune, 5);
//	for (int i = 0; i < dimensiune; i++) {
//		afisareCurs(cursuri[i]);
//	}
//	afisareStiva(stiva);
//}