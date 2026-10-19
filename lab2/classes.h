#ifndef CLASSES_H
#define CLASSES_H

#include <fstream>
using namespace std;

class Voucher
{
public:
    char city[30];     
    char accommodation_type[20];
    char transport_type[20]; 

    void SetVoucher(const char city_in[], const char accommodation_in[],
        const char transport_in[], float price_in,
        const char program_in[]);
    void SetVoucher(const char city_in[], const char accommodation_in[],
        const char transport_in[], float price_in,
        const char program_in[], float insurance_in);

    void ShowVoucher() const;       

    bool CompareCost(Voucher other) const;

    Voucher GetDiscounted(float percent) const;

    void ApplyGroupDiscount(float percent);  

    void WriteToFile(ofstream& file) const;
    void ReadFromFile(ifstream& file);

private:
    float price;          
    bool has_insurance;    
    float insurance_cost;
    char program_info[60]; 
    float group_discount; 
};

class Student
{
public:
    char surname[30];  
    char name[30];    
    int course;     

    void SetData(const char surname_in[], const char name_in[], int course_in,
        const char specialty_in[], const char group_in[]);
    void SetData(const char surname_in[], const char name_in[], int course_in,
        const char specialty_in[], const char group_in[],
        float balance_in);

    void ShowStudent() const;

    void BuyVoucher(Voucher voucher_in);

    Student GetCopy() const;

    void ApplyScholarship(float amount);

    void WriteToFile(ofstream& file) const;
    void ReadFromFile(ifstream& file);

    void SortRandomCourses() const;

private:
    char specialty[40];  
    char group_name[20]; 
    float balance;  
    Voucher voucher; 
    bool has_paid_for_voucher;
};

#endif