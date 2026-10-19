#define _CRT_SECURE_NO_WARNINGS
#include "classes.h"
#include <iostream>
#include <cstring>
using namespace std;

void Voucher::SetVoucher(const char city_in[], const char accommodation_in[],
    const char transport_in[], float price_in,
    const char program_in[])
{
    strcpy(city, city_in);
    strcpy(accommodation_type, accommodation_in);
    strcpy(transport_type, transport_in);
    price = price_in;
    strcpy(program_info, program_in);
    has_insurance = false;
    insurance_cost = 0;
    group_discount = 0;
}

void Voucher::SetVoucher(const char city_in[], const char accommodation_in[],
    const char transport_in[], float price_in,
    const char program_in[], float insurance_in)
{
    strcpy(city, city_in);
    strcpy(accommodation_type, accommodation_in);
    strcpy(transport_type, transport_in);
    price = price_in;
    strcpy(program_info, program_in);
    has_insurance = true;
    insurance_cost = insurance_in;
    group_discount = 0;
}

void Voucher::ShowVoucher() const
{
    cout << "Мiсто: " << city << endl;
    cout << "Проживання: " << accommodation_type << endl;
    cout << "Транспорт: " << transport_type << endl;
    cout << "Програма перебування: " << program_info << endl;
    cout << "Вартiсть: " << price << " грн" << endl;
    cout << "Групова знижка: " << group_discount << "%" << endl;
    if (has_insurance)
        cout << "Страховка: так, " << insurance_cost << " грн" << endl;
    else
        cout << "Страховка: немає" << endl;
}

bool Voucher::CompareCost(Voucher other) const
{
    return price < other.price;
}

Voucher Voucher::GetDiscounted(float percent) const
{
    Voucher result = *this;
    result.price = price - price * percent / 100;
    return result;
}

void Voucher::ApplyGroupDiscount(float percent)
{
    group_discount = percent;
    price = price - price * percent / 100;
}

void Voucher::WriteToFile(ofstream& file) const
{
    file.write((char*)this, sizeof(Voucher));
}

void Voucher::ReadFromFile(ifstream& file)
{
    file.read((char*)this, sizeof(Voucher));
}

void Student::SetData(const char surname_in[], const char name_in[],
    int course_in, const char specialty_in[],
    const char group_in[])
{
    strcpy(surname, surname_in);
    strcpy(name, name_in);
    course = course_in;
    strcpy(specialty, specialty_in);
    strcpy(group_name, group_in);
    balance = 0;
    has_paid_for_voucher = false;
}

void Student::SetData(const char surname_in[], const char name_in[],
    int course_in, const char specialty_in[],
    const char group_in[], float balance_in)
{
    strcpy(surname, surname_in);
    strcpy(name, name_in);
    course = course_in;
    strcpy(specialty, specialty_in);
    strcpy(group_name, group_in);
    balance = balance_in;
    has_paid_for_voucher = false;
}

void Student::ShowStudent() const
{
    cout << "Студент: " << surname << " " << name << endl;
    cout << "Курс: " << course << endl;
    cout << "Спецiальнiсть: " << specialty << endl;
    cout << "Група: " << group_name << endl;
    cout << "Баланс: " << balance << " грн" << endl;
    if (has_paid_for_voucher)
    {
        cout << "Путiвка придбана:" << endl;
        voucher.ShowVoucher();
    }
    else
    {
        cout << "Путiвку ще не придбано" << endl;
    }
}

void Student::BuyVoucher(Voucher voucher_in)
{
    voucher = voucher_in;
    has_paid_for_voucher = true;
    cout << surname << " " << name << " придбав(ла) путiвку до мiста "
        << voucher_in.city << endl;
}

Student Student::GetCopy() const
{
    Student copy = *this;
    return copy;
}

void Student::ApplyScholarship(float amount)
{
    balance = balance + amount;
}

void Student::WriteToFile(ofstream& file) const
{
    file.write((char*)this, sizeof(Student));
}

void Student::ReadFromFile(ifstream& file)
{
    file.read((char*)this, sizeof(Student));
}

void Student::SortRandomCourses() const
{
    int count = rand() % 8 + 3;   
    int* courses = new int[count]; 

    for (int i = 0; i < count; i++)
        courses[i] = rand() % 4 + 1;

    cout << "Згенеровано " << count << " значень курсу: ";
    for (int i = 0; i < count; i++)
        cout << courses[i] << " ";
    cout << endl;

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - 1 - i; j++)
            if (courses[j] > courses[j + 1])
            {
                int temp = courses[j];
                courses[j] = courses[j + 1];
                courses[j + 1] = temp;
            }

    cout << "Пiсля сортування: ";
    for (int i = 0; i < count; i++)
        cout << courses[i] << " ";
    cout << endl;

    delete[] courses;
}