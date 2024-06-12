#include <iostream>

using namespace std;

class Car
{
public:
	Car();
	Car(const char*mod, int y, double pr);
	Car(const char* mod);
	Car(const Car& obj) :Car(obj.model, obj.year, obj.price) {};
	Car& operator=(const Car& obj);

	const char* GetModel() {
		return model;
	}
	int GetYear() {
		return year;
	}
	double GetPrice() {
		return price;
	}

	void SetMod(const char* mod) {
		if (model != nullptr) {
			delete[] model;
			
			model = new char[strlen(mod) + 1];
			strcpy_s(model, strlen(mod) + 1, mod);
		}
	}
	void SetYear(int y) {
		year = y;
	}
	void SetPrice(double p) {
		price = p;
	}

	Car& operator ++() {
		this->year += 1;

		return *this;
	}
	Car& operator --() {
		this->year -= 1;

		return *this;
	}

	

	~Car();

private:
	char* model;
	int year;
	double price;
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

Car& Car::operator=(const Car& obj)
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

Car::~Car()
{
	delete[] model;
}

ostream& operator<<(ostream& os, Car& obj) {
	os << obj.GetModel() << endl << obj.GetYear() << endl << obj.GetPrice() << endl;

	return os;
}

istream& operator>>(istream& is, Car& obj) {
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

Car operator -=(Car& obj1, int a) {
	obj1.SetPrice(obj1.GetPrice() - a);

	return obj1;
}

Car operator +=(Car& obj1, int a) {
	obj1.SetPrice(obj1.GetPrice() + a);

	return obj1;
}

int operator-(Car& obj1, Car& obj2) {
	int r = obj1.GetPrice() - obj2.GetPrice();

	return r;
}

int operator+(Car& obj1, Car& obj2) {
	int r = obj1.GetPrice() + obj2.GetPrice();

	return r;
}

int main() {
	Car obj1("Audi", 2023, 500000);
	Car obj2("Mercedes", 2020, 1000000);
	

	
	obj1 += 1000; // увеличиваем стоимость на 1000
	

	cout << obj1 << endl;

	obj1 -= 1000;// уменьшаем стоимость на 1000

	++obj1; // увеличиваем год на 1
	
	cout << obj1 << endl;

	--obj1; // уменьшаем год на 1

	int r = obj1 - obj2; // разность стоимости автомобилей
	int sum = obj1 + obj2; // сумма стоимости автомобилей , возвращается общая сумма
   
	cout << r << endl << sum;
}