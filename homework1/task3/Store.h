#pragma once
#include "Product.h"

class Store
{
private:
    Product *Products;
    int NumProd;
    int CurNumProd;

public:
    Store(int NumProd=50);
    Store(const Store &s);//Copy
    Store& operator= (const Store &s);//new def of operator =
    ~Store(); //destruct
    void SetNumProd(const int &); //methods
    int GetNumProd() const;
    void AddProd();
    void DelProd(int SKU);
    void ChangeProd(int SKU);
    void DisplayProd();
    };
