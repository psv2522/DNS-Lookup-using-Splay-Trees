#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include"st.h"

int countlines(){
    FILE *fp;
    fp=fopen("data.txt","r");
    if(!fp){
        printf("Can't Open File");
    }
    int count = 0;
    char c;
    for(c = getc(fp); c != EOF; c = getc(fp)){
        if(c == '\n'){
            count = count + 1;
        }
    }
    return count;
}

int main(){

    st root;
    init_st(&root);
    char site[100];
    char ipaddress[100];
    FILE *fp;
    fp=fopen("data.txt","r");
    if(!fp){
        printf("Can't Open File");
    }

    int count = countlines(fp);
    
    for(int i = 1; i<count; i++){
        fscanf(fp, "%s - %s", site, ipaddress);
        InsertNode(&root, site, ipaddress); 
    }
    fclose(fp);

    int option;
    int n;

    do{
        int a = 1;
        
        printf("\nChoose any of the following options : \n");
		printf("1 Search for site/s\n");
		printf("2 Insert new site and its ipaddress\n");
        printf("3 Delete site/s\n");
		printf("4 Inorder traversal\n");
		printf("5 Exit.\n");
		printf("Enter option : ");
		scanf("%d", &option);
		printf("\n");

        switch (option)
        {
        case 1:
        {
            while(a){
			    printf("\nEnter the site you want to search : ");
                scanf("%s", site);
        		Search(&root, site);
                printf("\nDo you want to search more sites? If Yes enter 1, else 0: ");
			    scanf("%d", &a);
		    }
            break;
                
        }

        case 2:
        {
        	while(a){
			    printf("\nEnter the site to be inserted : ");
                scanf("%s", site);
                printf("Enter its ipaddress : ");
                scanf("%s", ipaddress);
        		InsertNode(&root, site, ipaddress); 
                printf("\nDo you want to insert more sites? If Yes enter 1, otherwise 0: ");
			    scanf("%d", &a);
		    }
            break;
        }

        case 3:
        {
            while(a){
			    printf("\nEnter the site to be deleted : ");
                scanf("%s", site); 
                Delete(&root, site);
                printf("\nDo you want to delete more sites? If Yes enter 1, otherwise 0: ");
			    scanf("%d", &a);
		    }
            break;
        }

        case 4:
        {
            int n = 1;
            printf("|------------------------------------------------------|\n");
            printf("| No. |  %-16s     |  %-16s      |\n", "site", "ipaddress");
            printf("|------------------------------------------------------|\n");
    		inorder(root, &n);
            printf("|------------------------------------------------------|\n");
    		break;
        }

        case 5:
        {
            exit(0);
            break;
        }

        default:
            printf("Please choose valid option!!\n");
        }
    }while(option> 0 && option <6);
}