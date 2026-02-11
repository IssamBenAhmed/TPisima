#include <stdio.h>
#include <string.h>
#include "romains.h"


int chiffreRomainToDecimal(char chiffreRomain){
	char chiffres[]={'M','D','C','L','X','V','I','f'};
	int valeursDecimales[]={1000,500,100,50,10,5,1};
	int decimal=0;
	for (int i = 0; chiffres[i]!='f';i++){
		if (chiffres[i]==chiffreRomain){
			decimal=valeursDecimales[i];
		}
	}
	return decimal;
}


int nombreRomainToDecimal(char* strRomain){
	
	printf("Entree dans nombreRomainToDecimal ,  chiffreRomain=%s\n",strRomain);
	int decimal=0;

	// TO DO question 1


	printf("Sortie de nombreRomainToDecimal ,  chiffreRomain=%s , valeur retournee :%d\n",strRomain,decimal);
	return decimal;
}
