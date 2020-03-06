#include<stdio.h>
#include<string>

struct Virus {
	char* nume;
	float diametru;
	int nrZileIncubatie;
};

Virus initializareVirus(const char* nume, float diametru, int nrZile) {
	Virus v;
	//v.nume = new char[strlen(nume) + 1];
	v.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
	strcpy(v.nume, nume);
	v.diametru = diametru;
	v.nrZileIncubatie = nrZile;

	return v;
}

void afisareVirus(Virus *v){
	printf("Virusul %s are un diametru de %5.2f microni si %d zile incubatie.\n",
		(*v).nume, (*v).diametru, (*v).nrZileIncubatie);
}

void main() {

	Virus virus;

	virus = initializareVirus("SARS", 2, 7);

	afisareVirus(&virus);
	free(virus.nume);


	Virus* pv;

	pv = (Virus*)malloc(sizeof(Virus));

	*pv=initializareVirus("Covid-19", 3, 28);
	afisareVirus(pv);

	free(pv->nume);
	free(pv);

	Virus* vv;
	int nrVirusi = 5;
	vv = (Virus*)malloc(nrVirusi * sizeof(Virus));
	for (int i = 0; i < nrVirusi; i++) {
		vv[i] = initializareVirus("AH1N1", 2.5, (i+1)*3);
	}
	for (int i = 0; i < nrVirusi; i++) {
		afisareVirus(vv+i);
	}

	for (int i = 0; i < nrVirusi; i++) {
		free(vv[i].nume);
	}
	free(vv);

	Virus**vpv;
	int nrPointeri = 3;
	vpv = (Virus**)malloc(sizeof(Virus*)*nrPointeri);
	for (int i = 0; i < nrPointeri; i++) {
		vpv[i] = (Virus*)malloc(sizeof(Virus));
		*(*vpv + i) = initializareVirus("gripa romaneasca", 1, 2);
		//*vpv[i]
	}

}