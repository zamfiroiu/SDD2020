//#include<stdio.h>
//#include<string>
//
//struct Restaurant {
//	char* nume;
//	int capacitate;
//	float cifraAfaceri;
//};
//
//Restaurant initializareRestaurant(const char* nume, int capacitate, float ca) {
//	Restaurant r;
//	//r.nume = new char[strlen(nume) + 1];
//	r.nume = (char*)malloc(sizeof(char)*(strlen(nume) + 1));
//	strcpy(r.nume, nume);
//	r.capacitate = capacitate;
//	r.cifraAfaceri = ca;
//	return r;
//}
//
//void afisareRestaurant(Restaurant r) {
//	printf("Restaurantul %s are o capacitate de %d locuri si o cifra de afaceri de %5.2f EUR.\n",
//		r.nume,r.capacitate,r.cifraAfaceri);
//}
//
//void main() {
//
//	Restaurant restaurant;
//	restaurant = initializareRestaurant("Mandaloun", 100, 3000);
//	afisareRestaurant(restaurant);
//	free(restaurant.nume);
//
//	Restaurant* pr;
//	pr = (Restaurant*)malloc(sizeof(Restaurant));
//	*pr = initializareRestaurant("Ciorbarie", 7, 1000);
//	afisareRestaurant(*pr);
//
//	free((*pr).nume);//free(pr->nume);
//	free(pr);
//
//	Restaurant * vr;
//	int nrRestaurante = 3;
//	vr = (Restaurant*)malloc(sizeof(Restaurant)*nrRestaurante);
//	for (int i = 0; i < nrRestaurante; i++) {
//		vr[i] = initializareRestaurant("KFC", (i + 1) * 5, i * 2000);
//	}
//
//	for (int i = 0; i < nrRestaurante; i++) {
//		afisareRestaurant(vr[i]);
//	}
//
//	for (int i = 0; i < nrRestaurante; i++) {
//		free(vr[i].nume);
//	}
//	free(vr);
//
//	Restaurant ** vpr;
//	int nrPointeri = 4;
//	vpr = (Restaurant**)malloc(sizeof(Restaurant*)*nrPointeri);
//	for (int i = 0; i < nrPointeri; i++) {
//		vpr[i] = (Restaurant*)malloc(sizeof(Restaurant));
//		*vpr[i] = initializareRestaurant("La placinte", i * 20, i * 1000);
//	}
//
//	for (int i = 0; i < nrPointeri; i++) {
//		afisareRestaurant(*vpr[i]);
//	}
//
//
//	for (int i = 0; i < nrPointeri; i++) {
//		free(vpr[i]->nume);//free((*vpr[i]).nume);
//		free(vpr[i]);
//	}
//	free(vpr);
//
//
//
//}