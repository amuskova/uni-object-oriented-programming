#pragma once

extern int GlobalSKU;
class Product
{
private:
    int SKU;
    double Price;
    int Count;
    int Size;
    char* Brand;
    char* Model;
    char* Colour;
public:
    Product(); //default constructor
    Product(double,int,int,char*,char*,char*); //constructor
    Product(const Product &p); //copy
    Product& operator=(const Product &p); //the new definition of operator =
    ~Product(); //destruct
    void SetSKU(const int &SKU); //methods
    int GetSKU()const;
    void SetPrice(const double &Price);
    double GetPrice() const;
    void SetSize(const int &Size);
    int GetSize() const;
    void SetCount(const int& Count);
    int GetCount() const;
    void SetBrand(const char* &Brand);
    char* GetBrand() const;
    void SetModel(const char* &Model);
    char* GetModel() const;
    void SetColour(const char* &Colour);
    char* GetColour() const;
    void PrintInfo() const;
};
