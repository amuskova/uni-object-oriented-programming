#include <iostream>
#include <limits>
#include "Store.h"
#include "Product.h"


int StrLen(const char* Str)
{
    int Counter=0;
    while(Str[Counter]!= '\0')
    {
        Counter++;
    }
    return Counter;
}
void DoubleLen(char* &Array)
{

    char* NewArray= new char[2*StrLen(Array)+1];
    for(int i=0;i<=StrLen(Array);i++)
    {
        NewArray[i]=Array[i];
    }
    delete[] Array;
    Array=NewArray;
}
void EnterCharArray(char* &input)
{
    int CharCount=0;
    char c;
    while(std::cin.get(c) && c!= '\n')
    {
        if(CharCount==StrLen(input))
        {
            DoubleLen(input);
        }
        input[CharCount]=c;
        CharCount++;
    }
    input[CharCount]='\0';
}
void StrCpy(char * &destination, const char* source)//strcpy
{
	int CharCount = 0;
	while (source[CharCount] != '\0')
	{
		if (CharCount == StrLen(destination))
		{
			DoubleLen(destination);
		}
		destination[CharCount] = source[CharCount];
		CharCount++;
	}
	destination[CharCount] = '\0';//terminating zero
}

int main()
{
    Store MyStore;
    char *ch=new char[1];
    do
    {
        std::cout<<"MAIN MENU:"<<std::endl;
        std::cout<<"A  Add new product  to the menu."<<std::endl;
        std::cout<<"X  Delete product to the menu."<<std::endl;
        std::cout<<"C  Change product to the menu."<<std::endl;
        std::cout<<"D  Display all products in the menu."<<std::endl;
        std::cout<<"Q  Quit from the console."<<std::endl;
        EnterCharArray(ch);
        if(StrLen(ch)==1)
        {
            if(ch[0]=='a' || ch[0]=='A')
            {
                MyStore.AddProd();
                std::cin.clear();
                std::cin.ignore();
            }
            else if(ch[0]=='x'||ch[0]=='X')
            {
                int n;
                std::cout<<"Please enter the SKU of the produt you would like to delete: "<<std::endl;
                std::cin>>n;
                while(!std::cin)
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<<"This is invalid input.The numbers of the SKU are integer or equal ti 1!"<<std::endl;
                    std::cout<<"Please enter the product's SKU you would like to delete: "<<std::endl;
                    std::cin>>n;
                }
                MyStore.DelProd(n);
                std::cin.clear();
                std::cin.ignore();
            }
            else if(ch[0]=='c' || ch[0]=='C')
            {
                int n;
                std::cout<<"Please enter the SKU of the product you would like to change: "<<std::endl;
                std::cin>>n;
                while(!std::cin)
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout<<"This is invalid input of the SKU! The numbers of the SKU are equal or greater to 1"<<std::endl;
                    std::cout<<"Please enter the SKU of the product you would like to change:  "<<std::endl;
                    std::cin>>n;
                }
                MyStore.ChangeProd(n);
                std::cin.clear();
                std::cin.ignore();
            }
            else if(ch[0]=='d' || ch[0]=='D')
            {
                MyStore.DisplayProd();
                std::cin.clear();
                std::cin.ignore();
            }
            else if (ch[0]=='q'|| ch[0]=='Q')
            {
                break;
            }
            else
            {
                std::cout<<"This is invalid input! There is not such an option in the menu. Please press ENTER for the main menu"<<std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
        else
            {
            std::cout<<"This is invalid input! TOO many letters!"<<std::endl;
            }
    } while(true);
    return 0;
}
