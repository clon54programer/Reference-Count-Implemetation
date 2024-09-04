#include <iostream>
#include "ReferenceCount.h"
#include <memory> //std::shared_ptr


class Person {
private:
	std::string name = "";
	int age = 0;
public:

	Person(std::string name, int age) : name(name),age(age){}

	std::string GetName()const { return this->name; }
	int GetAge()const { return this->age; }
};

int main() {
	ReferenceCount<int> prueba(1);

	std::cout << "Count: " << prueba.GetCount() << std::endl;
	std::cout << "Value: " << *prueba << std::endl;

	*prueba += 1;


	std::cout << "Value: " << *prueba << std::endl;

	ReferenceCount<int> ref_2 = prueba;

	std::cout << "count reference of ref_2: " << ref_2.GetCount() << std::endl;
	std::cout << "count reference of ref_1: " << prueba.GetCount() << std::endl;

	std::cout << "value of prueba: " << *prueba << std::endl;
	std::cout << "value of ref_2: " << *ref_2 << std::endl;


	prueba.Release();
	std::cout << "count reference of ref_2: " << ref_2.GetCount() << std::endl;
	// Nota: El destrcutor se llama dos veces al llegar al final del ambito.


	std::cout << '\n' << "Probando el constructor y operador de movimiento" << '\n';

	ReferenceCount<Person> genjiro({ "Genjiro",33 });
	auto juan = std::make_shared<Person>("Juan", 17);

	std::cout << "name: " << genjiro->GetName() << '\n';
	std::cout << "Age: " << genjiro->GetAge() << '\n';

	{
		std::cout << "count reference of genjiro: " << genjiro.GetCount() << std::endl;
		/// El operador de movimiento no funciona.
		auto genjiro_copy = std::move(genjiro);
		auto juan_copy = std::move(juan);

		std::cout << "count reference of genjiro_copy: " << genjiro_copy.GetCount() << std::endl;
		std::cout << "name: " << genjiro_copy->GetName() << '\n';
		std::cout << "Age: " << genjiro_copy->GetAge() << '\n' << '\n';

		// El constructor de movimiento funciona a medias, porque no deja un estado valido el otro puntero,
		// provocado que mande un error cuando se ejecuta las dos siguientes lineas.
		//std::cout << "name: " << genjiro->GetName() << '\n';
		//std::cout << "Age: " << genjiro->GetAge() << '\n';

		std::cout << "count reference of juan_copy: " << juan_copy.use_count() << std::endl;
		//std::cout << "name: " << juan->GetName() << '\n';
		//std::cout << "Age: " << juan->GetAge() << '\n' << '\n';
		// los shared_ptr de la libreria estandar, tambien falla cuando son movidos.



	}


}