class Product
{
public:
	Product(std::string name) :mname(name){}
	virtual void operation() = 0;
protected:
	std::string mname;
};
class  Product1 : public Product
{
public:
	Product1(std::string name) :Product(name){}
	virtual void operation()
	{
		std::cout << "this is Product1!" << std::endl;
	}
};

class  Product2 : public Product
{
public:
	Product2(std::string name) :Product(name){}
	virtual void operation()
	{
		std::cout << "this is Product2!" << std::endl;
	}
};
class  Product3 : public Product
{
public:
	Product3(std::string name) :Product(name){}
	virtual void operation()
	{
		std::cout << "this is Product3!" << std::endl;
	}
};
class Factory_1:public Factory
{
public:
	Factory_1(std::string name) :Factory(name){}
	virtual Product* createProduct()
	{
		return new Product1("Product1");
	}
};
class Factory_2:public Factory
{
public:
	Factory_2(std::string name) :Factory(name){}
	virtual Product* createProduct()
	{
		return new Product2("Product2");
	}
};
class Factory_3 :public Factory
{
public:
	Factory_3(std::string name) :Factory(name){}
	virtual Product* createProduct()
	{
		return new Product3("Product3");
	}
};
class Factory
{
public:
	Factory(std::string name) :mname(name){}
	virtual Product* createProduct() = 0;
protected:
	std::string mname;
};