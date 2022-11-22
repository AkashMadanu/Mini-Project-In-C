#include<stdio.h>
#define RED "\e[0;31m"
#define LIME "\e[1;32m"
#define CYAN "\e[0;36m"
#define UGREEN "\e[4;32m"
#define YELLOW "\e[0;33m"
#define reset "\e[0m"
#define TOMATO "\e[1;31m"
int main()
{   
       printf(RED "***************************************************************************************\n" reset);
       printf(LIME"<<<<<<<<<<<<<<<<<<<<"CYAN ".......""|||" CYAN "....." YELLOW "PHARMACY MANAGEMANT"CYAN "....." "|||" CYAN "......."LIME ">>>>>>>>>>>>>>>>>>\n" reset);
       printf(RED "***************************************************************************************\n" reset);
       int choice,exit,numberOfCustomers,search;
       printf( "          Enter the number of Customers                       : ");
       scanf("%d",&numberOfCustomers);
       int customerID[numberOfCustomers];
       char customerType[numberOfCustomers];
       int medicineID[numberOfCustomers];
       char medicineName[numberOfCustomers];
       int quantityOfMedicine[numberOfCustomers];
       int GST[numberOfCustomers];
       int totalBill[numberOfCustomers];
       int price[numberOfCustomers];
       int  regularDiscount[numberOfCustomers];

       for(int i = 0; i<numberOfCustomers; i++)
       {
             printf("          Enter the Customer ID                               : ");
             scanf("%d",&customerID[i]);

             printf("          Enter customer Type (Regular - R and Temporary -T   : ");
             scanf(" %c",&customerType[i]);

             printf("          Enter the Medicine ID :                             : ");
             scanf("%d",&medicineID[i]);


             printf("          Enter Medicine name \n          P - paracetamol,\n          L - Levocitrizine,\n          R - Rantac,\n          A - Amoxicillin                                     : ");
             scanf(" %c",&medicineName[i]);

             printf("          Enter the quantity of medicine to be purchased      :");
             scanf("%d",&quantityOfMedicine[i]);
             if(medicineName[i]=='P')
             {
                 price[i] = (quantityOfMedicine[i] * 5);
             }
              else if(medicineName[i]=='L')
             {
                price[i] = (quantityOfMedicine[i] * 2); 
             }
            else if(medicineName[i]=='R')
             {
                price[i] = (quantityOfMedicine[i] * 2); 
             }
            else if(medicineName[i]=='A')
             {
                price[i] = (quantityOfMedicine[i] * 10); 
             }
             else
             {
                 printf(RED "          Invalid Medicine Name!\n" reset);
             }
             //  GST Amount = (Original Cost x GST%)/100
             GST[i] =  (price[i]*5)/100;
             regularDiscount[i] = 0;
             if(customerType[i]=='R')
             {
                 regularDiscount[i] = ((price[i] + GST[i] )*10) / 100;
             }

             totalBill[i] = GST[i] + price[i] - regularDiscount[i];
            printf(CYAN "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" reset);
         }    
           
// re ---> to research the ID
        re:
         printf("\n"TOMATO"          Enter the Customer ID for search                     :                    " reset);
         scanf("%d",&search);
         int left=0,right=numberOfCustomers-1,mid;
         while (left<=right)
         {
             mid = (left+right)/2;
            if(search==customerID[mid])
            {
                
                break;
            }
            else if(search<customerID[mid])
            {
                right = mid-1;
            }
            else if(search>customerID[mid])
            {
                left = mid+1;
            }
            else
            {
               printf(RED "          ERROR IN BINARY SEARCH..." reset);
            }
         }
         if(search!=customerID[mid])
            {
                
                printf(RED "          The Searched ID : %d is not found in the list" ,search );
                goto re;

                reset;
            }
         int index =0;
         for(int i=0;i<numberOfCustomers;i++)
         {
            
            if(search==customerID[i])
            {
                    break;
            }
            index++;
         }
    do{
               printf("          Enter 1 for Customer Details\n");
               printf("          Enter 2 for Customer Bill\n");
               printf(RED "          Enter 3 to EXIT and Search for another Customer\n" reset);
               scanf("%d",&choice);


               switch (choice)
               {
               case 1:

               for(int i=index;i<numberOfCustomers;i++)
                {
                       printf(RED "_______________________________________________________________________________________\n" reset);
                       printf("          Customer ID          : %d\n",customerID[i]);
                       printf("          Customer Type        : %c\n",customerType[i]);
                       printf("          Medicine ID          : %d\n",medicineID[i]);
                       printf("          Quantity of Medicine : %d\n",quantityOfMedicine[i]);
                       printf(RED "_______________________________________________________________________________________\n" reset);
                   break;
                }
                break;
               case 2 :
                      
               for(int i=index;i<numberOfCustomers;i++)
                {
                       printf(RED "_______________________________________________________________________________________\n" reset);
                       printf("          Total Bill           : %d\n",totalBill[i]);
                       printf(RED "_______________________________________________________________________________________\n" reset);
                   break;
                }
                break;

               case 3 :
                       goto re;
                   break;
               default:
                       printf("-----------------------------Invalid Entry!!----------------------------");
                   break;
               }

               printf("Enter 4 to Exit : ");
               scanf("%d",&exit);
    }while (exit==4);
     return 0;
}