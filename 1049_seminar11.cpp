//#include<stdio.h>
//#include<string>
//
//struct Mesaj {
//	int prioritate;
//	char* text;
//};
//
//void afisareMesaj(Mesaj m) {
//	printf("%d.%s\n", m.prioritate, m.text);
//}
//
//Mesaj initMesaj(const char* text, int prioritate) {
//	Mesaj m;
//	m.prioritate = prioritate;
//	m.text = (char*)malloc(sizeof(char)*(strlen(text) + 1));
//	strcpy(m.text, text);
//	return m;
//}
//
//struct HEAP {
//	Mesaj* vector;
//	int dim;
//};
//
//HEAP initHeap(int dim) {
//	HEAP h;
//	h.dim = dim;
//	h.vector = (Mesaj*)malloc(sizeof(Mesaj)*dim);
//	return h;
//}
//
//
//
//void filtrare(HEAP h, int poz) {
//	if (h.dim > 0) {
//		int pS = 2 * poz + 1;
//		int pD = 2 * poz + 2;
//		int pozMax = poz;
//		if (pS<h.dim && h.vector[pS].prioritate > h.vector[pozMax].prioritate) {
//			pozMax = pS;
//		}
//		if (pD<h.dim && h.vector[pD].prioritate > h.vector[pozMax].prioritate) {
//			pozMax = pD;
//		}
//		if (pozMax != poz) {
//			Mesaj aux = h.vector[poz];
//			h.vector[poz] = h.vector[pozMax];
//			h.vector[pozMax] = aux;
//			if (2 * pozMax + 1 < h.dim) {
//				filtrare(h, pozMax);
//			}
//		}
//	}
//}
//
//void afisareHeap(HEAP h) {
//	for (int i = 0; i < h.dim; i++) {
//		afisareMesaj(h.vector[i]);
//	}
//}
//
//Mesaj extrageMesajDinHeap(HEAP &h) {
//	if (h.dim > 0) {
//		Mesaj rezultat= h.vector[0];
//		Mesaj* temp = (Mesaj*)malloc(sizeof(Mesaj)*(h.dim - 1));
//		for (int i = 1; i < h.dim; i++) {
//			temp[i - 1] = h.vector[i];
//		}
//		free(h.vector);
//		h.vector = temp;
//		h.dim--;
//		for (int i = (h.dim - 2) / 2; i >= 0; i--) {
//			filtrare(h, i);
//		}
//		return rezultat;
//	}
//	else {
//		throw "NU avem heap";
//	}
//}
//
//void main() {
//	HEAP h=initHeap(6);
//	h.vector[0] = initMesaj("mesaj 1", 1);
//	h.vector[1] = initMesaj("buna", 6);
//	h.vector[2] = initMesaj("hey ", 4);
//	h.vector[3] = initMesaj("ce faci", 2);
//	h.vector[4] = initMesaj("bine", 8);
//	h.vector[5] = initMesaj("ma bucur", 5);
//
//	afisareHeap(h);
//	for (int i = (h.dim - 2) / 2; i >= 0; i--) {
//		filtrare(h, i);
//	}
//	printf("\n\n");
//	afisareHeap(h);
//
//	printf("\n\nExtragere:\n");
//	try {
//		Mesaj m = extrageMesajDinHeap(h);
//		afisareMesaj(m);
//		free(m.text);
//	}
//	catch (...) {
//		printf("NU avem heap.");
//	}
//
//	printf("\n\nDupa extragere:\n");
//	afisareHeap(h);
//
//}