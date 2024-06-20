#include <iostream>
using namespace std;

class clsHotel {

private:
    int _SecretCode = 987451;
    int _TotalIncome = 1'000'000'000;
    int VIPRoomsNumber = 50;
    int VIPRentPrice = 1000;

public:
    int RoomsNumber = 500;
    int Floors = 10;
    int RentPrice = 100;


    friend class clsHotelOwner;
    friend int CalcTotalVIPRoomsIncome(clsHotel Hotel);
};

class clsPerson
{

private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    //Read Only Property
    int ID()
    {
        return _ID;
    }

    //Property Set
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string FirstName()
    {
        return _FirstName;
    }

    //Property Set
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    //Property Get
    string LastName()
    {
        return _LastName;
    }

    //Property Set
    void setEmail(string Email)
    {
        _Email = Email;
    }

    //Property Get
    string Email()
    {
        return _Email;
    }

    //Property Set
    void setPhone(string Phone)
    {
        _Phone = Phone;
    }

    //Property Get
    string Phone()
    {
        return _Phone;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }


    virtual void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID       : " << _ID;
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";

    }

    void SendEmail(string Subject, string Body)
    {

        cout << "\nThe following message sent successfully to email: " << _Email;
        cout << "\nSubject: " << Subject;
        cout << "\nBody: " << Body << endl;

    }

    void SendSMS(string TextMessage)
    {
        cout << "\nThe following SMS sent successfully to phone: " << _Phone;
        cout << "\n" << TextMessage << endl;
    }


};

class clsHotelOwner : public clsPerson
{
private:
    int _LastYearTotalIncome = 100'000'000;
    int _OwnerSecretCode = 0;

    

    bool _IsTheOwner(int code) {
        return code == _OwnerSecretCode;
    }

public:

    clsHotelOwner(int ID, string FirstName, string LastName, string Email, string Phone, int OwnerSecretCode)
    : clsPerson(ID, FirstName, LastName, Email, Phone){
        _OwnerSecretCode = OwnerSecretCode;
    }

    bool IncomeIncreased(clsHotel Hotel)
    {
        if (_IsTheOwner(Hotel._SecretCode))
        {
            return Hotel._TotalIncome > _LastYearTotalIncome;
        }
    }

};

int CalcTotalVIPRoomsIncome(clsHotel Hotel)
{
   return Hotel.VIPRentPrice * Hotel.VIPRoomsNumber;
}

int main()
{
    clsHotel Hotel;
    clsHotelOwner Owner(10, "Mohammed", "Almomany", "A@a.com", "8298982", 987451);

    Owner.Print();
    cout << "\nIncome Increased: " << ((Owner.IncomeIncreased(Hotel) == 1) ? "True" : "False") << '\n';
    cout << "\nTotal VIP Rooms Income: " << CalcTotalVIPRoomsIncome(Hotel) << '\n';
    system("pause>0");
    return 0;
}
 