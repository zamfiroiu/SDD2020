#include<iostream>

struct Copac {
	char* culoareFrunze;
	int nrFrunze;
	float inaltime;//in metri
};

Copac initialiazareCopac(const char* culoare, int nrFrunze, float inaltime) {
	Copac c;
	c.nrFrunze = nrFrunze;
	c.inaltime = inaltime;
	//c.culoareFrunze = new char[strlen(culoare) + 1];
	c.culoareFrunze = (char*)malloc(sizeof(char)*(strlen(culoare) + 1));
	strcpy(c.culoareFrunze, culoare);
	return c;
}

void afisareCopac(Copac c) {
	printf("Culoare: %s, Numar frunze: %d, Inaltime: %5.2f\n",
		c.culoareFrunze, c.nrFrunze, c.inaltime);
}


void main() {

	Copac copac = initialiazareCopac("Verde", 369, 3.57);
	afisareCopac(copac);

	Copac* pc;
	//pc = (Copac*)malloc(sizeof(Copac));
	pc = &initialiazareCopac("Rosie", 658, 5.78);
	afisareCopac(*pc);
	
	int nrCopaci = 3;
	Copac* vector;
	vector = (Copac*)malloc(sizeof(Copac)*nrCopaci);
	for (int i = 0; i < nrCopaci; i++) {
		vector[i].culoareFrunze = (char*)malloc(sizeof(char)*(strlen("Verde") + 1));
		strcpy(vector[i].culoareFrunze, "Verde");
		vector[i].nrFrunze = (i + 1) * 100;
		vector[i].inaltime = i + 0.6;
	}

	afisareCopac(*vector);
	afisareCopac(*(vector + 1));
	afisareCopac(*(vector + 2));

	int nrPoineri = 5;
	Copac* *pointeri;
	pointeri = (Copac**)malloc(sizeof(Copac*)*nrPoineri);
	for (int i = 0; i < nrPoineri; i++) {
		pointeri[i] = (Copac*)malloc(sizeof(Copac));
		(*pointeri[i]).culoareFrunze = (char*)malloc(sizeof(char)*(strlen("Verde") + 1));
		strcpy((*pointeri[i]).culoareFrunze, "Verde");
		(*pointeri[i]).nrFrunze = (i + 1) * 100;
		(*pointeri[i]).inaltime = i + 0.6;
	}

	for (int i = 0; i < nrPoineri; i++) {
		afisareCopac(*pointeri[i]);
	}


	
	
	

}