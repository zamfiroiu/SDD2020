//#include<stdio.h>
//#include<string>
//
//struct Mesaj {
//	char* continut;
//	int prioritate;
//};
//
//Mesaj initMesaj(const char* continut, int prioritate) {
//	Mesaj m;
//	m.continut = (char*)malloc(sizeof(char)*(strlen(continut) + 1));
//	strcpy(m.continut, continut);
//	m.prioritate = prioritate;
//
//	return m;
//}
//
//void afisareMesaj(Mesaj m) {
//	printf("%d.%s\n", m.prioritate, m.continut);
//}
//
//struct HEAP {
//	Mesaj * mesaje;
//	int dim;
//};
//
//HEAP initHeap(int dim) {
//	HEAP h;
//	h.mesaje = (Mesaj*)malloc(sizeof(Mesaj)*dim);
//	h.dim = dim;
//	return h;
//}
//
//void filtrare(HEAP h, int poz) {
//	if (h.dim > 0) {
//		int pS = 2 * poz + 1;
//		int pD = 2 * poz + 2;
//		int pozMax = poz;
//		if (pS<h.dim && h.mesaje[pozMax].prioritate < h.mesaje[pS].prioritate) {
//			pozMax = pS;
//		}
//		if (pD<h.dim &&h.mesaje[pozMax].prioritate < h.mesaje[pD].prioritate) {
//			pozMax = pD;
//		}
//		if (pozMax != poz) {
//			Mesaj aux = h.mesaje[poz];
//			h.mesaje[poz] = h.mesaje[pozMax];
//			h.mesaje[pozMax] = aux;
//			if (2 * pozMax + 1 < h.dim) {
//				filtrare(h, pozMax);
//			}
//		}
//	}
//}
//
//void afisareHEAP(HEAP h) {
//	for (int i = 0; i < h.dim; i++) {
//		afisareMesaj(h.mesaje[i]);
//	}
//}
//
//void main() {
//	HEAP h=initHeap(6);
//	h.mesaje[0] = initMesaj("Buna", 1);
//	h.mesaje[1] = initMesaj("ce faci", 6);
//	h.mesaje[2] = initMesaj("?", 4);
//	h.mesaje[3] = initMesaj("hello", 2);
//	h.mesaje[4] = initMesaj("bine", 8);
//	h.mesaje[5] = initMesaj("neata", 5);
//
//	afisareHEAP(h);
//	for (int i = (h.dim - 2) / 2; i >= 0; i--) {
//		filtrare(h, i);
//	}
//	printf("\n\n");
//	afisareHEAP(h);
//
//}