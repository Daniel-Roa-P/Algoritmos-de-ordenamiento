#include <iostream>

using namespace std;

int arreglo[]={3,5,7,4,1,8,9,5,2,9,11,5};

void seleccion(int arreglo[],int cantidad){

	int i,j,menor,temp;
	
	for(i=0;i<cantidad;i++){
		
		menor=i;
		
		for(j=i+1;j<cantidad;j++){
			
			if(arreglo[j]<arreglo[menor]){
				
				menor=j;
				
			}
		}	
		
		temp=arreglo[menor];
		arreglo[menor]=arreglo[i];
		arreglo[i]=temp;
			
		}	

}

void insercion(int arreglo[],int cantidad){
	
	
	int i,j,valor;
	
	for(i=1;i<cantidad;i++){
		
		valor=arreglo[i];
		j=i-1;
		
		while((arreglo[j]>valor)&&(j>=0)){
			
			arreglo[j+1]=arreglo[j];
			j--;
			
		}
		
		arreglo[j+1]=valor;
		
		}
		
	}

int main(){

	for(int k = 0 ; k<12 ;k++){
			
			cout<<arreglo[k]<<" ";
			
		}
	
	cout<<endl;
	
	/*seleccion(arreglo,12);*/
	insercion(arreglo,12);
	
	for(int k = 0 ; k<12 ;k++){
			
			cout<<arreglo[k]<<" ";
			
		}
	
}
