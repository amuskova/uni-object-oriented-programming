#include <iostream>
#include "Store.h"
#include <limits>

int StrLenStore(const char* Str)
{
    int Counter=0;
    while(Str[Counter]!='\0')
    {
        Counter++;
    }
    return Counter;
}
void DoubleLenStore(char* &Array)
{
    int i=0;
    char* NewArray=new char[2*StrLenStore(Array)+1];
    for(i=0;i<=StrLenStore(Array);i++)
    {
        NewArray[i]=Array[i];
    }
    delete[] Array;
    Array=NewArray;
}

void EnterCharArrayStore(char* &input)
{
    int CharCount =0;
    char c;
    while(std::cin.get(c) && c!='\n')
    {
        if(CharCount==StrLenStore(input))
        {
            DoubleLenStore(input);
        }
        input[CharCount]=c;
        CharCount++;
    }
    input[CharCount]='\0';
    std::cin.clear();
}
void StrCpyStore(char* &destination, const char* source)
{
    int CharCount=0;
    while(source[CharCount] != '\0')
    {
        if(CharCount==StrLenStore(destination))
        {
            DoubleLenStore(destination);
        }
        destination[CharCount]=source[CharCount];
        CharCount++;
    }
    destination[CharCount]='\0';
}
Store::Store(int NumProd)
{
    this->SetNumProd(NumProd);
    this->CurNumProd=0;
    Products=new Product[this->GetNumProd()];
}
Store::Store(const Store &s)
{
    this->SetNumProd(s.GetNumProd());
    this->CurNumProd=s.CurNumProd;
    Products=new Product[this->GetNumProd()];
    for(int i=0;i<this->GetNumProd();i++)
    {
        this->Products[i]=s.Products[i];
    }
}
Store& Store::operator=(const Store &s)
{
    if(this!=&s)
    {
        delete[] this->Products;
        this->SetNumProd(s.GetNumProd());
        Products=new Product[this->GetNumProd()];
        for(int i=0;i<this->GetNumProd();i++)
        {
            this->Products[i]=s.Products[i];
        }
    }
    return *this;
}
Store::~Store()
{
    delete[] this->Products;
}
void Store::SetNumProd(const int& NumProd)
{
    this->NumProd=NumProd;
}
int Store::GetNumProd() const
{
    return this->NumProd;
}
void Store::AddProd()
{
    if(this->CurNumProd==NumProd)
    {
        std::cout<<"There is no space for more products in this store!"<<std::endl;
    }
    else
        {
            std::cout<<"Add the new product: "<<std::endl;
    Product NewProd;
    this->CurNumProd++;
    Products[CurNumProd-1].SetSKU(GlobalSKU);
    GlobalSKU++;
    char* brand = new char[10];
    std::cout<<"Please, enter the brand of the T-Shirt: "<<std::endl;
    EnterCharArrayStore(brand);
    const char* brandConst = brand;
    NewProd.SetBrand(brandConst);
    char* model=new char[10];
    std::cout<<"Please enter the model of the T-Shirt: "<<std::endl;
    EnterCharArrayStore(model);
    const char* modelConst=model;
    NewProd.SetModel(modelConst);
    double price;
    std::cout<<"Please enter the price of the T-Shirt: "<<std::endl;
    std::cin>>price;
    while(!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"There is invalid input! Please enter the price of the T-Shirt:"<<std::endl;
        std::cin>>price;
    }
    NewProd.SetPrice(price);
    int count;
    std::cout<<"Please enter the count of the T-Shirts: "<<std::endl;
    std::cin>>count;
    while(!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"There is invalid input. Please enter the count: "<<std::endl;
        std::cin>>count;
    }
    NewProd.SetCount(count);
    int size;
    std::cout<<"Please enter the size of the T-Shirt: "<<std::endl;
    std::cin>>size;
    while(!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"There is invalid input! Please enter the size of the T-Shirt: "<<std::endl;
        std::cin>>size;
    }
    NewProd.SetSize(size);

    char* colour = new char[10];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter the colour:" << std::endl;
		EnterCharArrayStore(colour);
		const char* colourConst = colour;
		NewProd.SetColour(colourConst);

		Products[CurNumProd - 1] = NewProd;
        }
        std::cout<<"You have had sucessfully added item! Press ENTER for the main menu!"<<std::endl;
}
void Store::DelProd(int SKU)
{
    bool FoundSKU=false;
    if(CurNumProd<1)
    {
        std::cout<<"ERROR!You can not delete! There is no item in  the store!"<<std::endl;
    }
    else
    {
        for(int i=0;i<CurNumProd;i++)
        {
            if(Products[i].GetSKU()==SKU)
            {
                FoundSKU=true;
                Products[i].SetSKU(-1);
                for(int j=i;j<CurNumProd-1;j++)
                {
                    Products[j]=Products[j+1];
                }
                this->CurNumProd--;
                std::cout<<"You have succesfully deleted item! Press ENTER for the main menu!"<<std::endl;
            }
        }
        if(!FoundSKU)
        {
            std::cout<<"This is invalid input! There do not exist such a SKU!"<<std::endl;
        }
    }
}
void Store::ChangeProd(int SKU)
{
    bool FoundSKU=false;
    if(CurNumProd<1)
    {
        std::cout<<"There is no item in this store!"<<std::endl;
    }
    for(int i=0;i<CurNumProd;i++)
    {
        if(Products[i].GetSKU()==SKU)
        {
            FoundSKU=true;
            Product NewProd;
            Products[i].SetSKU(GlobalSKU);
            GlobalSKU++;
            std::cin.clear();
            std::cin.ignore();
            char* brand=new char[10];
            std::cout<<"Please enter the T-Shirt's brand: "<<std::endl;
            EnterCharArrayStore(brand);
            const char* brandConst=brand;
            NewProd.SetBrand(brandConst);
            char* model=new char[10];
            std::cout<<"Please enter the model of the T-Shirt: "<<std::endl;
            EnterCharArrayStore(model);
            const char* modelConst=model;
            NewProd.SetModel(modelConst);
            double price;
            std::cout<<"Please enter the prise of the T-Shirt: "<<std::endl;
            std::cin>>price;
            while(!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"This is invalid input! Please enter the price: "<<std::endl;
                std::cin>>price;
            }
            NewProd.SetPrice(price);
            int count;
            std::cout<<"Please enter the new count of the T-Shirts: "<<std::endl;
            std::cin>>count;
            while(!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"This is invalid input!please enter the new content of the T-Shirts: "<<std::endl;
                std::cin>>count;
            }
            NewProd.SetCount(count);
            std::cin.clear();
            std::cin.ignore();

            int size;
            std::cout<<"Please enter the new size: "<<std::endl;
            std::cin>>size;
            while(!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"This is invalid input! Please enter the new size of the T-Shirts: "<<std::endl;
                std::cin>>size;
            }
            NewProd.SetSize(size);
            std::cin.clear();
			std::cin.ignore();

			char* colour = new char[10];
			std::cout << "Please enter the T-Shirt's new colour:" << std::endl;
			EnterCharArrayStore(colour);
			const char* colourConst = colour;
			NewProd.SetColour(colourConst);

			Products[CurNumProd - 1] = NewProd;
			std::cout << "Succesfully changed item! Press enter for main menu." << std::endl;
        }
    }
    if(!FoundSKU)
    {
        std::cout<<"This is not valid input! There is no A SKU such like this!"<<std::endl;
    }
}
void Store::DisplayProd()
{
    if(CurNumProd==0)
    {
        std::cout<<"There are no items in the store!"<<std::endl;
    }
    for(int i=0;i<CurNumProd;i++)
    {
        Products[i].PrintInfo();
        std::cout<<"___________________________________"<<std::endl;
    }
    std::cout<<"Please press ENTER for the main menu!"<<std::endl;
}
