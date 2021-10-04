#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXCHAR 1000

int main(){
	
	unsigned int ip_from[4];	    
	int ip_to; 	        
	char country_code; 	
	char country_name; 	
	char region_name; 	
	char city_name; 	    
	double latitude; 	   
	double longitude; 
	unsigned int cal;
	int res;
	
	printf("saisir l'adresse ip \n");
	scanf("%d.%d.%d.%d", &ip_from[0], &ip_from[1], &ip_from[2], &ip_from[3]);

    cal = ip_from[0]* 256 * 256 * 256 + ip_from[1] * 256 * 256 + ip_from[2] * 256 + ip_from[3];
    
    res = abs(cal);
    
    printf("%ld",cal);

    FILE *fp;
    char Ligne[MAXCHAR];
    char *Sortie;


    fp = fopen("geoip.csv","r");


    while (feof(fp) != true)
    {
        fgets(Ligne, MAXCHAR, fp);
        printf("Ligne: %s", Ligne);

        Sortie = strtok(Ligne, ",");

        while(Sortie != NULL)
        {
            printf("Sortie: %s\n", Sortie);
            Sortie = strtok(NULL, ",");
        }

    } 

    return 0;

}
