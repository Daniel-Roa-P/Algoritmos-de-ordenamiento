#include <iostream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

int* arreglo;
int n, caso, opcion;

void mejor() {

	for (int k = 0; k < n; k++) {

		arreglo[k] = k;
		cout << arreglo[k] << " ";

	}

}

void peor() {

	int l = 0;

	for (int k = n; k > 0; k--) {

		arreglo[l] = k;
		cout << arreglo[l] << " ";
		l++;

	}

}

void burbuja(int arreglo[], int cantidad) {

	int i, j, aux;

	for (i = 0; i < cantidad; i++) {

		for (j = i + 1; j < cantidad; j++) {

			if (arreglo[j] < arreglo[i]) {


				aux = arreglo[j];
				arreglo[j] = arreglo[i];
				arreglo[i] = aux;

			}
		}

	}

}

void seleccion(int arreglo[], int cantidad) {

	int i, j, menor, temp;

	for (i = 0; i < cantidad; i++) {

		menor = i;

		for (j = i + 1; j < cantidad; j++) {

			if (arreglo[j] < arreglo[menor]) {

				menor = j;

			}
		}

		temp = arreglo[menor];
		arreglo[menor] = arreglo[i];
		arreglo[i] = temp;

	}

}

void insercion(int arreglo[], int cantidad) {


	int i, j, valor;

	for (i = 1; i < cantidad; i++) {

		valor = arreglo[i];
		j = i - 1;

		while ((arreglo[j] > valor) && (j >= 0)) {

			arreglo[j + 1] = arreglo[j];
			j--;

		}

		arreglo[j + 1] = valor;

	}

}

int main() {

	while (true) {

		cout << "Ingrese el tamaño del arreglo: ";
		cin >> n;
		cout << endl;

		arreglo = new int[n];

		cout << "Ingrese tipo de caso: " << endl;
		cout << "1. Mejor " << endl;
		cout << "2. Peor " << endl;
		cin >> caso;
		cout << endl;

		switch (caso) {

		case 1:
			mejor();
			break;
		case 2:
			peor();
			break;

		}

		cout << endl;
		cout << "Ingrese algoritmo a usar: " << endl;
		cout << "1. Seleccion " << endl;
		cout << "2. Insercion " << endl;
		cout << "3. Burbuja " << endl;
		cin >> opcion;
		cout << endl;


		if (opcion == 1) {

			auto inicio = std::chrono::high_resolution_clock::now();

			seleccion(arreglo, n);

			auto final = std::chrono::high_resolution_clock::now();

			auto dif = final - inicio;

			cout << "El algoritmo de seleccion tardo: " << chrono::duration <double, nano>(dif).count() << " Nano segundos" << endl;

		}
		else if (opcion == 2) {

			auto inicio = std::chrono::high_resolution_clock::now();

			insercion(arreglo, n);

			auto final = std::chrono::high_resolution_clock::now();

			auto dif = final - inicio;

			cout << "El algoritmo de insercion tardo: " << chrono::duration <double, nano>(dif).count() << " Nano segundos" << endl;

		}
		else if (opcion == 3) {

			auto inicio = std::chrono::high_resolution_clock::now();

			burbuja(arreglo, n);

			auto final = std::chrono::high_resolution_clock::now();

			auto dif = final - inicio;

			cout << "El algoritmo de burbuja tardo: " << chrono::duration <double, nano>(dif).count() << " Nano segundos" << endl;

		}

		cout << endl;

		for (int k = 0; k < n; k++) {

			cout << arreglo[k] << " ";

		}

		cout << endl;

		delete arreglo;

	}

		return 0;
}