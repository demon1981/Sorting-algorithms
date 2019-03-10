/*

Реализация различных алгоритмов сортировки простого массива
Реализация работы на указателях и динамическом выделении памияти

*/
#include <stdio.h>  
#include <stdlib.h>
#include<locale.h>  

//#define arreySize 5
//#define NUM_LIMIT 100

void bulbSort(int, int*);
void selectSort(int, int*);
void insertSort(int, int*);
void mergeSort(int*, int, int);
void chgArreyCell(int*,int*);

int main() {
	setlocale(LC_ALL, "RUS");

	int arreySize;
	int *Arr;
		
	printf("Введите размер массива: ");
	scanf("%d", &arreySize); 
	
	Arr = (int*) malloc(arreySize * sizeof(int));
		
	for(int i=0; i<arreySize; i++){
		Arr[i] = rand()%arreySize;
	}
	
	/*printf("Содержимое массива:\n");
	for(int i=0; i<arreySize; i++){
		printf("%d ", Arr[i]);
	}*/
	
	//mergeSort(Arr, 0, arreySize-1);

	int algorithmNum = 0;
	printf("\nВыбирите алгоритм сортировки (1-bulb, 2-select, 3-insert, 4-merge): ");
	scanf("%d", &algorithmNum);
	
	switch(algorithmNum){
	    case 1: 
	        bulbSort(arreySize, Arr);
	        break;
	    case 2: 
	        selectSort(arreySize, Arr);
	        break;
		case 3: 
	        insertSort(arreySize, Arr);
	        break;
		case 4: 
	        mergeSort(Arr, 0, arreySize-1);
	        break;
	    default:
	    	printf("Неправильный номер алгоритма сортировки!!!\n");
	}
	
	printf("\nПроверка правильности сортировки:\n");	
	for(int i=1; i<arreySize; i++){
		if(Arr[i-1]>Arr[i]) printf("%d ", i);
	}
	
	
	/*printf("\nОтсортированный массив:\n");	
	for(int i=0; i<arreySize; i++){
		printf("%d ", Arr[i]);
	}*/
	
	free(Arr);	
}

void mergeSort(int *Arr, int a, int b){			
	//если массив разбиваеться больше чем на 1 элемент рекурсивно вызываем сортировку для этих половинок.		
	
	int tempArrSize = b-a+1;//размер временного массива для сортировки
	
	int c;//конец первого массива
	//учтем случаи с нечетным количеством элементов массива
	if (tempArrSize % 2 > 0)  
		c = a + (tempArrSize / 2);	
	else  
		c = a + ((tempArrSize / 2) - 1);


	if(b-a	> 1){	
		mergeSort(Arr, a, c);//a, a+(tempArrSize/2)-1);					
		mergeSort(Arr, c+1, b);//b-(tempArrSize/2)+1, b);			
	} 					
			
	int *tempArr = (int*) malloc((tempArrSize) * sizeof(int));		
	
	//расставляем индексы для обхода массива, к - индекс для временного массива, начинаеться с 0, инкремируем только его 	
	for(int i=a, j=c+1, k=0; k < tempArrSize; k++){		
		if(j==b+1){
			tempArr[k] = Arr[i];
			i++;
		} 		
		else if(i==c+1){
			tempArr[k] = Arr[j];			
			j++;
		}
		else{
			if(Arr[i] > Arr[j]){
				tempArr[k] = Arr[j];						
				j++;
			}				
			else{
				tempArr[k] = Arr[i];							
				i++;
			}				
		} 				
	}	
	//переносим данные из времменого масива в основной
	for(int i=0; i<tempArrSize; i++){		
		Arr[i + a] = tempArr[i];
	}		
	free(tempArr);
}

void insertSort(int arreySize, int *Arr){
	/*При передаче массива, передаеться указатель, разыменование происходит в скобках функции
	работа происходит с темже массивом что и в main()*/	
		
	for(int i = 1; i < arreySize; i++){		
		for(int j = i; j > 0 && Arr[j] < Arr[j-1]; j--){
			chgArreyCell(&Arr[j], &Arr[j-1]);				
		}
	}	
}

void bulbSort(int arreySize, int *arrey){
	/*При передаче массива, передаеться указатель, разыменование происходит в скобках функции
	работа происходит с темже массивом что и в main()*/	
	int chg = 0;

	while(arreySize != 1){	
		for(int i = 0; i<arreySize-1; i++) {			
			if(arrey[i] > arrey[i+1]){							
				chgArreyCell(&arrey[i], &arrey[i+1]);	
			}
		}
		arreySize--;		
	}			
}

void selectSort(int arreySize, int *Arr){
	/*При передаче массива, передаеться указатель, разыменование происходит в скобках функции
	работа происходит с темже массивом что и в main()*/	
		
	int min = 0;
	int chg = 0;
	int firstSort = 0;
	while(firstSort!=arreySize){
		for(int i = firstSort; i < arreySize; i++){			
			if(Arr[i] < Arr[min]){
				min = i;								
			}			 			
		}			
		if(min>firstSort){
			chgArreyCell(&Arr[min], &Arr[firstSort]);
		}			
		min = ++firstSort;	
	}
}

void chgArreyCell(int *a, int *b){
	int chg = *a;
	*a = *b;
	*b = chg;		
}

