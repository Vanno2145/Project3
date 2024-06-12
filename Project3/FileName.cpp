#include <iostream>

using namespace std;

class Car
{
	char* model;
	int year;
	double price;
public:
	Car();//Construct by default
	Car(const char*mod, int y, double pr);//Construct by 3 params
	Car(const char* mod);//Construct by 1 params
	Car(const Car& obj) :Car(obj.model, obj.year, obj.price) {};
	Car& operator=(const Car& obj);

	//Get model
	const char* GetModel() {
		return model;
	}
	//Get year
	int GetYear() {
		return year;
	}
	//Get price
	double GetPrice() {
		return price;
	}

	//Set model
	void SetMod(const char* mod) {
		if (model != nullptr) {
			delete[] model;
			
			model = new char[strlen(mod) + 1];
			strcpy_s(model, strlen(mod) + 1, mod);
		}
	}
	//Set year
	void SetYear(int y) {
		year = y;
	}
	//Set price
	void SetPrice(double p) {
		price = p;
	}


	Car& operator ++() {//overload operator ++
		this->year += 1;

		return *this;
	}
	Car& operator --() {//overload operator --
		this->year -= 1;

		return *this;
	}

	~Car();//Destruct
};

Car::Car()
{
	model = nullptr;
	price = 0;
	year = 0;
}

Car::Car(const char* mod, int y, double pr):Car(mod)
{
	year = y;
	price = pr;
}

Car::Car(const char* mod)
{
	model = new char[strlen(mod) + 1];
	strcpy_s(model, strlen(mod) + 1, mod);
}

Car& Car::operator=(const Car& obj)//overload operator =
{
	if (this == &obj) {
		return *this;
	}

	if (model != nullptr) {
		delete[] model;
	}
	model = new char[strlen(obj.model) + 1];
	strcpy_s(model, strlen(obj.model) + 1, obj.model);
	year = obj.year;
	price = obj.price;

	return *this;
}

Car::~Car()//Destruct
{
	delete[] model;
}

ostream& operator<<(ostream& os, Car& obj) {//overload cout 
	os << obj.GetModel() << endl << obj.GetYear() << endl << obj.GetPrice() << endl;

	return os;
}

istream& operator>>(istream& is, Car& obj) {//overload cin
	int y;
	double price;
	char m[10];
	cout << "Enter model" << endl;
	is >> m;
	obj.SetMod(m);
	cout << "Enter year" << endl;
	is >> y;
	obj.SetYear(y);
	cout << "Enter price" << endl;
	is >> price;
	obj.SetPrice(price);

	

	return is;
}

Car operator -=(Car& obj1, int a) {//overload operator -=
	obj1.SetPrice(obj1.GetPrice() - a);

	return obj1;
}

Car operator +=(Car& obj1, int a) {//overload operator +=
	obj1.SetPrice(obj1.GetPrice() + a);

	return obj1;
}

int operator-(Car& obj1, Car& obj2) {//overload operator -
	int r = obj1.GetPrice() - obj2.GetPrice();

	return r;
}

int operator+(Car& obj1, Car& obj2) {//overload operator +
	int r = obj1.GetPrice() + obj2.GetPrice();

	return r;
}

int main() {
	Car obj1("Audi", 2023, 500000);//Create car 1
	Car obj2("Mercedes", 2020, 1000000);//Create car 2
	

	
	obj1 += 1000; // price + 1000
	

	cout << obj1 << endl;

	obj1 -= 1000;// price - 1000

	++obj1; // year + 1
	
	cout << obj1 << endl;

	--obj1; // // year - 1

	int r = obj1 - obj2; // Price car 1 - price car 2
	int sum = obj1 + obj2; // price car 1 + price car 2
   
	cout << r << endl << sum;
}