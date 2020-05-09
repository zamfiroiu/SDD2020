//#include<stdio.h>
//#include<string>
//struct Mesaj {
//	char* text;
//	int prioritate;
//};
//
//Mesaj initMesaj(const char* text, int prioritate) {
//	Mesaj m;
//	m.prioritate = prioritate;
//	m.text = (char*)malloc(sizeof(char)*(strlen(text) + 1));
//	strcpy(m.text, text);
//
//	return m;
//}
//
//void afisareMesaj(Mesaj m) {
//	printf("%d.%s\n", m.prioritate, m.text);
//}
//
//struct HEAP {
//	Mesaj* vect;
//	int dim;
//};
//
//HEAP initHeap(int dim) {
//	HEAP h;
//	h.vect = (Mesaj*)malloc(sizeof(Mesaj)*dim);
//	h.dim = dim;
//	return h;
//}
//
//void filtrare(HEAP h, int poz) {
//	if (h.dim > 0) {
//		int pD = 2 * poz + 2;
//		int pS = 2 * poz + 1;
//		int pozMax = poz;
//		if (pS<h.dim && h.vect[pozMax].prioritate < h.vect[pS].prioritate) {
//			pozMax = pS;
//		}	
//		if (pD<h.dim && h.vect[pozMax].prioritate < h.vect[pD].prioritate) {
//			pozMax = pD;
//		}
//		if (pozMax != poz) {
//			Mesaj aux = h.vect[poz];
//			h.vect[poz] = h.vect[pozMax];
//			h.vect[pozMax] = aux;
//			if (pozMax * 2 + 1 < h.dim) {
//				filtrare(h, pozMax);
//			}
//		}
//	}
//}
//
//void main()
//{
//	HEAP h=initHeap(5);
//	h.vect[0] = initMesaj("Mesaj 4", 4);
//	h.vect[1] = initMesaj("Buna", 7);
//	h.vect[2] = initMesaj("Ce faci", 1);
//	h.vect[3] = initMesaj("Dormi?", 9);
//	h.vect[4] = initMesaj("Bine", 2);
//
//	for (int i = (h.dim - 2) / 2; i >= 0; i--) {
//		filtrare(h, i);
//	}
//
//	afisareMesaj(h.vect[0]);
//}