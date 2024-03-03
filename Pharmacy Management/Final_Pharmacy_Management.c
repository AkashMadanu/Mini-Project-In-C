#include<stdio.h>

void readDetails();
void BinarySearch();
void Bill();
void Details();

#define RED "\e[0;31m"
#define LIME "\e[1;32m"
#define CYAN "\e[0;36m"
#define UGREEN "\e[4;32m"
#define YELLOW "\e[0;33m"
#define reset "\e[0m"
#define TOMATO "\e[1;31m"
//Decleration 
       int choice,exit,numberOfCustomers,search,mid;
    
       char cont;
       int customerID[10];
       char customerType[10];
       int medicineID[10];
       char medicineName[10];
       int quantityOfMedicine[10];
       int GST[10];
       int totalBill[10];
       int price[10];
       int  regularDiscount[10];

       int *PTRcustomerID = &customerID;
       int *PTRmedicineID = &medicineID;
       int *PTRquantityOfMedicine = &quantityOfMedicine;
       int *PTRGST = &GST;
       int *PTRtotalBill = &totalBill;
       int *PTRprice = &price;
       int *PTRregularDiscount = &regularDiscount;
       int *PTRsearch = &search;




       

int main()
{   
       printf(RED "***************************************************************************************\n" reset);
       printf(LIME"<<<<<<<<<<<<<<<<<<<<"CYAN ".......""|||" CYAN "....." YELLOW "PHARMACY MANAGEMANT"CYAN "....." "|||" CYAN "......."LIME ">>>>>>>>>>>>>>>>>>\n" reset);
       printf(RED "***************************************************************************************\n" reset);

       printf( "          Enter the number of Customers                       : ");

       scanf("%d",&numberOfCustomers);

do{
        
        printf("          Enter 1 to Read Details\n");
        printf("          Enter 2 for Bill Calculation\n");
        printf("          Enter 3 Print Details\n");
    
       
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            readDetails(PTRcustomerID,PTRmedicineID,PTRquantityOfMedicine,PTRprice);

            break;
        case 2 :
                BinarySearch(PTRsearch);
                Bill(PTRGST,PTRtotalBill,PTRprice,PTRregularDiscount);


               
            break;
        case 3 :
                BinarySearch(PTRsearch);
                Details(PTRcustomerID,PTRmedicineID,PTRquantityOfMedicine);

                break;
             
        default:
        printf(RED "          -------------------------Invalid-------------------------\n" reset);
            break;
        }
        printf("Press 'Y' to continue\n ");
        scanf(" %c",&cont);
} while (cont=='Y');
       
	printf("\n          --------------------Thank you!!!-----------------");


       return 0;
}

void readDetails(int *PTRcustomerID,int *PTRmedicineID,int *PTRquantityOfMedicine,int *PTRprice)
{
       for(int i = 0; i<numberOfCustomers; i++)
       {
             printf("          Enter the Customer ID                               : ");
             scanf("%d",(PTRcustomerID+i));

             printf("          Enter customer Type (Regular - R and Temporary -T   : ");
             scanf(" %c",&customerType[i]);

             printf("          Enter the Medicine ID :                             : ");
             scanf("%d",(PTRmedicineID+i));


             printf("          Enter Medicine name \n          P - paracetamol,\n          L - Levocitrizine,\n          R - Rantac,\n          A - Amoxicillin                                     : ");
             scanf(" %c",&medicineName[i]);

             printf("          Enter the quantity of medicine to be purchased      :");
             scanf("%d",(PTRquantityOfMedicine+i));

             if(medicineName[i]=='P')
             {
                 *(PTRprice+i) = (*(PTRquantityOfMedicine+i) * 5);
             }
              else if(medicineName[i]=='L')
             {
                *(PTRprice+i) = (*(PTRquantityOfMedicine+i) * 2); 
             }
            else if(medicineName[i]=='R')
             {
                *(PTRprice+i) = (*(PTRquantityOfMedicine+i) * 2); 
             }
            else if(medicineName[i]=='A')
             {
                *(PTRprice+i) = (*(PTRquantityOfMedicine+i) * 10); 
             }
             else
             {
                 printf(RED "          Invalid Medicine Name!\n" reset);
             }

            printf(CYAN "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" reset);
         } 
}

void BinarySearch(int *PTRsearch)
{
              
//       Asking user to search for the Customer ID
        re:
         printf("\n"TOMATO"          Enter the Customer ID for search                     :                    " reset);
         scanf("%d",PTRsearch);
    
         int left=0,right=numberOfCustomers-1;

         while (left<=right)
         {
             mid = (left+right)/2;
            if((*PTRsearch)==customerID[mid])
            {
                // printf("The customer is %d AND THE INDEX IS : %d",customerID[mid],mid);
                break;
            }
            else if((*PTRsearch)<customerID[mid])
            {
                
                right = mid-1;
            }
            else if((*PTRsearch)>customerID[mid])
            {
                left = mid+1;
            }
            else
            {
               printf(RED "          ERROR IN BINARY SEARCH...\n" reset);
            }
   
         }

         if((*PTRsearch)!=customerID[mid])
            {
                
                printf(RED "          The Searched ID : %d is not found in the list\n" ,(*PTRsearch) );
                goto re;

                reset;
            }
}

void Bill(int *PTRGST,int *PTRtotalBill,int *PTRprice,int *PTRregularDiscount)
{
   
    for(int i=mid;i<numberOfCustomers;i++)
        {
           
       //  GST Amount = (Original Cost x GST%)/100
             *(PTRGST + i) =  (*(PTRprice+i)*5)/100;
             *(PTRregularDiscount+i) = 0;
             if(customerType[i]=='R')
             {
                 *(PTRregularDiscount+i) = ((*(PTRprice+i) + *(PTRGST + i) )*10) / 100;
             }

             *(PTRtotalBill+i) = *(PTRGST + i) + *(PTRprice+i) - *(PTRregularDiscount+i); 

             printf(RED "_______________________________________________________________________________________\n" reset);
             printf("Price of the Medicine : %d\n",*(PTRprice+i));
             printf("GST : %d\n",*(PTRGST + i));
             printf("Recgular Discount : %d\n",*(PTRregularDiscount+i));
             printf("Total Price : %d\n",  *(PTRtotalBill+i));
             printf(RED "_______________________________________________________________________________________\n" reset);


             break;
        }     
        
}

void Details(int *PTRcustomerID,int *PTRmedicineID,int *PTRquantityOfMedicine)
{
         for(int i=mid;i<numberOfCustomers;i++)
                {
                       printf(RED "_______________________________________________________________________________________\n" reset);
                       printf("          Customer ID          : %d\n",*(PTRcustomerID+i));
                       printf("          Customer Type        : %c\n",customerType[i]);
                       printf("          Medicine ID          : %d\n",*(PTRmedicineID+i));
                       printf("          Quantity of Medicine : %d\n",*(PTRquantityOfMedicine+i));
                       printf(RED "_______________________________________________________________________________________\n" reset);
                      
                   break;
                }
}
