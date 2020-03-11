#include <iostream>
#include "Product.h"

int GlobalSKU=0;
int StrLenProd(const char* Str)
{
    int Counter=0;
    while (Str[Counter] != '\0')
    {
        Counter ++;
    }
return Counter;
}
void DoubleLenProd(char* &Array)
{

    char* NewArray=new char[2*StrLenProd(Array)+1];
    for(int i=0;i<=StrLenProd(Array);i++)
    {
        NewArray[i]=Array[i];

    }
    delete[] Array;
    Array=NewArray;
}
void EnterCharArrayProd(char* &input)
{
    int CharCount=0;
    char c;
    while (std::cin.get(c) && c!='\n')
    {
        if(CharCount==StrLenProd(input))
        {
            DoubleLenProd(input);
        }
        input[CharCount]=c;
        CharCount++;
    }
    input[CharCount]='\0';
}
void StrCpyProd(char* &destination, const char* source)
{
    int CharCount=0;
    while(source[CharCount]!='\0')
    {
        if(CharCount==StrLenProd(destination))
        {
            DoubleLenProd(destination);
        }
        destination[CharCount]=source[CharCount];
        CharCount++;
    }
    destination[CharCount]='\0';
}
Product::Product()
{
    SKU=GlobalSKU+1;
    Price=0;
    Count=0;
    Size=0;
    Brand=new char[10];
    Model=new char[10];
    Colour=new char[10];
}
Product::Product(double Price,int Count, int Size, char* Brand, char* Model, char* Colour)
{
    this->SetSKU(GlobalSKU);
    GlobalSKU++;
    this->SetPrice(Price);
    this->SetCount(Count);
    this->SetSize(Size);
    this->Brand=new char[10];
    StrCpyProd(this->Brand,Brand);
    this->Model=new char[10];
    StrCpyProd(this->Model,Model);
    this->Colour=new char[10];
    StrCpyProd(this->Colour,Colour);
}

Product::Product(const Product &p)
{
    this->SetSKU(p.GetSKU());
    this->SetPrice((p.GetPrice()));
    this->SetCount(p.GetCount());
    this->SetSize(p.GetSize());
    this->Brand=new char[10];
    StrCpyProd(this->Brand,p.Brand);
    this->Model=new char[10];
    StrCpyProd(this->Model,p.Model);
    this->Colour=new char[10];
    StrCpyProd(this->Colour,p.Colour);
}

Product& Product:: operator=(const Product &p)
{
    if(this != &p)
    {
        delete[] this->Brand;
        delete[] this->Model;
        delete[] this->Colour;

        this->SetSKU(p.GetSKU());
        this->SetPrice(p.GetPrice());
        this->SetCount(p.GetCount());
        this->SetSize(p.GetSize());

        this->Brand=new char[10];
        StrCpyProd(this->Brand,p.Brand);
        this->Model=new char[10];
        StrCpyProd(this->Model,p.Model);
        this->Colour=new char[10];
        StrCpyProd(this->Colour,p.Colour);
    }
    return *this;
}

Product::~Product()
{
    delete[] Brand;
    delete[] Model;
    delete[] Colour;
}

void Product::SetSKU(const int &SKU)
{
    if(SKU>=1)
    {
        this->SKU=SKU;
    }
}
int Product::GetSKU() const
{
    return this->SKU;
}
void Product::SetPrice(const double &Price)
{
    if(Price>=0)
    {
        this->Price=Price;
    }
}
double Product::GetPrice() const
{
    return this->Price;
}
void Product::SetCount(const int &Count)
{
    if(Count>0)
    {
        this->Count=Count;
    }
}
int Product::GetCount() const
{
    return this->Count;
}
 void Product::SetSize(const int &Size)
 {
     if(Size>0)
     {
         this->Size=Size;
     }
 }
 int Product::GetSize() const
 {
 return this-> Size;
 }
 void Product::SetBrand(const char* &Brand)
 {
     StrCpyProd(this->Brand,Brand);
 }
 char* Product::GetBrand()const
 {
     return this->Brand;
 }
 void Product::SetModel(const char* &Model)
 {
     StrCpyProd(this->Model,Model);
 }
 char* Product::GetModel() const{return this->Model;}
 void Product::SetColour(const char* &Colour)
 {
     StrCpyProd(this->Colour,Colour);
 }
 char* Product::GetColour() const {return this->Colour;}

 void Product::PrintInfo() const
 {
     std::cout<<"Product's info: "<<std::endl;
     std::cout<<"The T-Shirt keeping unit is: "<<this->GetSKU()<<std::endl;
     std::cout<<"The T-Shirt brand is: "<<this->GetBrand()<<std::endl;
     std::cout<<"The Model of the T-Shirt is: "<<this->GetModel()<<std::endl;
     std::cout<<"The Price of the T-Shirt is: "<<this->GetPrice()<<"BGN"<<std::endl;
     std::cout<<"We have available "<<this->GetCount()<<" T-Shirts of this type"<<std::endl;
     std::cout<<"The Size is "<<std::endl;
     std::cout<<"The Colour of the T-Shirt is: "<<this->GetColour()<<std::endl;
 }
