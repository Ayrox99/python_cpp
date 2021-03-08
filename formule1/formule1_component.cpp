#include <pybind11/pybind11.h>
using namespace std;

struct Pet {
	Pet(const string& name) : name(name) {

	}
	void setName(const string& name_) { 
		name = name_; 
	}
	const string& getName() const { 
		return name; 
	}
	string name;
};

namespace py = pybind11;
PYBIND11_MODULE(example, m) {
	py::class_<Pet>(m, "Pet")
		.def(py::init<const string&>())
		.def("setName", &Pet::setName)
		.def("getName", &Pet::getName);
}