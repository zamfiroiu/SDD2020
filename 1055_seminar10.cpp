#include<stdio.h>
#include<string>

struct Mesaj {
	char* text;
	int prioritate;
};

void afisareMesaj(Mesaj m) {
	printf("%d.%s\n", m.prioritate, m.text);
}

Mesaj initMesaj(const char* text, int prioritate) {
	Mesaj m;
	m.prioritate = prioritate;
	m.text = (char*)malloc(sizeof(char)*(strlen(text) + 1));
	strcpy(m.text, text);
	return m;
}
struct HEAP {
	Mesaj* vector;
	int dim;
};

HEAP initHeap(int dim) {
	HEAP h;
	h.dim = dim;
	h.vector = (Mesaj*)malloc(sizeof(Mesaj)*dim);
	return h;
}

void filtrare(HEAP hp, int poz) {
	if (hp.dim > 0) {
		int pS = 2 * poz + 1;
		int pD = 2 * poz + 2;
		int pozMax = poz;
		if (pS<hp.dim && hp.vector[pS].prioritate > hp.vector[pozMax].prioritate) {
			pozMax = pS;
		}
		if (pD<hp.dim && hp.vector[pD].prioritate > hp.vector[pozMax].prioritate) {
			pozMax = pD;
		}
		if (pozMax != poz) {
			Mesaj aux = hp.vector[poz];
			hp.vector[poz] = hp.vector[pozMax];
			hp.vector[pozMax] = aux;
			if (2 * pozMax + 1 < hp.dim) {
				filtrare(hp, pozMax);
			}
		}
	}
}

void afisareHeap(HEAP h) {
	for (int i = 0; i < h.dim; i++) {
		afisareMesaj(h.vector[i]);
	}
}

void main() {
	HEAP h=initHeap(6);
	h.vector[0] = initMesaj("mesaj 1", 1);
	h.vector[1] = initMesaj("buna", 6);
	h.vector[2] = initMesaj("hey ", 4);
	h.vector[3] = initMesaj("ce faci", 2);
	h.vector[4] = initMesaj("bine", 8);
	h.vector[5] = initMesaj("ma bucur", 5);
	afisareHeap(h);
	for (int i = (h.dim - 2) / 2; i >= 0; i--) {
		filtrare(h,i);
	}
	printf("\n\n");
	afisareHeap(h);
}
