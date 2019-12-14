#include<stdio.h>
#include<termios.h>
int main(void)
{
    float num1, num2, result;
    char choice;

    do{
        printf("Enter first number: ");
        scanf("%f",&num1);

        printf("Enter second number: ");
        scanf("%f",&num2);

        printf("Enter choice +,-,*,/: ");
        scanf(" %c",&choice);

        if(choice == '+')
        {
            result =num1+num2;
            printf("%.2f + %.2f = %.2f\n",num1, num2, result);
        }
        else
        {
          if(choice == '-')
            {
                result =num1-num2;
                printf("%.2f - %.2f = %.2f\n",num1, num2, result);
            } //end if '-'
            else
            {
                if(choice == '*')
                {
                    result =num1*num2;
                    printf("%.2f * %.2f = %.2f\n",num1, num2, result);
                } //end if '*'
                else
                {
                    if(choice == '/')
                    {
                    result =num1/num2;
                    printf("%.2f / %.2f = %.2f\n",num1, num2, result);
                    } //end if '/'
                }//end inner inner  else
            } //end inner else
        }//end else outer
        printf("Do you want to continue calculation? Enter Y or N: ");
        scanf(" %c", &choice);


    } //end do-while
	while(choice=='Y');
    //return 0;
} //end main
