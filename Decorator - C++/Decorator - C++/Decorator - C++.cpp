#include <iostream>
using namespace std;

__interface IProcessor {
	virtual void Process() = 0;
};

class Transmitter : public IProcessor {
private:
	string data;
public:
	Transmitter(string d) : data(d){}
	void Process() override {
		cout << "Data" << data << "beamed" << "\n";
	}
};

class Shell : public IProcessor {
protected:
	IProcessor* processor;
public:
	Shell(IProcessor* pr) : processor(pr){}
	void Process() override {
		processor->Process();
	}
};

class HammingCoder : public Shell {
public:
	HammingCoder(IProcessor* pr) : Shell(pr){}
	void Process() override {
		cout << "Hamming's noise-resistant code is imposed->";
		processor->Process();
	}
};

class Encryptor : public Shell {
public:
	Encryptor(IProcessor* pr) : Shell(pr){}
	void Process() override {
		cout << "Data encryption->";
		processor->Process();
	}
};

int main() {
	IProcessor* transmitter = new Transmitter("1234");
	transmitter->Process();
	cout << "\n";

	Shell* hammingCode = new HammingCoder(transmitter);
	hammingCode->Process();
	cout << "\n";

	Shell* encriptor = new Encryptor(hammingCode);
	encriptor->Process();
	cout << "\n";
}