#include <pybind11/pybind11.h>
using namespace std;

struct Key {

	string publicKey;
	string privateKey;

	void initialize(string number) {
		privateKey = number;
	}

	string getPrivateKey() {
		return privateKey;
	}

	string getPublicKey() {
		return "fromage";
	}
	
};

namespace py = pybind11;

PYBIND11_MODULE(key_component, m) {
	py::class_<Key>(m, "Key", py::dynamic_attr())
		.def(py::init<int>())
		.def("initialize", &Key::initialize)
		.def("getPrivateKey", &Key::getPrivateKey)
		.def("getPublicKey", &Key::getPublicKey);
}