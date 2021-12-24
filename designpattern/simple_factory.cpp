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
class Factory
{
public:
	Product *CreateProduct(int flag)
	{
		switch (flag)
		{
		case 1:
			return new Product1("Product1");
			break;
		case 2:
			return new Product2("Product1");
			break;
		//case 3:
		//	return new Product3("Product3");
		//	break;
		default:
			std::cout << " flag is error !" << std::endl;
			break;
		}
	}
};