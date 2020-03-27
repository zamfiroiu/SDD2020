//#include<stdio.h>
//#include<string>
//
//struct Muzeu {
//	char* denumire;
//	int nrVizitatori;
//};
//
//struct Nod {
//	Muzeu info;
//	Nod* next;
//};
//
//Muzeu creareMuzeu(const char* denumire, int nr) {
//	Muzeu m;
//	m.denumire = (char*)malloc(sizeof(char)*(strlen(denumire) + 1));
//	strcpy(m.denumire, denumire);
//	m.nrVizitatori = nr;
//	return m;
//}
//
//void afisareMuzeu(Muzeu m) {
//	printf("Muzeul %s are %d vizitatori.\n", m.denumire, m.nrVizitatori);
//}
//
//void push(Nod* &first, Muzeu m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = m;
//	nou->next = first;
//	first = nou;
//}
//
//Muzeu pop(Nod* & first) {
//	if (first) {
//		Muzeu rez = first->info;
//		Nod* temp = first;
//		first = first->next;
//		free(temp);
//		return rez;
//	}
//}
//
//void afisareStiva(Nod*& stiva) {
//	while (stiva) {
//		Muzeu m = pop(stiva);
//		afisareMuzeu(m);
//		free(m.denumire);
//	}
//}
//
//int CalculareNumarVizitatori(Nod* &stiva) {
//	int suma = 0;
//	Nod* copie = NULL;
//	while (stiva) {
//		Muzeu m = pop(stiva);
//		suma += m.nrVizitatori;
//		push(copie, m);
//	}
//	while (copie) {
//		push(stiva, pop(copie));
//	}
//	return suma;
//}
//
//void stergereMuzeu(Nod* &stiva, const char* den) {
//	Nod* copie = NULL;
//	while (stiva && strcmp(stiva->info.denumire, den) != 0) {
//		push(copie, pop(stiva));
//	}
//	if (stiva) {
//		Muzeu m=pop(stiva);
//		free(m.denumire);
//	}
//	while (copie) {
//		push(stiva, pop(copie));
//	}
//}
//
//void main() {
//	Nod* stiva = NULL;
//	push(stiva, creareMuzeu("Antipa", 7000));
//	push(stiva, creareMuzeu("Arta", 6500));
//	push(stiva, creareMuzeu("Istorie", 5000));
//
//	afisareMuzeu(pop(stiva));
//
//	printf("Numarul total: %d\n\n", CalculareNumarVizitatori(stiva));
//	stergereMuzeu(stiva, "Arta");
//	afisareStiva(stiva);
//}