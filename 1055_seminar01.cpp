#include<stdio.h>
#include<string>

struct Parc {
	float suprafata;
	char* denumire;
	int nrVizitatori;
};

Parc initializareParc(float suprafata, const char*denumire, int nrVizitatori) {
	Parc p;
	p.suprafata = suprafata;
	//p.denumire = new char[strlen(denumire) + 1];
	p.denumire = (char*)malloc(sizeof(char)*(strlen(denumire) + 1));
	strcpy(p.denumire, denumire);
	p.nrVizitatori = nrVizitatori;

	return p;
}

void afisareParc(Parc p) {
	printf("Parcul %s are o suprafata de %5.2f hectare si este vizitat zilnic de %d vizitatori.\n", 
		p.denumire, p.suprafata, p.nrVizitatori);
}

void main() {
	Parc parc;
	parc = initializareParc(20, "Cismigiu", 200);
	afisareParc(parc);
	free(parc.denumire);

	Parc* pp;
	pp = (Parc*)malloc(sizeof(Parc));
	*pp = initializareParc(60, "Mihai I", 1000);
	afisareParc(*pp);

	free((*pp).denumire);
	free(pp);

	Parc* vp;
	int nrParcuri = 4;
	vp = (Parc*)malloc(sizeof(Parc)*nrParcuri);
	for (int i = 0; i < nrParcuri; i++) {
		vp[i] = initializareParc((i + 1) * 10, "Tineretului", i * 100);
		//*(vp+i)
	}
	for (int i = 0; i < nrParcuri; i++) {
		afisareParc(vp[i]);
	}
	for (int i = 0; i < nrParcuri; i++) {
		free(vp[i].denumire);
	}
	free(vp);

	Parc** vpp;
	int nrPointeri = 3;
	vpp = (Parc**)malloc(sizeof(Parc*)*nrPointeri);
	for (int i = 0; i < nrPointeri; i++) {
		vpp[i] = (Parc*)malloc(sizeof(Parc));
		*vpp[i] = initializareParc(10 * i, "Carol I", 100 * i);
	}
	for (int i = 0; i < nrPointeri; i++) {
		afisareParc(*vpp[i]);
	}

	for (int i = 0; i < nrPointeri; i++) {
		free((*vpp[i]).denumire);
		//free(vpp[i]->denumire);
		free(vpp[i]);
	}

	free(vpp);



	





}