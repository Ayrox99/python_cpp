#include <pybind11/pybind11.h>
#include "micro-ecc-master/uECC.h"
using namespace std;

struct Key {

	string publicKey;
	string privateKey;

	void initialize(string number) {
		privateKey = number;
		const uint8_t* castIntPrivateKey = reinterpret_cast<const uint8_t*>(privateKey.c_str());
		const int publicKeySize = uECC_curve_public_key_size(uECC_secp256k1());
		uint8_t* varIntPublicKey = new uint8_t(publicKeySize);
		uECC_compute_public_key(castIntPrivateKey, varIntPublicKey, uECC_secp256k1());
		publicKey = string(varIntPublicKey, varIntPublicKey + publicKeySize);
	}

	string getPrivateKey() {
		return privateKey;
	}

	string getPublicKey() {
		return publicKey;
	}
	
};

namespace py = pybind11;

PYBIND11_MODULE(key_component, m) {
	py::class_<Key>(m, "Key", py::dynamic_attr())
		.def(py::init())
		.def("initialize", &Key::initialize)
		.def("getPrivateKey", &Key::getPrivateKey)
		.def("getPublicKey", &Key::getPublicKey);
}