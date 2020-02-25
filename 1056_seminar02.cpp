#include<iostream>

struct Calculator {
	char* producator;
	int RAM;
	float capacitate;
	int deschis;
};

Calculator initCalculator(const char* prod, int RAM, float capacitate, int deschis) {
	Calculator c;
	c.producator = (char*)malloc(sizeof(char*)*(strlen(prod) + 1));
	strcpy(c.producator, prod);
	c.RAM = RAM;
	c.capacitate = capacitate;
	c.deschis = deschis;

	return c;
}

void afisareVectorCalculatoare(Calculator* v, int nrCalculatoare) {
	for (int i = 0; i < nrCalculatoare; i++) {
		printf("Calculatorul %s are %d RAM, %5.2f capacitate si este %d\n",
			v[i].producator,v[i].RAM,v[i].capacitate,v[i].deschis);
	}
}
void adaugaCalculator(Calculator* *vector, int *nrCalculatoare, Calculator newOne) {
	Calculator* copie;
	copie = (Calculator*)malloc(sizeof(Calculator)*((*nrCalculatoare) + 1));
	for (int i = 0; i < *nrCalculatoare; i++) {
		copie[i] = (*vector)[i];
	}
	copie[*nrCalculatoare] = newOne;
	(*nrCalculatoare) ++;
	free(*vector);
	(*vector) = copie;
}

void eliminareCalculatoareSlabe(Calculator* *vector, int *nrCalculatoare, float prag)
{
	int nr=0;
	int j = 0;
	for (int i = 0; i < *nrCalculatoare; i++)
		if ((*vector)[i].capacitate >= prag)
			nr++;
	Calculator* copie;
	copie = (Calculator*)malloc(sizeof(Calculator)*nr);
	for (int i = 0; i < *nrCalculatoare; i++)
	{
		if ((*vector)[i].capacitate >= prag)
		{
			copie[j] = (*vector)[i];
			j++;
		}
		else
		{
			free((*vector)[i].producator);
		}
	}
	free(*vector);
	*vector = copie;
	*nrCalculatoare = nr;
}

void main() {
	Calculator* vector;
	int nrCalculatoare = 5;
	vector = (Calculator*)malloc(sizeof(Calculator)*nrCalculatoare);
	for (int i = 0; i < nrCalculatoare; i++) {
		vector[i] = initCalculator("HP", 4 + i, 64 * (i + 1), i % 2);
	}
	Calculator c;
	c = initCalculator("Acer", 12, 1200, 1);
	adaugaCalculator(&vector, &nrCalculatoare, c);
	eliminareCalculatoareSlabe(&vector, &nrCalculatoare, 200);
	afisareVectorCalculatoare(vector, nrCalculatoare);
	for (int i = 0; i < nrCalculatoare; i++) {
		free(vector[i].producator);
	}
	free(vector);
}