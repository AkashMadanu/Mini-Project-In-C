// Takeing user details and printing
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

    int ID,medicineID,quantityOfMedicine,GST,totalBill,price;
    char CustomerType;
    // Takeing the details 
    printf("          Enter the Customer ID :");
    scanf("%d",&ID);

    printf("          Enter customer Type (Regular - R and Temporary -T :");
    scanf(" %c",&CustomerType);

    printf("          Enter the Medicine ID   :");
    scanf("%d",&medicineID);

    printf("          Enter the quantity of medicine to be purchased :");
    scanf("%d",&quantityOfMedicine);
    
    price = (quantityOfMedicine * 10);
// GST CALCULATION
    GST =  (price*5)/100;

    totalBill = GST + price;
    // Printing Details
    printf("          Customer ID          : %d\n",ID);
    printf("          Customer Type        : %c\n",CustomerType);
    printf("          Medicine ID          : %d\n",medicineID);
    printf("          quantity of medicine : %d\n",quantityOfMedicine);
    printf("          Total Bill           : %d\n",totalBill);
    return 0;
}