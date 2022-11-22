#include<stdio.h>
#define RED "\e[0;31m"
#define LIME "\e[1;32m"
#define CYAN "\e[0;36m"
#define UGREEN "\e[4;32m"
#define YELLOW "\e[0;33m"
#define reset "\e[0m"
int main()
{
       printf(RED "***************************************************************************************\n" reset);
       printf(LIME"<<<<<<<<<<<<<<<<<<<<"CYAN ".......""|||" CYAN "....." YELLOW "PHARMACY MANAGEMANT"CYAN "....." "|||" CYAN "......."LIME ">>>>>>>>>>>>>>>>>>\n" reset);
       printf(RED "***************************************************************************************\n" reset);

    int ID,medicineID,quantityOfMedicine,GST,totalBill,price,regularDiscount,choice,exit;
    char CustomerType,medicineName;
    printf("          Enter the Customer ID                               : ");
    scanf("%d",&ID);

    printf("          Enter customer Type (Regular - R and Temporary -T   : ");
    scanf(" %c",&CustomerType);

    printf("          Enter the Medicine ID :                             : ");
    scanf("%d",&medicineID);


    printf("          Enter Medicine name \n          P - paracetamol,\n          L - Levocitrizine,\n          R - Rantac,\n          A - Amoxicillin                                     : ");
    scanf(" %c",&medicineName);

    printf("          Enter the quantity of medicine to be purchased      :");
    scanf("%d",&quantityOfMedicine);
    
    if(medicineName=='P')
    {
        price = (quantityOfMedicine * 5);
    }
     else if(medicineName=='L')
    {
       price = (quantityOfMedicine * 2); 
    }
   else if(medicineName=='R')
    {
       price = (quantityOfMedicine * 2); 
    }
   else if(medicineName=='A')
    {
       price = (quantityOfMedicine * 10); 
    }
    else
    {
        printf(RED "          Invalid Medicine Name!\n" reset);
    }


//  GST Amount = (Original Cost x GST%)/100
    GST =  (price*5)/100;
    regularDiscount = 0;
    if(CustomerType=='R')
    {
        regularDiscount = ((price + GST )*10) / 100;
    }

    totalBill = GST + price - regularDiscount;

            printf("Enter 1 for Customer Details\n");
            printf("Enter 2 for Customer Bill\n");
            printf(RED "Enter 3 to EXIT\n" reset);
            scanf("%d",&choice);


            switch (choice)
            {
            case 1:
                    printf(RED "_______________________________________________________________________________________\n" reset);
                    printf("          Customer ID          : %d\n",ID);
                    printf("          Customer Type        : %c\n",CustomerType);
                    printf("          Medicine ID          : %d\n",medicineID);
                    printf("          Quantity of Medicine : %d\n",quantityOfMedicine);
                    printf(RED "_______________________________________________________________________________________\n" reset);
                break;
            case 2 :
                    printf(RED "_______________________________________________________________________________________\n" reset);
                    printf("          Total Bill           : %d\n",totalBill);
                    printf(RED "_______________________________________________________________________________________\n" reset);
                break;

            case 3 :
                    printf(RED "EXIT\n" reset );
                break;
            default:
                    printf("-----------------------------Invalid Entry!!----------------------------");
                break;
            }
    return 0;
}