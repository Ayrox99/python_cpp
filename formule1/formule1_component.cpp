#include <pybind11/pybind11.h>
using namespace std;

char version[] = "1.0";

char const* getVersion() {
	return version;
}

struct Formula1 {
	Pet(const int& speed) : speed(speed) {

	}
	void setSpeed(const int& speed_) { 
		speed = speed_; 
	}
	const string& getSpeed() const { 
		return speed; 
	}
	int speed;
};

namespace py = pybind11;

PYBIND11_MODULE(formule1_component, m) {
	py::class_<Pet>(m, "Formula 1", py::dynamic_attr())
		.def(py::init<const int&>())
		.def("setSpeed", &Pet::setSpeed)
		.def("getSpeed", &Pet::getSpeed);
}