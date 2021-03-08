#include <pybind11/pybind11.h>
using namespace std;

char version[] = "1.0";

char const* getVersion() {
	return version;
}

struct Formula1 {
	Formula1(int speed) : speed(speed) {

	}
	void setSpeed(int speed_) { 
		speed = speed_; 
	}
	const int getSpeed() const { 
		return speed; 
	}
	int speed;
};

namespace py = pybind11;

PYBIND11_MODULE(formule1_component, m) {
	py::class_<Formula1>(m, "Formula 1", py::dynamic_attr())
		.def(py::init<const int&>())
		.def("setSpeed", &Formula1::setSpeed)
		.def("getSpeed", &Formula1::getSpeed);
}